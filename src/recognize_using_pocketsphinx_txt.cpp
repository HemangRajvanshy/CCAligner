#include "recognize_using_pocketsphinx_txt.h"

PocketsphinxAlignerTxt::PocketsphinxAlignerTxt(Params *parameters)
{
	_parameters = parameters;
	
	//creating local copies
	_audioFileName = _parameters->audioFileName;
	_transcriptFileName = _parameters->transcriptFileName;
	_outputFileName = _parameters->outputFileName;

	_modelPath = _parameters->modelPath;
	_dictPath = _parameters->dictPath;
	_lmPath = _parameters->lmPath;
	_fsgPath = _parameters->fsgPath;
	_logPath = _parameters->logPath;
	_phoneticlmPath = _parameters->phoneticlmPath;
	_phonemeLogPath = _parameters->phonemeLogPath;

	_audioWindow = _parameters->audioWindow;
	_sampleWindow = _parameters->sampleWindow;
	_searchWindow = _parameters->searchWindow;

	processFiles();
}

bool PocketsphinxAlignerTxt::processFiles()
{
	LOG("Initialising Aligner using PocketSphinx");
	LOG("Audio Filename: %s Transcript filename: %s", _audioFileName.c_str(), _transcriptFileName.c_str());


	/*std::cout << "Reading and processing subtitles...\n";
	_subParserFactory = new SubtitleParserFactory(_subtitleFileName);
	_parser = _subParserFactory->getParser();
	_subtitles = _parser->getSubtitles(); */

	std::cout << "Reading and decoding audio samples...\n";
	if (_parameters->readStream)
		_file = new WaveFileData(readStreamDirectly, _parameters->audioIsRaw);
	else
		_file = new WaveFileData(_audioFileName, _parameters->audioIsRaw);

	_file->read();
	_samples = _file->getSamples();

	return true;
}

bool PocketsphinxAlignerTxt::generateGrammar(grammarName name)
{
	LOG("Generating Grammar based on transcript, Grammar Name: %d ", name);

	std::cout << "Generating language model and grammar files...\n";

	if (_parameters->grammarType == complete_grammar || _parameters->grammarType == dict)
	{
		std::cout << "Note: You have chosen to generate a dictionary. Based on your TensorFlow configuration,\n";
		std::cout << "this may take some time, please be patient. For alternatives, see docs.\n";
	}

	return 1;// generate(_subtitles, name);
}

bool PocketsphinxAlignerTxt::initDecoder(std::string modelPath, std::string lmPath, std::string dictPath, std::string fsgPath, std::string logPath)
{
	LOG("Initialising PocketSphinx decoder");

	std::cout << "Initialising PocketSphinx decoder..\n";
	_modelPath = modelPath;
	_lmPath = lmPath;
	_dictPath = dictPath;
	_fsgPath = fsgPath;
	_logPath = logPath;

	LOG("Configuration: \n\tmodelPath = %s \n\tlmPath = %s \n\tdictPath = %s \n\tfsgPath = %s \n\tlogPath = %s ",
		_modelPath.c_str(), _lmPath.c_str(), _dictPath.c_str(), _fsgPath.c_str(), _logPath.c_str());

	if (_parameters->useBatchMode)
	{
		if (_parameters->useExperimentalParams)
		{
			_configWord = cmd_ln_init(NULL,
				ps_args(), TRUE,
				"-hmm", modelPath.c_str(),
				"-lm", lmPath.c_str(),
				"-dict", dictPath.c_str(),
				"-logfn", logPath.c_str(),
				"-cmn", "batch",
				"-lw", "1.0",
				"-beam", "1e-80",
				"-wbeam", "1e-60",
				"-pbeam", "1e-80",
				NULL);
		}

		else
		{
			_configWord = cmd_ln_init(NULL,
				ps_args(), TRUE,
				"-hmm", modelPath.c_str(),
				"-lm", lmPath.c_str(),
				"-dict", dictPath.c_str(),
				"-logfn", logPath.c_str(),
				"-cmn", "batch",
				NULL);
		}

	}

	else if (_parameters->useExperimentalParams)
	{
		_configWord = cmd_ln_init(NULL,
			ps_args(), TRUE,
			"-hmm", modelPath.c_str(),
			"-lm", lmPath.c_str(),
			"-dict", dictPath.c_str(),
			"-logfn", logPath.c_str(),
			"-lw", "1.0",
			"-beam", "1e-80",
			"-wbeam", "1e-60",
			"-pbeam", "1e-80",
			NULL);

	}

	else
	{
		_configWord = cmd_ln_init(NULL,
			ps_args(), TRUE,
			"-hmm", modelPath.c_str(),
			"-lm", lmPath.c_str(),
			"-dict", dictPath.c_str(),
			"-logfn", logPath.c_str(),
			NULL);
	}


	if (_configWord == NULL)
	{
		FATAL(EXIT_FAILURE, "Failed to create config object, see log for details");
	}

	_psWordDecoder = ps_init(_configWord);

	if (_psWordDecoder == NULL)
	{
		FATAL(EXIT_FAILURE, "Failed to create recognizer, see log for details");
	}

	if (_parameters->searchPhonemes)
	{
		initPhonemeDecoder(_parameters->phoneticlmPath, _parameters->phonemeLogPath);
	}

	return true;
}

bool PocketsphinxAlignerTxt::initPhonemeDecoder(std::string phoneticlmPath, std::string phonemeLogPath)
{
	LOG("Initialising PocketSphinx phoneme decoder");

	std::cout << "Initialising PocketSphinx phoneme decoder..\n";

	_phoneticlmPath = phoneticlmPath;
	_phonemeLogPath = phonemeLogPath;

	LOG("Configuration : \n\tphoneticlmPath = %s \n\tphonemeLogPath = %s", _phoneticlmPath.c_str(), _phonemeLogPath.c_str());

	_configPhoneme = cmd_ln_init(NULL,
		ps_args(), TRUE,
		"-hmm", _modelPath.c_str(),
		"-lm", _lmPath.c_str(),
		"-logfn", _phonemeLogPath.c_str(),
		"-allphone", _phoneticlmPath.c_str(),
		"-beam", "1e-20",
		"-pbeam", "1e-10",
		"-allphone_ci", "no",
		"-backtrace", "yes",
		"-lw", "2.0",
		NULL);

	if (_configPhoneme == NULL)
	{
		FATAL(EXIT_FAILURE, "Failed to create config object, see log for details");
	}

	_psPhonemeDecoder = ps_init(_configPhoneme);

	if (_psPhonemeDecoder == NULL)
	{
		FATAL(EXIT_FAILURE, "Failed to create phoneme recognizer, see log for details");
	}

	return true;
}

bool PocketsphinxAlignerTxt::align()
{
	if (_parameters->grammarType != no_grammar)
		generateGrammar(_parameters->grammarType);
	
	initDecoder(_parameters->modelPath, _parameters->lmPath, _parameters->dictPath, _parameters->fsgPath, _parameters->logPath);

	transcribe();

	return true;
}

int PocketsphinxAlignerTxt::findTranscribedWordTimings(cmd_ln_t *config, ps_decoder_t *ps, int index)
{
	int frame_rate = cmd_ln_int32_r(config, "-frate");
	ps_seg_t *iter = ps_seg_iter(ps);
	int printedTillIndex = index;

	while (iter != NULL)
	{
		index++;
		int32 sf, ef, pprob;
		float conf;

		ps_seg_frames(iter, &sf, &ef);
		pprob = ps_seg_prob(iter, NULL, NULL, NULL);
		conf = logmath_exp(ps_get_logmath(ps), pprob);

		std::string recognisedWord(ps_seg_word(iter));
		long startTime = sf * 1000 / frame_rate, endTime = ef * 1000 / frame_rate;

		_alignedData.addNewWord(recognisedWord, startTime, endTime, conf);

		iter = ps_seg_next(iter);
	}

	if (_parameters->outputFormat == xml)
		printTranscriptionAsXMLContinuous(_outputFileName, &_alignedData, printedTillIndex);
	else if (_parameters->outputFormat == json)
		printTranscriptionAsJSONContinuous(_outputFileName, &_alignedData, printedTillIndex);
	else if (_parameters->outputFormat == srt)
		printTranscriptionAsSRTContinuous(_outputFileName, &_alignedData, printedTillIndex);
	
	return index;
}

bool PocketsphinxAlignerTxt::transcribe()
{
	std::cout << "Transcribing...\n";

	//pointer to samples
	const int16_t *sample = _samples.data();

	//creating partition of 2048 bytes
	int numberOfPartitions = _samples.size() / 2048, remainingSamples = _samples.size() % 2048;

	//index of the word : used for sub and output handling
	int index = 0;

	bool utt_started, in_speech;

	_rvWord = ps_start_utt(_psWordDecoder);
	utt_started = FALSE;

	printTranscriptionHeader(_outputFileName, _parameters->outputFormat);

	for (int i = 0; i <= numberOfPartitions; i++)
	{
		if (i == numberOfPartitions)
			ps_process_raw(_psWordDecoder, sample, remainingSamples, FALSE, FALSE);

		else
			ps_process_raw(_psWordDecoder, sample, 2048, FALSE, FALSE);

		in_speech = ps_get_in_speech(_psWordDecoder);

		if (in_speech && !utt_started)
		{
			utt_started = TRUE;
		}

		if (!in_speech && utt_started)
		{
			ps_end_utt(_psWordDecoder);
			_hypWord = ps_get_hyp(_psWordDecoder, NULL);

			if (_hypWord != NULL)
			{
				if (_parameters->displayRecognised)
					std::cout << "Recognised: " << _hypWord << "\n";
				index = findTranscribedWordTimings(_configWord, _psWordDecoder, index);
			}

			ps_start_utt(_psWordDecoder);
			utt_started = FALSE;
		}

		sample += 2048;

	}

	_rvWord = ps_end_utt(_psWordDecoder);

	if (utt_started)
	{
		_hypWord = ps_get_hyp(_psWordDecoder, NULL);
		if (_hypWord != NULL)
		{
			if (_parameters->displayRecognised)
				std::cout << "Recognised: " << _hypWord << "\n";
			index = findTranscribedWordTimings(_configWord, _psWordDecoder, index);
		}
	}

	printTranscriptionFooter(_outputFileName, _parameters->outputFormat);

	std::cout << "Finished transcription.\n";

	return true;
}


PocketsphinxAlignerTxt::~PocketsphinxAlignerTxt()
{

	ps_free(_psWordDecoder);
	cmd_ln_free_r(_configWord);
/*
	if (_parameters->searchPhonemes)
	{
		ps_free(_psPhonemeDecoder);
		cmd_ln_free_r(_configPhoneme);
	}

	delete(_file);

	delete(_parser);
	delete(_subParserFactory); */
}
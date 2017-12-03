#ifndef CCALIGNER_RECOGNIZE_USING_POCKETSPHINX_TXT_H
#define CCALIGNER_RECOGNIZE_USING_POCKETSPHINX_TXT_H

#include "srtparser.h"
#include "read_wav_file.h"
#include "pocketsphinx.h"
#include "grammar_tools.h"
#include "generate_approx_timestamp.h"
#include "commons.h"
#include "params.h"
#include "output_handler.h"


int levenshtein_distance(const std::string& firstWord, const std::string& secondWord);

class PocketsphinxAlignerTxt
{
private:
	std::string _audioFileName, _transcriptFileName, _outputFileName;          //input and output filenames
	std::vector<int16_t> _samples;

	WaveFileData * _file;

	AlignedData _alignedData;
	Params * _parameters;

	std::string _modelPath, _lmPath, _dictPath, _logPath, _fsgPath, _phoneticlmPath, _phonemeLogPath;
	long int _audioWindow, _sampleWindow, _searchWindow;

	ps_decoder_t * _psWordDecoder, *_psPhonemeDecoder;
	cmd_ln_t * _configWord, *_configPhoneme;
	char const * _hypWord, *_hypPhoneme;
	int _rvWord, _rvPhoneme;
	int32 _scoreWord, _scorePhoneme;

	bool processFiles();
	bool printWordTimes(cmd_ln_t *config, ps_decoder_t *ps);
	int findTranscribedWordTimings(cmd_ln_t *config, ps_decoder_t *ps, int index);
	recognisedBlock findAndSetWordTimes(cmd_ln_t *config, ps_decoder_t *ps, SubtitleItem *sub);
	bool reInitDecoder(cmd_ln_t *config, ps_decoder_t *ps);
	bool initPhonemeDecoder(std::string phoneticlmPath, std::string phonemeLogPath);

public:
	PocketsphinxAlignerTxt(Params * parameters);
	bool initDecoder(std::string modelPath, std::string lmPath, std::string dictPath, std::string fsgPath, std::string logPath);
	bool generateGrammar(grammarName name);
	bool recognise();
	bool align();
	bool transcribe();
	bool printAligned(std::string outputFileName, outputFormats format);
	~PocketsphinxAlignerTxt(); 
};

#endif
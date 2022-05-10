/*---------------------------------------------------------------- 
qanthink 版权所有。
作者：
时间：2022.4.22
----------------------------------------------------------------*/

#include <iostream>
#include <unistd.h>

#include "ao.hpp"
#include "audio_player.h"
#include "mp3decoder.h"

extern "C" {
#include <libavutil/opt.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswresample/swresample.h>
}


using namespace std;

int main(int argc, const char *argv[])
{
	int volume = -25;
	const char *filePath = NULL;

	#if 0
	if(3 != argc)
	{
		cerr << "Please useage ./skyipc volume ./xxx.wav" << endl;
		cerr << "For example: /customer/skyipc -30 /customer/xiaopingguo.wav" << endl;
		cerr << "For example: /customer/skyipc 5 /mnt/linux/Audios/wav/16K_16bit_MONO_30s.wav" << endl;
		cerr << "Support by qanthink@163.com" << endl;
		return -1;
	}
	else
	{
		filePath = argv[2];
		volume = atoi(argv[1]);
	}
	#endif

	AudioOut *pAudioOut = AudioOut::getInstance();			// init Mi_AUDIO_OUT
	pAudioOut->setVolume(volume);
	AudioPlayer *pAudioPlayer = AudioPlayer::getInstance();	// init audio player.

	#if 0
	// test PCM
	//pAudioPlayer->playPCM("/mnt/linux/Audios/pcm/pcm_16000_16bit.pcm");
	pAudioPlayer->playPCM("/mnt/linux/Audios/pcm/xiaopingguo_mono_16b_16000.pcm");
	#endif

	#if 0
	// test WAV
	pAudioPlayer->playWAV("/mnt/linux/Audios/my_wav/1234567890abcde.wav");
	sleep(5);		// remove sleep() in your codes. There is just a sample.
	pAudioPlayer->playWAV("/mnt/linux/Audios/my_wav/1234567890abcde.wav");
	sleep(5);
	pAudioPlayer->playWAV("/mnt/linux/Audios/music/16K_16bit_MONO_30s.wav");
	sleep(35);

	// You can just play 3 wavs and 3 pcms. If you want to play more, please connect qanthink@163.com.
	pAudioPlayer->playWAV("/mnt/linux/Audio/my_wav/1234567890abcde.wav");
	sleep(10);
	pAudioPlayer->playWAV("/mnt/linux/Audio/my_wav/1234567890abcde.wav");
	sleep(10);
	pAudioPlayer->playWAV("/mnt/linux/Audio/my_wav/1234567890abcde.wav");
	sleep(10);
	#endif
	
	#if 0
	pAudioPlayer->playWAV(filePath);
	//sleep(5);		// remove sleep() in your codes. There is just a sample.
	#endif

	#if 1
	pAudioPlayer->playMP3("/mnt/linux/Audios/mp3/xiaopingguo.mp3");
	sleep(5);
	#endif

	#if 0
	Mp3Decoder *pMp3Decoder = Mp3Decoder::getInstance();
	//pMp3Decoder->mp3ToPcm("/mnt/linux/Audios/mp3/xiaopingguo.mp3", "/mnt/linux/Audios/pcm/test0510.pcm");
	pMp3Decoder->mp3Decoding("/mnt/linux/Audios/mp3/xiaopingguo.mp3");
	
	//pMp3Decoder->pcmFileResample("/mnt/linux/Audios/pcm/xiaopingguo_mono_16b_16000.pcm", 16000, AV_CH_LAYOUT_MONO, AV_SAMPLE_FMT_S16, \
	//			"/mnt/linux/Audios/pcm/xiaopingguo_stero_32b_44100.pcm", 44100, AV_CH_LAYOUT_STEREO, AV_SAMPLE_FMT_FLT);
	#endif

	#if 0
	unsigned char p4BytesData[4];
	Mp3Decoder *pMp3Decoder = Mp3Decoder::getInstance();
	pMp3Decoder->getMp3Frame4Bytes("/mnt/linux/Audios/mp3/xiaopingguo.mp3", p4BytesData);
	pMp3Decoder->analyzeMp3Frame("/mnt/linux/Audios/mp3/xiaopingguo.mp3", NULL, NULL, NULL);
	#endif

	while(true)
	{
		sleep(1);
		static int sleepCntSec = 0;
		if(4 == (++sleepCntSec))
		{
			return 0;
		}
	}
	
	return 0;
}


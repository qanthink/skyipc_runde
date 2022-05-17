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
	int volume = -30;
	const char *filePath = NULL;

	#if 1
	if(3 != argc)
	{
		cerr << "Please useage ./skyipc volume ./xxx.mp3" << endl;
		cerr << "For example: /customer/skyipc -30 /customer/xiaopingguo.mp3" << endl;
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

	#if 1
	//pAudioPlayer->playMP3("/mnt/linux/Audios/mp3/xiaopingguo.mp3");
	//pAudioPlayer->playMP3("/mnt/linux/Audios/mp3/bencaogangmu_f.mp3");
	//pAudioPlayer->playMP3("/mnt/linux/Audios/mp3/bencaogangmu_h.mp3");
	//pAudioPlayer->playMP3("/mnt/linux/Audios/mp3/1234567890abcde.mp3");
	pAudioPlayer->playMP3(filePath);
	#endif

	#if 1
	while(true)
	{
		sleep(1);
		static int sleepCntSec = 0;
		if(4 == (++sleepCntSec))
		//if(20 == (++sleepCntSec))
		{
			cout << "Play over. Support by qanthink@163.com" << endl;
			return 0;
		}
	}
	#endif
	
	return 0;
}


/*---------------------------------------------------------------- 
qanthink 版权所有。
作者：
时间：2022.4.22
----------------------------------------------------------------*/

#include <iostream>
#include <unistd.h>
#include "ao.hpp"
#include "audio_player.h"

using namespace std;

#if 0
int main()
{
	const char *mp3FilePath = "XiYangYang.mp3";
	const char *wavFilePath = "HuiTaiLang.wav";
	const char *pcmFilePath = "RuanMianMian.pcm";
	
	AudioPlayer *pAudioPlayer = AudioPlayer::getInstance();
	pAudioPlayer->playMP3(mp3FilePath);
	pAudioPlayer->playWAV(wavFilePath);
	pAudioPlayer->playPCM(pcmFilePath);

	system("pause");

	return 0;
}
#endif

#if 1
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

	bool bBlock = true;
	AudioPlayer audioPlayer;
	audioPlayer.playMP3(filePath, true);

	#if 1
	while(true)
	{
		sleep(2);
		static int sleepCntSec = 0;
		if(1 == (++sleepCntSec))
		//if(20 == (++sleepCntSec))
		{
			cout << "Play over. Support by qanthink@163.com" << endl;
			return 0;
		}
	}
	#endif
	
	return 0;
}
#endif

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

int main(int argc, const char *argv[])
{
	AudioOut *pAudioOut = AudioOut::getInstance();			// init Mi_AUDIO_OUT
	pAudioOut->setVolume(-30);
	AudioPlayer *pAudioPlayer = AudioPlayer::getInstance();	// init audio player.

	// test PCM
	//pAudioPlayer->playPCM("/mnt/linux/Music/pcm_16000_16bit.pcm");
	//sleep(5);

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

	while(true)
	{
		sleep(1);
		static int sleepCntSec = 0;
		if(0 == (++sleepCntSec % 10))
		{
			cout << "Progress running." << endl;
		}
		
		if(60 * 1 == sleepCntSec)		// n * 60 = n min.
		{
			break;
		}
	}
	
	return 0;
}


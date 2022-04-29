/*---------------------------------------------------------------- 
sigma star版权所有。
作者：
时间：2020.7.10
----------------------------------------------------------------*/

#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <thread>

#include "ao.hpp"
#include "audio_player.h"

using namespace std;

int main(int argc, const char *argv[])
{
	AudioPlayer *pAudioPlayer = AudioPlayer::getInstance();
	pAudioPlayer->playPCM("/mnt/linux/Music/pcm_16000_16bit.pcm");
	sleep(5);
	pAudioPlayer->playPCM("/mnt/linux/Music/pcm_16000_16bit.pcm");
	sleep(5);
	pAudioPlayer->playPCM("/mnt/linux/Music/pcm_16000_16bit.pcm");

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

	//thAi.join();
	//thVideo.join();
	//pLive555Rtsp->disable();
	
	return 0;
}


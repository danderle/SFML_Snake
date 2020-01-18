#include "Sound.h"

Sound::Sound()
{
	if (!titleBuf.loadFromFile(titleWav))
		return;
	title.setBuffer(titleBuf);

	if (!musicBuf.loadFromFile(musicWav))
		return;
	music.setBuffer(musicBuf);
	music.setLoop(true);

	if (!fartBuf.loadFromFile(fartWav))
		return;
	fart.setBuffer(fartBuf);
	
	if (!eatBuf.loadFromFile(eatWav))
		return;
	eat.setBuffer(eatBuf);
}

void Sound::PlayEat()
{
	eat.play();
}

void Sound::PlayFart()
{
	fart.play();
}

void Sound::PlayMusic()
{
	music.play();
}

void Sound::PlayTitle()
{
	title.play();
}

void Sound::StopMusic()
{
	if (music.getStatus() == sf::Sound::Status::Playing)
	{
		music.stop();
	}
}

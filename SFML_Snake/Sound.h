#pragma once
#include <SFML/Audio.hpp>

class Sound
{
public:
	Sound();

	void PlayEat();
	void PlayFart();
	void PlayMusic();
	void PlayTitle();

private:
	sf::SoundBuffer titleBuf;
	sf::SoundBuffer musicBuf;
	sf::SoundBuffer fartBuf;
	sf::SoundBuffer eatBuf;
	sf::Sound title;
	sf::Sound music;
	sf::Sound fart;
	sf::Sound eat;

	const std::string& titleWav = "Resources\\Title.wav";
	const std::string& musicWav = "Resources\\Music_Loop.wav";
	const std::string& fartWav = "Resources\\Fart.wav";
	const std::string& eatWav = "Resources\\Eat.wav";
};


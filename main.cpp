#include <iostream>
#include "Game.h"
#include<SFML/Audio.hpp>

int main()
{
    sf::SoundBuffer soundBuffer;
    if (!soundBuffer.loadFromFile("BGM\\sound.wav")) return -1;
    sf::Sound sound;
    sound.setBuffer(soundBuffer);
    sound.play();

    Game snakeGame;
	snakeGame.start();

	return 0;
}

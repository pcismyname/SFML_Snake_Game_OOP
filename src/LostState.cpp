#include "LostState.h"
#include<iostream>

LostState::LostState()
{
      this->font.loadFromFile("font/DejaVuSans.ttf");
	this->backgroundTexture.loadFromFile("pic/lost.png");


	this->score = nullptr;//Initially Pointing to Nothing

	//Initializing the Player Score Text
	this->playerScore.setPosition(sf::Vector2f(350, 200));
	this->playerScore.setFillColor(sf::Color::Black);
	this->playerScore.setFont(this->font);
	this->playerScore.setCharacterSize(80);


	//Initializing the Play Button Text
	this->playAgain = new Button(sf::Vector2f(275,400),nullptr,sf::Vector2f(300,100),
		sf::Color(200,200,200), sf::Color(140,140,140), sf::Color(100,100,100), &this->font, "Play Again",
		45,sf::Color::Black);
	this->playAgain->setTextPos(sf::Vector2f(300, 400));

	//Initializing the BackGround
	this->background.setSize(sf::Vector2f(800, 800));
	//this->background.setFillColor(sf::Color::Cyan);
	this->background.setTexture(&this->backgroundTexture);
}

LostState::~LostState()
{
 delete this->playAgain;
}

void LostState::update(double deltaT)
{
    this->updateKeyBinds(deltaT);
}

void LostState::draw(sf::RenderWindow * w)
{
   w->draw(this->background);
   w->draw(this->playerScore);
   this->playAgain->draw(w);
}

void LostState::processStuff(double deltaT, sf::Vector2f mousePos)
{
    this->playerScore.setString(std::to_string(State::getHolderScore()));
	this->playAgain->checkState(mousePos);
}

void LostState::updateKeyBinds(double deltaT)
{
	State::checkForQuit(); //Checks if the User Wants to Quit
}

bool LostState::switchState()
{
    return (this->playAgain->isPressed());
}

void LostState::setScore(std::string newScore)
{
    this->playerScore.setString(newScore);
}


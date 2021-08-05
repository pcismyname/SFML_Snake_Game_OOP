#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game() : window(sf::VideoMode(800, 800), "SnakeGame", sf::Style::Close)
{
    this->deltaT = 0; 
    this->initStates(); 
    this->score =0;


}

Game::~Game()
{
    for(int i=0;i<this->states.size();i++)
    {
        delete states.top();
        states.pop();
    }
}

void Game::start()
{
    this->run();
}

void Game::run()
{
    sf::Clock clock;

    while(this->window.isOpen())
    {
        this->deltaT = clock.restart().asSeconds();

        sf::Event event;
        while(this->window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                this->window.close();
            }
        }

        this->window.clear();

        Game::update();
        Game::processStuff();
        Game::draw();

        this->window.display();
    }
}

void Game::update()
{
    if(!this->states.empty())
    {
        this->states.top()->update(this->deltaT);
    }
}

void Game::draw()
{
    if(!this->states.empty())
    {
        this->states.top()->draw(&this->window);
    }
}

void Game::processStuff()
{

    if(!this->states.empty())
    {

        this->states.top()->processStuff(this->deltaT, sf::Vector2f(sf::Mouse::getPosition(this->window)));

        if(this->states.top()->getQuit() == true)
        {
            this->score = this->states.top()->State::getHolderScore();

            delete this->states.top();
            this->states.pop();
        }


    }
    
    //Lost State
    if(this->states.size() <= 1)
    {
        this->states.top()->State::setHolderScore(this->score);

        if(this->states.top()->switchState())
        {
            delete this->states.top();
            this->states.top() = new LostState();

            this->states.push(new GameState());
        }
    }
}

void Game::initStates()
{
    this->states.push(new LostState());
    this->states.push(new GameState());
}



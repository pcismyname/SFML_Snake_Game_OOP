#include "GameState.h"
#include <iostream>

GameState::GameState()
{
    this->headTexture.loadFromFile("pic\\head.png");
    this->fruitTexture.loadFromFile("pic\\fruit.png");

    this->head = new Head(sf::Vector2f(400, 400), &headTexture);

    srand(time(0));
    int randNum = rand() % 740 + 40;

    this->fruit = new Fruit(sf::Vector2f(randNum, randNum), &fruitTexture);

    this->initBorder();

    this->counterHF = 0;
    this->counterHT = 0;
    this->counterHB = 0;
    this->pauseCounter = 0;

    this->background.setPosition(sf::Vector2f(0, 0));
    this->background.setFillColor(sf::Color(100, 100, 100));

    this->font.loadFromFile("font\\DejaVuSans.ttf");

    this->pause = false;
    this->pauseText.setString("Pause");
    this->pauseText.setPosition(sf::Vector2f(300, 300));
    this->pauseText.setCharacterSize(60);

    this->scoreTexture.loadFromFile("pic\\blank.png");

    //set score button
    this->scoreButton = new Button(sf::Vector2f(80, 60), &this->scoreTexture, sf::Vector2f(100, 40), sf::Color::Cyan,
                                   sf::Color::Cyan, sf::Color::Cyan, &this->font, std::to_string(State::getHolderScore()), 40, sf::Color::Black);
    this->scoreButton->setTextPos(sf::Vector2f(700, 40));
}

GameState::~GameState()
{
    std::cout << "Delete Head " << std::endl;
    std::cout << "Deleting Fruit" << std::endl;
    delete this->head;
    delete this->fruit;

    for (int i = 0; i < this->borders.size(); i++)
    {
        delete borders[i];
    }

    delete this->scoreButton;
}

void GameState::update(double deltaT)
{
    this->updateKeyBinds(deltaT);

    if (this->pause == false)
    {
        this->head->update(deltaT);
        this->fruit->update(deltaT);
    }
}

void GameState::draw(sf::RenderWindow *w)
{
    this->background.setSize(sf::Vector2f(w->getSize().x, w->getSize().y));
    w->draw(this->background);

    this->head->draw(w);
    this->fruit->draw(w);

    //Drawing the border
    for (int i = 0; i < this->borders.size(); i++)
    {
        this->borders[i]->draw(w);
    }

    if (pause == true)
    {
        w->draw(this->pauseText);
    }

    this->scoreButton->draw(w);
}

void GameState::processStuff(double deltaT, sf::Vector2f mousePos)
{
    if (this->head->getCollider().checkCollision(this->fruit->getCollider()) == true)
    {
        if (counterHF >= 0.3)
        {
            std::cout << "Head And Fruit Are Colliding" << std::endl;
            this->head->growTail();
            this->fruit->setCollide(true);
            State::setHolderScore(State::getHolderScore() + 1);
            this->scoreButton->setText(std::to_string(State::getHolderScore()));
            counterHF = 0;
        }
    }

    if (this->head->headToTail() == true)
    {
        if (counterHT >= 0.3)
        {
            std::cout << "Head Touched Tail" << std::endl;
            counterHT = 0;
            State::setQuit(true);
        }
    }

    for (int i = 0; i < this->borders.size(); i++)
    {

        if (this->head->getCollider().checkCollision(this->borders[i]->getCollider()) == true)
        {
            if (counterHB >= 0.3)
            {
                std::cout << "Head is Touching the Border " << std::endl;
                counterHB = 0;
                State::setQuit(true);
            }
        }
    }

    counterHF += deltaT; 
	counterHT += deltaT; 
	counterHB += deltaT; 

}

void GameState::updateKeyBinds(double deltaT)
{
	State::checkForQuit(); 

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		if (pauseCounter >= 0.3)
		{
			if (this->pause == false)
			{
				this->pause = true;
			}
			else
			{
				this->pause = false; 
			}
			std::cout << "Pausing Screen " << this->pause<<  std::endl;
			pauseCounter = 0; 
	    }
	pauseCounter += deltaT; 
    }
}

void GameState::initBorder()
{
	this->borderTexture.loadFromFile("pic/wall.png");

	int amountNeeded = 83;//Need 76 Borders to Cover the 800x800 Window Sizes Each Border 40x40 
	/*
		20 needed
		_____ 
	18  |    | 18
		|    |
		------
		20 needed 
	*/

	//Position for the Borders
	sf::Vector2f pos(0, 0);

	int flag = 0;//Helps update the position

	for (int i = 0; i < amountNeeded; i++)
	{
		this->borders.push_back(new Border(pos, &this->borderTexture));

		if (i < 20) //Updating the Position for the Long lines 
		{
			pos.x += 40;
			pos.y = 0; 
		}
		else if (i < 60 && i >= 20) //Updating the Position for the border Lines  |     |
		{
			if (i % 2 == 0)
			{
				//i is even
				pos.x = 0;
			}
			else
			{
				//i is odd 
				pos.x = 800;
			}
			if (flag == 2)
			{
				//Update the y POSITION
				pos.y += 40;
				flag = 0; //Resetting Flag
			}
			flag++; //Updating Flag 
		}
		else if (i >= 60)//Updating the Position for the Long lines LAST ONE
		{
			if (i == 60)
			{
				pos.x = 0;//Reset the Starting Position
				pos.y = 800;
			}
			else
			{
				pos.y = 800;
				pos.x += 40;
			}
		}
	}
}


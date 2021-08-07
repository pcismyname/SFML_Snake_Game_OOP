#include "Fruit.h"

Fruit::Fruit(sf::Vector2f position, sf::Texture * texture)
	:Entity(position, texture)
{
  this->collide = false; //Initially False
   srand(time(0));
}

Fruit::~Fruit()
{
}

void Fruit::update(double deltaT)
{
    if(this->collide == true)
    {
        int randNumX = rand() % 740 +40 ;
        int randNumY = rand() % 600 + 40;

        Entity::setPos(sf::Vector2f(randNumX, randNumY));

        this->collide = false;
    }
}

void Fruit::setCollide(bool newCollide)
{
	this->collide = newCollide;
}

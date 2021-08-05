
#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <ctime>
#include <cstdlib> 

class Fruit : public Entity
{
public:
	Fruit(sf::Vector2f position, sf::Texture * texture);
	~Fruit();

	void update(double deltaT) override;

	void setCollide(bool newCollide);

private:
	bool collide; 
};


#endif

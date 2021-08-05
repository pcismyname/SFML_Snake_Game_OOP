#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include "Collider.h"

class Entity
{
public:
    Entity(sf::Vector2f position, sf::Texture * texture);
     ~Entity();

    virtual void draw(sf::RenderWindow *w); //Drawing function for Entity 
	virtual void update(double deltaT) = 0;

    //getters
	sf::Vector2f getPos();
	Collider getCollider();
	sf::RectangleShape getBody();
	sf::Vector2f getSize();

	//Setter
	void setPos(sf::Vector2f newPos);
	void setSize(sf::Vector2f newSize);

	void setFillCol(sf::Color newColor);

private:
    sf::RectangleShape body;
    Collider *c;
};

#endif // ENTITY_H

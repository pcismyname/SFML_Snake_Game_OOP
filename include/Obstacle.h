#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Entity.h"

class Obstacle : public Entity
{
public:
    Obstacle(sf::Vector2f position, sf::Texture * texture);
    ~Obstacle();

    void update(double deltaT) override;
};

#endif // OBSTACLE_H

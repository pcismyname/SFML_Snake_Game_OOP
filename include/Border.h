#ifndef BORDER_
#define BORDER_

#include "Entity.h"



class Border : public Entity
{
public:
    Border(sf::Vector2f position, sf::Texture * texture);
    ~Border();

    void update(double deltaT) override;

};

#endif // BORDER_

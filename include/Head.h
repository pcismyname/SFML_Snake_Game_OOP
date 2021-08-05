#ifndef HEAD_H
#define HEAD_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <vector>
#include "Tail.h"

enum DIRECTION{UP =0,RIGHT,DOWN,LEFT};


class Head : public Entity
{
public:
   Head(sf::Vector2f position, sf::Texture * texture);
   ~Head();
    
    void draw(sf::RenderWindow* w) override;

	void update(double deltaT) override;

    void keyboardInput();

    void growTail();

    void updateTail();

    bool headToTail();

private:
    DIRECTION dir;

    double counter;
    std::vector<Tail *>tail;
    sf::Texture tailTexture;
};

#endif // HEAD_H

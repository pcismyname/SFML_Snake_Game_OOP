#ifndef LOSTSTATE_H
#define LOSTSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Button.h"
#include <string>


class LostState : public State
{
public:
    LostState();
    ~LostState();

    void update(double deltaT) override;

    void draw(sf::RenderWindow *w) override;

    void processStuff(double deltaT, sf::Vector2f mousePos) override;

    void updateKeyBinds(double deltaT) override;

    bool switchState() override;

    void setScore(std::string newScore);



private:
    sf::Font font;
    int *score;

    sf::Text playerScore;
    Button* playAgain;

    sf::RectangleShape background;
    sf::Texture backgroundTexture;



};

#endif // LOSTSTATE_H

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
#include <string>
#include "State.h"
#include "Entity.h"
#include "Fruit.h"
#include "Head.h"
#include "Border.h"
#include <vector>
#include "Button.h"
#include <Obstacle.h>

class GameState : public State
{
 public:
    GameState();
    ~GameState();

    void update(double deltaT) override;
    void draw(sf::RenderWindow *w) override;
    void processStuff(double deltaT, sf::Vector2f mousePos) override;

    void updateKeyBinds(double deltaT) override;
    void initBorder();

private:

    Head *head;
    sf::Texture headTexture;

    Fruit * fruit;
    sf::Texture fruitTexture;

    Obstacle *obs1;
    Obstacle *obs2;
    sf::Texture obsTexture;

    std::vector<Border *> borders;
    sf::Texture borderTexture;

    double counterHF;

	double counterHT;

	double counterHB;

	double counterHO1;
    double counterHO2;


	double pauseCounter;

    sf::RectangleShape background;


	bool pause;

	sf::Text pauseText;
	sf::Font font;

	sf::Texture scoreTexture;
	Button* scoreButton;



};

#endif // GAMESTATE_H

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <stack>
#include <string>
#include "Entity.h"
#include "State.h"
#include "GameState.h"
#include "Head.h"
#include "Fruit.h"
#include "Button.h"
#include "LostState.h" 


class Game
{
    public:
        Game();
       ~Game();
       void start();

    private:
        void update();
        void draw();
        void processStuff();
        void run();
        void initStates();
    
    private:

        sf::RenderWindow window;

        std::stack<State *>states;

        double deltaT;
        int score;
    

};

#endif // GAME_H

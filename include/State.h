#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>



class State
{
public:
    State();
    ~State();

    virtual void update(double deltaT) = 0;
    virtual void draw(sf::RenderWindow * w) = 0;
    virtual void processStuff(double deltaT, sf::Vector2f mousePos) = 0;

    virtual void updateKeyBinds(double deltaT) = 0;

    virtual void checkForQuit();

    void setQuit(bool newQuit);

    bool getQuit() const;

    void setHolderScore(int newScore);

    int getHolderScore() const;

    virtual bool switchState();

    private:
        bool quit;
        int holderScore;

};

#endif // STATE_H

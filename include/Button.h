#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include "Entity.h" 
#include <string>

enum ButtonState{IDLE = 0, HOVER, PRESSED};


class Button : public Entity
{
public:
    Button(sf::Vector2f position, sf::Texture * texture, sf::Vector2f size,
		sf::Color idleColor, sf::Color hoverColor, sf::Color pressedColor,sf::Font * font,
		std::string value, int textSize, sf::Color textColor);
    ~Button();

    void update(double deltaT) override;
	void draw(sf::RenderWindow * w) override;

    void checkState(sf::Vector2f mousePos);
    bool isPressed();

    
	void setTextPos(sf::Vector2f newPos);
	void setText(std::string newText); 

	
	std::string getText() const; 

private:
    sf::Text text; 
	ButtonState state;

	sf::Color idleColor; 
	sf::Color hoverColor;
	sf::Color pressedColor;

};

#endif // BUTTON_H

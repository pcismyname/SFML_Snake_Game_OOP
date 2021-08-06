#include "Button.h"

Button::Button(sf::Vector2f position, sf::Texture * texture, sf::Vector2f size,
	sf::Color idleColor, sf::Color hoverColor, sf::Color pressedColor, sf::Font * font,
	std::string value, int textSize, sf::Color textColor)
	: Entity(position, texture)
{
    Entity::setSize(size);

    this->state = IDLE;

    //Setting Color
    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->pressedColor = pressedColor;
    
    //Setting the Buttons Text
	this->text.setFont(*font);
	this->text.setCharacterSize(textSize);
	this->text.setString(value);
	this->text.setFillColor(textColor);
	//Centering the Text in the Middle of the Button
	this->text.setPosition(Entity::getSize()); 

}

Button::~Button()
{
}

void Button::update(double deltaT)
{
}

void Button::draw(sf::RenderWindow *w)
{
    w->draw(Entity::getBody());
    w->draw(this->text);
}

void Button::checkState(sf::Vector2f mousePos)
{
    this->state = IDLE;

    if(Entity::getBody().getGlobalBounds().contains(mousePos))
    {
        this->state = HOVER;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->state = PRESSED;
        }
    }
    switch (this->state)
    {
    case IDLE:
        Entity::setFillCol(this->idleColor);
        break;
    case HOVER:
        Entity::setFillCol(this->hoverColor);
        break;
    case PRESSED:
        Entity::setFillCol(this->pressedColor);
        break;
    default:
        Entity::setFillCol(sf::Color::Red);
    }
}

bool Button::isPressed()
{
	if (this->state == PRESSED)
	{
		return true;
	}
	//Else
	return false;
}

void Button::setTextPos(sf::Vector2f newPos)
{
    this->text.setPosition(newPos);
}

void Button::setText(std::string newText)
{
    this->text.setString(newText);
}

std::string Button::getText() const
{
    return this->text.getString();
}





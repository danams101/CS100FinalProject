#include "UIButton.hpp"

//Sets text the button displays, the size of the text, the size of the button,
//the color of text, and color of button.
UIButton::UIButton(const std::string& buttonText, int textSize, sf::Vector2f buttonSize,
                    sf::Color textColor, sf::Color buttonColor){
    text.setString(buttonText);
    text.setCharacterSize(textSize);
    text.setFillColor(textColor);
    
    rect.setSize(buttonSize);
    rect.setFillColor(buttonColor);
}

void UIButton::setButtonColor(sf::Color color){
    rect.setFillColor(color);
}

void UIButton::setTextColor(sf::Color color){
    text.setFillColor(color);
}

//Sets font, must be set when called.
void UIButton::setFont(sf::Font& font){
    text.setFont(font);
}

//Sets position of button, must be set when called(instantiated). 
void UIButton::setPosition(sf::Vector2f pos){
    /*
    Sets position of the button and centers the text within the button.
    */

    rect.setPosition(pos);

    float xPos = pos.x + ((rect.getLocalBounds().width - text.getLocalBounds().width)/2);
    float yPos = pos.y + ((rect.getLocalBounds().height - text.getLocalBounds().height)/2)- (text.getLocalBounds().height/2);

    text.setPosition({xPos, yPos});
}

//Returns true if the mouse is on the button.
bool UIButton::isMouseOn(sf::RenderWindow& window){
    /*
    Gets mouse position in window, which returns a sfml int vector.
    Static casts that to float vector, which is needed for contains function.
    Uses the rect bounds to see if it contains the mouse.
    */

    sf::Vector2i mousePosInt = sf::Mouse::getPosition(window);

    sf::Vector2f mousePosFloat = static_cast<sf::Vector2f>(mousePosInt);

    if(rect.getGlobalBounds().contains(mousePosFloat)){
        return true;
    }

    return false;
}

//Changes button color if mouse is on.
void UIButton::highlightBehavior(sf::RenderWindow& window){
    /*
    If mouse on -> highlights button (Turns button white).
    */

    if(this->isMouseOn(window)){
        this->setButtonColor(sf::Color::White);
    }
    else{
        this->setButtonColor(sf::Color::Green);
    }
}

//Draws object to the window
void UIButton::drawTo(sf::RenderWindow& window) {
    window.draw(rect);
    window.draw(text);
}
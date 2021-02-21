#include "UIButton.hpp"

UIButton::UIButton(const std::string& buttonText, int textSize, sf::Vector2f buttonSize,
                sf::Color textColor, sf::Color buttonColor){
    text.setString(buttonText);
    text.setCharacterSize(textSize);
    text.setFillColor(textColor);
    
    rect.setSize(buttonSize);
    rect.setFillColor(buttonColor);
}

// UIButton::~UIButton(){

// }
void UIButton::setButtonColor(sf::Color color){
    rect.setFillColor(color);
}

void UIButton::setTextColor(sf::Color color){
    text.setFillColor(color);
}

void UIButton::setFont(sf::Font& font){
    text.setFont(font);
}

void UIButton::setPosition(sf::Vector2f pos){
    rect.setPosition(pos);

    //Center the text in the button box
    float xPos = pos.x + ((rect.getLocalBounds().width - text.getLocalBounds().width)/2);
    float yPos = pos.y + ((rect.getLocalBounds().height - text.getLocalBounds().height)/2)- (text.getLocalBounds().height/2);

    text.setPosition({xPos, yPos});
}

bool UIButton::isMouseOn(sf::RenderWindow& window){
    sf::Vector2i mousePosInt = sf::Mouse::getPosition(window);

    sf::Vector2f mousePosFloat = static_cast<sf::Vector2f>(mousePosInt);

    if(rect.getGlobalBounds().contains(mousePosFloat)){
        return true;
    }

    return false;
}

void UIButton::highlightBehavior(sf::RenderWindow& window){
    if(this->isMouseOn(window)){
        this->setButtonColor(sf::Color::White);
    }
    else{
        this->setButtonColor(sf::Color::Green);
    }
}

void UIButton::drawTo(sf::RenderWindow& window) {
    window.draw(rect);
    window.draw(text);
}
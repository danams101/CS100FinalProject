#include "UIButton.hpp"

UIButton::UIButton(sf::Vector2f size, sf::Color color, sf::Vector2f pos){
    rect.setSize(size);
    rect.setFillColor(color);
    rect.setPosition(pos);
}

// UIButton::~UIButton(){

// }

void UIButton::drawTo(sf::RenderWindow& window) {
    window.draw(rect);
}
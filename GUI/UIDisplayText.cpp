#include "UIDisplayText.hpp"

UIDisplayText::UIDisplayText(const std::string& s, int textSize, int lim, sf::Color textColor){

    charLimit = lim;
    text.setString(s);
    text.setCharacterSize(textSize);
    text.setFillColor(textColor);

    textWrappingLogic();

}

void UIDisplayText::setTextColor(sf::Color color){
    text.setFillColor(color);
}
void UIDisplayText::setFont(sf::Font& font){
    text.setFont(font);
}
void UIDisplayText::setPosition(sf::Vector2f pos){
    text.setPosition(pos);
}

void UIDisplayText::drawTo(sf::RenderWindow& window){
    window.draw(text);
}

void UIDisplayText::textWrappingLogic(){
    
    int numOfChars = text.getString().getSize();

    int numOfNewlines = numOfChars / charLimit;

    
    int insertIndex = numOfChars - charLimit;
    while(numOfNewlines > 0) {
        std::string s = text.getString();

        s.insert(insertIndex, "\n");

        text.setString(s);

        insertIndex -= charLimit;
        --numOfNewlines;
    }
}
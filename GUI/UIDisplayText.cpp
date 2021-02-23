#include "UIDisplayText.hpp"

// Sets the display text, the text size, a limint on charaters and the text color.
UIDisplayText::UIDisplayText(const std::string& s, int textSize, int lim, sf::Color textColor){
    /*
    Note: charLim is for a text wrapping algo we might implement later.
    */
    charLimit = lim;
    text.setString(s);
    text.setCharacterSize(textSize);
    text.setFillColor(textColor);

    //textWrappingLogic();

}

// Sets text color.
void UIDisplayText::setTextColor(sf::Color color){
    text.setFillColor(color);
}

// Sets font, must be set when called.
void UIDisplayText::setFont(sf::Font& font){
    text.setFont(font);
}

// Sets position, must be set when called.
void UIDisplayText::setPosition(sf::Vector2f pos){
    text.setPosition(pos);
}

// Draws object to the window.
void UIDisplayText::drawTo(sf::RenderWindow& window){
    window.draw(text);
}

// Text wrapping logic, might fix later.
/*
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
*/
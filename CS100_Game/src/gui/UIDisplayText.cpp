#include "UIDisplayText.h"

/* Constructors/Destructors */
UIDisplayText::UIDisplayText(float x, float y, std::map<std::string, sf::Color> colors,std::string text, int textSize, sf::Font* font, bool limit, int charLimit)
 : UIObject(x, y, width, height){
    /*
    Note: charLim is for a text wrapping algo we might implement later.
    */

   this->colors = colors;
   this->hasLimit = limit;
   this->charLimit = charLimit;

   this->font = font;

   this->text.setString(text);
   this->text.setCharacterSize(textSize); 
   this->text.setFont(*this->font);

    //textWrappingLogic();

}

UIDisplayText::~UIDisplayText(){

}

/* Accessors */
bool UIDisplayText::hasCharLimit(){
    return hasLimit;
}
int UIDisplayText::getCharLimit(){
    return charLimit;
}

std::string UIDisplayText::getText(){
    return this->text.getString();
}

/* Functions */

void UIDisplayText::setText(std::string text){
    this->text.setString(text);
}
void UIDisplayText::setColor(std::string colorName, sf::Color color){
    this->colors[colorName] = color;
}
void UIDisplayText::setColors(std::map<std::string, sf::Color> colors){
    this->colors = colors;
}
void UIDisplayText::setFont(sf::Font* font){
    this->font = font;
}

// Override from UIObject
void UIDisplayText::setPostition(float x, float y){
    this->bounds.setPosition(sf::Vector2f(x, y));
}

//Ticks and Render
//void updateSomthing(), nothing to update at the moment
void UIDisplayText::renderDisplayText(sf::RenderTarget* target){
    text.setFillColor(this->colors["idleColor"]);
    text.setPosition(this->x, this->y);

    target->draw(this->text);
}

//Virtual finctions from UIObject
void UIDisplayText::tick(const float& dt, sf::Window* window){
    updateBounds();
}
void UIDisplayText::render(sf::RenderTarget* target){
    renderDisplayText(target);

    //renderBounds(target);
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
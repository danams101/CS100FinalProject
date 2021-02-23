#ifndef _UIBUTTON_HPP_
#define _UIBUTTON_HPP_

#include "UIObject.hpp"

class UIButton : public UIObject {
    public:
        //Constructor
        UIButton(const std::string& buttonText, int textSize, sf::Vector2f buttonSize,
                sf::Color textColor, sf::Color buttonColor);

        //Setters
        void setButtonColor(sf::Color color);
        void setTextColor(sf::Color color);
        void setFont(sf::Font& font);
        void setPosition(sf::Vector2f pos);

        //Functions
        bool isMouseOn(sf::RenderWindow& window);
        void highlightBehavior(sf::RenderWindow& window);

        //Virtual function from UIObject class
        virtual void drawTo(sf::RenderWindow& window);

    private:
        sf::RectangleShape rect;
        sf::Text text;

};

#endif //_UIBUTTON_HPP_
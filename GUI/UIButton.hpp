#ifndef _UIBUTTON_HPP_
#define _UIBUTTON_HPP_

#include "UIObject.hpp"

class UIButton : public UIObject {
    public:
        //TODO: add variables for text size/color
        UIButton(const std::string& buttonText, int textSize, sf::Vector2f buttonSize,
                sf::Color textColor, sf::Color buttonColor);

        //virtual ~UIButton();

        void setButtonColor(sf::Color color);

        void setTextColor(sf::Color color);

        void setFont(sf::Font& font);

        void setPosition(sf::Vector2f pos);

        bool isMouseOn(sf::RenderWindow& window);

        void highlightBehavior(sf::RenderWindow& window);

        virtual void drawTo(sf::RenderWindow& window);

    private:
        sf::RectangleShape rect;
        sf::Text text;

};

#endif //_UIBUTTON_HPP_
#ifndef _UIBUTTON_HPP_
#define _UIBUTTON_HPP_

#include "UIObject.hpp"

class UIButton : public UIObject {
    public:
        //TODO: add variables for text size/color
        UIButton(sf::Vector2f size, sf::Color color, sf::Vector2f pos);

        //virtual ~UIButton();

        virtual void drawTo(sf::RenderWindow& window);


    private:
        sf::RectangleShape rect;
        //sf::Text

};

#endif //_UIBUTTON_HPP_
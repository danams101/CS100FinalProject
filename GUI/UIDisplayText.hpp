#ifndef _UIDISPLAYTEXT_HPP_
#define _UIDISPLAYTEXT_HPP_

#include "UIObject.hpp"

class UIDisplayText : public UIObject {
    public:

        UIDisplayText(const std::string& s, int textSize, sf::Vector2f boundingBoxSize, sf::Color textColor);

        void setTextColor(sf::Color color);
        void setFont(sf::Font& font);
        void setPosition(sf::Vector2f pos);

        //for testing the text bounding box
        void setBoundingBoxColor(sf::Color color);

        virtual void drawTo(sf::RenderWindow& window);

    private:
        sf::Text text;
        sf::RectangleShape boundingBox;

        //Need to add
        void textWrappingLogic();

};

#endif // _UIDISPLAYTEXT_HPP_
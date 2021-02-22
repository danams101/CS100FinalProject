#ifndef _UIDISPLAYTEXT_HPP_
#define _UIDISPLAYTEXT_HPP_

#include "UIObject.hpp"

class UIDisplayText : public UIObject {
    public:

        UIDisplayText(const std::string& s, int textSize, int lim, sf::Color textColor);

        void setTextColor(sf::Color color);
        void setFont(sf::Font& font);
        void setPosition(sf::Vector2f pos);

        virtual void drawTo(sf::RenderWindow& window);

    private:
        sf::Text text;
        int charLimit;

        //NOTE: I want to make a better text wrapping function if there is time.
        void textWrappingLogic();

};

#endif // _UIDISPLAYTEXT_HPP_
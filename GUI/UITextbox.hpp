#ifndef _UITEXTBOX_HPP_
#define _UITEXTBOX_HPP_

#include "UIObject.hpp"
#include <iostream>
#include <sstream>

class UITextbox : public UIObject {
    public:

        UITextbox();

        void setTextColor(sf::Color color);
        void setFont(sf::Font& font);
        void setPosition(sf::Vector2f pos);


    private:
        sf::Text textbox;
        std::ostringstream ss;
        bool isSelected;

        //We need an input character limit
        int limit;

        // we get input text in unicode from sfml
        int DELETE_KEY = 8;
        int TAB_KEY = 9;
        int ENTER_KEY = 13;
        void InputLogic(int charTypedVal);

        //delete the last character function
        void backspace();

};

#endif //_UITEXTBOX_HPP_
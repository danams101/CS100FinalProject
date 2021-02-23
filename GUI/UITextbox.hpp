#ifndef _UITEXTBOX_HPP_
#define _UITEXTBOX_HPP_

#include "UIObject.hpp"
#include <iostream>
#include <sstream>

class UITextbox : public UIObject {
    public:
        //Constructor
        UITextbox(int textSize, sf::Color color, bool isSelected, int charLimit);

        //Setters
        void setTextColor(sf::Color color);
        void setFont(sf::Font& font);
        void setPosition(sf::Vector2f pos);
        void setSelection(bool ToF);
        
        //Getters
        std::string getText();

        //Functions
        void typedOn(sf::Event textEntered);

        //Virtual function from UIObject class
        virtual void drawTo(sf::RenderWindow& window);


    private:
        sf::Text textbox;
        std::ostringstream ss;
        bool isSelected;

        //Input character limit
        int limit;

        // Declared special keys using unicode for special characters.
        int DELETE_KEY = 8;
        int TAB_KEY = 9;
        int ENTER_KEY = 13;

        //Private functions
        void InputLogic(int charTypedVal);
        void backspace();

};

#endif //_UITEXTBOX_HPP_
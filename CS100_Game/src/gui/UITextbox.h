#ifndef _UITEXTBOX_HPP_
#define _UITEXTBOX_HPP_

#include "UIObject.h"
#include <iostream>
#include <sstream>

class UITextbox : public UIObject {
    private:
        sf::Text textbox;

        sf::Font* font;

        std::ostringstream ss;
        bool selected;

        //Input character limit
        int limit;

        std::map<std::string,sf::Color> colors;

        // Declared special keys using unicode for special characters.
        int DELETE_KEY = 8;
        int TAB_KEY = 9;
        int ENTER_KEY = 13;

        //Private functions
        void InputLogic(int charTypedVal);
        void backspace();
        
    public:
        UITextbox(float x, float y, std::map<std::string, sf::Color> colors, int textSize = 10, sf::Font* font = nullptr, bool selected = false, int limit = 24);

        virtual ~UITextbox();

        /* Accessors */
        bool isSelected();
        int getCharLimit();
        std::string getText();

        /* Functions */
        void setSelected(bool ToF);
        void setTextColor(sf::Color color);
        void setColor(std::string colorName, sf::Color color);
        void setColors(std::map<std::string, sf::Color> colors);
        void setFont(sf::Font* font);
        
        void typedOn(sf::Event textEntered);
        
        // Override from UIObject
        void setPosition(float x, float y);
        
        // Ticks and Render
        void updateSelected(sf::Window* window);
        void renderTextbox(sf::RenderTarget* target);

        //Virtual function from UIObject class
        virtual void tick(const float& dt, sf::Window* window);
        virtual void render(sf::RenderTarget* target);



};

#endif //_UITEXTBOX_HPP_
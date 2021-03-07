#ifndef _UIDISPLAYTEXT_HPP_
#define _UIDISPLAYTEXT_HPP_

#include "UIObject.h"

class UIDisplayText : public UIObject {
    private:
        sf::Text text;
        sf::Font* font;

        bool hasLimit;
        int charLimit;

        std::map<std::string, sf::Color> colors;

        //NOTE: I want to make a better text wrapping function if there is time.
        //void textWrappingLogic();

    public:
        UIDisplayText(float x, float y, float width, float height, std::map<std::string, sf::Color> colors, std::string text, int textSize = 12, sf::Font* font = nullptr, bool limit = false, int charLimit = 0);
        virtual ~UIDisplayText();

        /* Accessors */
        bool hasCharLimit();
        int getCharLimit();

        std::string getText();

        /* Functions */

        void setText(std::string text);
        void setColor(std::string colorName, sf::Color color);
        void setColors(std::map<std::string, sf::Color> colors);
        void setFont(sf::Font* font);

        // Override from UIObject
        void setPosition(float x, float y);

        void move(float x, float y);

        //Ticks and Render
        //void updateSomthing(), nothing to update at the moment
        void renderDisplayText(sf::RenderTarget* target);

        //Virtual finctions from UIObject
        virtual void tick(const float& dt, sf::Window* window);
        virtual void render(sf::RenderTarget* target);


};

#endif // _UIDISPLAYTEXT_HPP_
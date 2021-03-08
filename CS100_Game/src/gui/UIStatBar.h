#ifndef _UISTATBAR_HPP_
#define _UISTATBAR_HPP_

#include "UIObject.h"

class UIStatBar : public UIObject {
    private:
        bool activated;
        bool done = false;
        
        float barLength;
        float timer;
        float timerDuration;

        sf::RectangleShape bar;
        sf::Clock clock;

        std::map<std::string, sf::Color> colors;

    public:
        //Constructor
        UIStatBar(float x, float y, float width, float height, std::map<std::string, sf::Color> colors, float duration, bool activated = false);

        virtual ~UIStatBar();

        /* Accessors */
        bool isActivated();
        bool isDone();

        float getTimerDuration();
        float getBarLength();
        
        /* Functions */
        void setActivation(bool activated);
        void setColor(std::string colorName, sf::Color color);
        void setColors(std::map<std::string, sf::Color> colors);

        void setStatBarColor(sf::Color color);
        void resetBar();

        // Override from UIObject
        void setPosition(float x, float y);
        void setSize(float width, float height);

        // Ticks and render
        void updateProgress(const float& dt);
        void renderStatBar(sf::RenderTarget* target);

        // Virtual function from UIObject class
        virtual void tick(const float& dt, sf::Window* window);
        virtual void render(sf::RenderTarget* target);

};

#endif //_UISTATBAR_HPP_

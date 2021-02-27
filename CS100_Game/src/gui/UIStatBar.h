#ifndef _UISTATBAR_HPP_
#define _UISTATBAR_HPP_

#include "UIObject.h"

class UIStatBar : public UIObject {
    private:
        bool activated;
        
        float barLength;
        float timer;
        float timerDuration;

        sf::RectangleShape bar;
        sf::Clock clock;

        std::map<std::string, sf::Color> colors;

        // A private function for now because it is called in the drawTo function.
        // Can be moved to public later, to have updateProgress control outside class.
        // For now its just a timer/progress bar.
    public:
        //Constructor
        UIStatBar(float x, float y, float width, float height, std::map<std::string, sf::Color> colors, float duration, bool activated = false);

        virtual ~UIStatBar();

        /* Accessors */
        bool isActivated();
        float getTimerDuration();
        float getBarLength();
        // Function to return progress, might need it later.
        float getProgress();
        
        /* Functions */
        void setActivation(bool activated);
        void setColor(std::string colorName, sf::Color color);
        void setColors(std::map<std::string, sf::Color> colors);

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

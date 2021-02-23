#ifndef _UISTATBAR_HPP_
#define _UISTATBAR_HPP_

#include "UIObject.hpp"

class UIStatBar : public UIObject {
    public:
        //Constructor
        UIStatBar(sf::Vector2f barSize, bool active, float duration);

        //Setter functions
        void setColor(sf::Color color);
        void setPosition(sf::Vector2f pos);
        void setActivation(bool active);

        // Function to return progress, might need it later.
        float getProgress();

        //Virtual function from UIObject class
        virtual void drawTo(sf::RenderWindow& window);

    private:
        sf::RectangleShape bar;
        sf::Clock clock;

        float barLength;
        float timer;
        float timerDuration;

        bool isActivated;
        
        // A private function for now because it is called in the drawTo function.
        // Can be moved to public later, to have updateProgress control outside class.
        // For now its just a timer/progress bar.
        void updateProgress();
};

#endif //_UISTATBAR_HPP_
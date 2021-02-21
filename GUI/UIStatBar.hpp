#ifndef _UISTATBAR_HPP_
#define _UISTATBAR_HPP_

#include "UIObject.hpp"

class UIStatBar : public UIObject {
    public:
        // might add initialization for dt and timer later
        UIStatBar(sf::Vector2f barSize, bool active, bool isTimer);

        void setColor(sf::Color color);
        void setPosition(sf::Vector2f pos);

        void updateProgress();
        float getProgress();

        virtual void drawTo(sf::RenderWindow& window);

    private:
        sf::RectangleShape bar;

        bool isActivated;
        bool isTimer;

        //still need to figure out dt timer stuff
        //float dt;
        //float timer;

};

#endif //_UISTATBAR_HPP_
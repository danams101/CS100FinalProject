#ifndef _UIBUTTONTIMER_H_
#define _UIBUTTONTIMER_H_

#include "UIButton.h"
#include "UIStatBar.h"

class UIButtonTimer : public UIButton {
    private:
        UIStatBar* status;
        bool clickable = true;

    public:
        /* Button with added statBar functionality */
        UIButtonTimer(float x, float y, float width, float height, std::map<std::string, sf::Color> colors, float thickness = 0,
		std::string text = "", int textSize = 0, sf::Font* font = nullptr, bool centered = false, float duration = 5.f, bool activated = false);

        ~UIButtonTimer();

        /* UIButtonTimer Accessors */
        bool isTimerDone();
        bool isClickable();

        bool getTimerActivation();

        /* UIButtonTimer Functions */
        void setTimerActivation(bool ToF);


        // Updates and Ticks
        void updateState(sf::Window* window);
        //void updateTimerState();

        void renderButton(sf::RenderTarget* target);
        void renderStatbar(sf::RenderTarget* target);

        void tick(const float&dt, sf::Window* window);
        void render(sf::RenderTarget* target);

};

#endif
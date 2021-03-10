#ifndef _UIBUTTON_H_
#define _UIBUTTON_H_

#include "UIObject.h"

enum states{IDLE = 0, HOVER, ACTIVE};

class UIButton : public UIObject {
	protected:
		bool centered;
		bool clicked;
		int state;

		float thickness;

        sf::Text text;
		sf::Font* font;

		// colors
		std::map<std::string, sf::Color> colors;

		// sf::Color idleColor;
		// sf::Color hoverColor;
		// sf::Color activeColor;

		// sf::Color accentIdleColor;
		// sf::Color accentHoverColor;
		// sf::Color accentActiveColor;

		// sf::Color textIdleColor;
		// sf::Color textHoverColor;
		// sf::Color textActiveColor;

    public:
		UIButton(float x, float y, float width, float height, std::map<std::string, sf::Color> colors, float thickness = 0,
		std::string text = "", int textSize = 0, sf::Font* font = nullptr, bool centered = false);
		virtual ~UIButton();

		/* Accessors */
        bool isCentered();
		bool isHovered();
		bool isActive();
		bool isClicked();

		std::string getText();

		/* Functions */
		void setState(std::string state);
		void setText(std::string text);
		void setThickness(float thickness);
        void setColor(std::string colorName, sf::Color color);
		void setColors(std::map<std::string, sf::Color> colors);
        void setFont(sf::Font* font);

		// Overrided from UIObject
		void setPosition(float x, float y);

        // Ticks and render
		void updateState(sf::Window* window);
		void renderButton(sf::RenderTarget* target);
		void renderText(sf::RenderTarget* target);

        // Virtual function from UIObject class
		virtual void tick(const float& dt, sf::Window* window);
        virtual void render(sf::RenderTarget* target);
};

#endif //_UIBUTTON_H_

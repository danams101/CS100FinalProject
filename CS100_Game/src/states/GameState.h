#ifndef GAMESTATE_H
#define GAMSTATE_H

#include "State.h"

class GameState : public State {
    private:

        //Resources needed
        const std::string keybindFile = "../res/config/keybinds_gamestate.ini";
        const std::string defaultFontFile = "../res/fonts/UbuntuMono-R.ttf";

		//Variables
		std::map<std::string, sf::Font> fonts;

        //Might need more than one to account for panels
		UIList uiList;
		std::map<std::string, UIButton*> buttons;
        std::map<std::string, UIDisplayText*> texts;
		
		std::map<std::string, sf::Color> defaultTheme;
		std::map<std::string, sf::Color> debugTheme;

        bool showGame = false;
        bool asleep = true;

        /* Initializer Functions */
        void initVariables();
        void initFonts();
        void initColors();
        void initKeybinds();
        void initUI();

        void renderBackground(sf::RenderTarget* target = nullptr);

    public:
        GameState(GlobalData* global_data);
        virtual ~GameState();

        /* Functions */
        void resetUI();

        //Ticks and render
        void updateButtons();
        void updateKeyInput();//prob where can fix testbox
        void tick(const float& dt);
        void render(sf::RenderTarget* target = nullptr);

};

#endif
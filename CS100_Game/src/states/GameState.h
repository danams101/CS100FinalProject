#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include <list>

#include "../gui/guiText.hpp"
#include "../inventory/inventory.hpp"
#include "../inventory/campStatus.hpp"
//#include "ForestState.h"

//class ForestState;

class GameState : public State {
    protected:

        //Resources needed
        const std::string keybindFile = "res/config/keybinds_gamestate.ini";
        const std::string defaultFontFile = "res/fonts/UbuntuMono-R.ttf";
        const std::string updateTextFile = "res/config/updateTexts.ini";

		//Variables
		std::map<std::string, sf::Font> fonts;

        // 0 = out, 1 = flickering, 2 = roaring
        int fireState = 0;
        Inventory inventory;
        CampStatus camp;


        //Might need more than one to account for panels
		UIList uiList;

		std::map<std::string, UIButton*> buttons;
        std::map<std::string, UIButtonTimer*> timers;

        std::map<std::string, UIDisplayText*> inventoryMap;

        //Possible texts to display, will initialize from a text file
        std::map<std::string, std::string> texts;

        std::list<uiText*> uiTexts;

		std::map<std::string, sf::Color> defaultTheme;
		std::map<std::string, sf::Color> debugTheme;
        std::map<std::string, sf::Color> tabButtonTheme;

        bool showGame = false;
        bool asleep = true;

        /* Initializer Functions */
        void initVariables();
        void initFonts();
        void initColors();
        void initKeybinds();

        void initTexts();

        void initUI();


    public:
        GameState(GlobalData* global_data);
        virtual ~GameState();

        /* Functions */
        void resetUI();

        void configureTextList(std::list<uiText*>& list);



        //Ticks and render
        void renderBackground(sf::RenderTarget* target = nullptr);
        void renderUpdateTexts(sf::RenderTarget* target = nullptr);

        void updateButtons();
        void updateInventory();
        void updateKeyInput();//prob where can fix testbox
        void tick(const float& dt);
        void render(sf::RenderTarget* target = nullptr);

};

#endif

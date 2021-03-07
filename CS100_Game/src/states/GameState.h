#ifndef GAMESTATE_H
#define GAMSTATE_H

#include "State.h"
#include <list>

#include "../uiText.hpp"

class GameState : public State {
    private:

        //Resources needed
        const std::string keybindFile = "../res/config/keybinds_gamestate.ini";
        const std::string defaultFontFile = "../res/fonts/UbuntuMono-R.ttf";

		//Variables
		std::map<std::string, sf::Font> fonts;

        //Might need more than one to account for panels
		UIList uiList;

        /* list for text objects
                everytime a text object is added(pushfront), the previous gets shifted down
                once the last reaches a certain point its popped
                what gets sent to the list depends on what button is pressed
                we could have a randomized function
                what gets printed could be initialized to a map from a text file
                Ex: button pushed-> textlist.pushfront(textMap["button"])*/

		std::map<std::string, UIButton*> buttons;
        std::map<std::string, UIStatBar*> statBars;
        std::map<std::string, UIDisplayText*> displayTexts; //DONT KNOW IF WANT TO KEEP

        //Possible texts to display, will initialize from a text file
        std::map<std::string, sf::Text> texts;

        //std::list<UIDisplayText*> scrolledText;

        //UIList* textList;

        //UIDisplayText* disT;

        std::list<uiText*> uiTexts;
		
		std::map<std::string, sf::Color> defaultTheme;
		std::map<std::string, sf::Color> debugTheme;

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



        //Ticks and render
        void renderBackground(sf::RenderTarget* target = nullptr);
        void renderUpdateTexts(sf::RenderTarget* target = nullptr);

        void updateButtons();
        void updateKeyInput();//prob where can fix testbox
        void tick(const float& dt);
        void render(sf::RenderTarget* target = nullptr);

};

#endif
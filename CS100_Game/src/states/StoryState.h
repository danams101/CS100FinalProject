#ifndef STORYSTATE_H
#define STORYSTATE_H

#include "State.h"
#include "GameState.h"

class StoryState : public State{
    private:
        //Resources needed
		const std::string keybindFile = "../res/config/keybinds_gamestate.ini";
		const std::string defaultFontFile = "../res/fonts/UbuntuMono-R.ttf";

		//Variables
		std::map<std::string, sf::Font> fonts;
		UIList uiList;
		std::map<std::string, UIButton*> buttons;

		std::map<std::string, sf::Color> defaultTheme;
		std::map<std::string, sf::Color> debugTheme;

		/* Initializer Functions */
		void initVariables();
		void initFonts();
		void initColors();
		void initKeybinds();

        void initDialogues();

		void initUI();
    public:
        StoryState(GlobalData* global_data);
        virtual ~StoryState();

        void resetUI(); //can be used to clear screen for next dialogue
        //or can have a function in object that checks if should be shown
        //or make a proper delete object function that doesnt leak memory :/


        void updateButtons();

        void updateKeyInput();//where textbox lays

        void tick(const float& dt);
        void render(sf::RenderTarget* target = nullptr);
};



#endif
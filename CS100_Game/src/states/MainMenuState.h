#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

// #include "GameState.h"
// #include "SettingsState.h"

#include "State.h"

class MainMenuState : public State {
	private:

		//Resources needed
		const std::string keybindFile = "res/config/keybinds_mainmenustate.ini";
		const std::string defaultFontFile = "res/fonts/UbuntuMono-R.ttf";

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
		void initUI();

	public:
		MainMenuState(GlobalData* global_data);
		virtual ~MainMenuState();

		/* Functions */
		void resetUI();
		
		// Tick and render
		void updateButtons();
		void updateKeyInput();
		void tick(const float& dt);
		void render(sf::RenderTarget* target = NULL);
};

#endif

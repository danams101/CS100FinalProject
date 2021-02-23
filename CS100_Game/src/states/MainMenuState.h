#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

// #include "GameState.h"
// #include "SettingsState.h"

#include "State.h"

class MainMenuState : public State {
	private:

		//Resources needed
		const std::string keybindFile = "res/config/keybinds_mainmenustate.ini";

		//Variables
		sf::Font font;

		//Functions
		void initVariables();
		void initFonts();
		void initKeybinds();

	public:
		MainMenuState(GlobalData* global_data);
		virtual ~MainMenuState();

		//Functions
		void updateInput(const float& dt);
		void update(const float& dt);
		void render(sf::RenderTarget* target = NULL);
};

#endif

#include "../stdafx.h"
#include "MainMenuState.h"

//Initializer functions

//Initialize variables
void MainMenuState::initVariables() {
    /* No mainmenustate private variables to initialize */
}

//Initialize fonts
void MainMenuState::initFonts() {
    /* Implementation to load in fonts */

	// if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	// {
		// throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	// }
}

// Initialize keybind
void MainMenuState::initKeybinds() {

	// std::ifstream ifs(keybindFile);

	// if (ifs.is_open())
	// {
		// std::string key = "";
		// std::string key2 = "";

		// while (ifs >> key >> key2)
		// {
			// this->keybinds[key] = this->supportedKeys->at(key2);
		// }
	// }

	// ifs.close();
}

//Constructors/Destructors
MainMenuState::MainMenuState(GlobalData* global_data) : State(global_data) {
	this->initVariables();
	this->initFonts();
	this->initKeybinds();
}

MainMenuState::~MainMenuState() {

}

// Update input using dt
void MainMenuState::updateInput(const float &dt) {
    /* To do */

}

// Main update function
void MainMenuState::update(const float& dt) {
    /* Will have to link all the other update functions here */

	std::cout << "Main menu state is working!\n";
	this->updateInput(dt);
}

// Main render function
void MainMenuState::render(sf::RenderTarget* target) {
    /* Will have to link all the other render functions here */

	if (!target)
		target = this->globalData->window;

}

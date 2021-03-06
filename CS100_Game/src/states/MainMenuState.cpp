#include "../stdafx.h"
#include "MainMenuState.h"

/* Initializer Functions */

// Initialize variables
void MainMenuState::initVariables() {
    /* No mainmenustate private variables to initialize */
}

// Initialize fonts
void MainMenuState::initFonts() {
    /* Implementation to load in fonts
	In the future, should be able to load multiple fonts
	Using a gfx loader class from a .ini file*/

	sf::Font font;

	if (!font.loadFromFile(this->defaultFontFile))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
		return;
	}
	this->fonts["default"] = font;
}

// Initialize colors
void MainMenuState::initColors() {
	/* Implementation to load in colors
	In the future, should be able to load multiple themes
	Using a gfx loader class from a .ini file */
	
	// Set default theme colors
	this->debugTheme["idleColor"] = sf::Color::White;
	this->debugTheme["hoverColor"] = sf::Color::Yellow;
	this->debugTheme["activeColor"] = sf::Color::Green;
	this->debugTheme["accentIdleColor"] = sf::Color::Blue;
	this->debugTheme["accentHoverColor"] = sf::Color::Red;
	this->debugTheme["accentActiveColor"] = sf::Color::Cyan;
	this->debugTheme["textIdleColor"] = sf::Color::Blue;
	this->debugTheme["textHoverColor"] = sf::Color::Red;
	this->debugTheme["textActiveColor"] = sf::Color::Cyan;

	this->defaultTheme["idleColor"] = sf::Color(52,58,64);
	this->defaultTheme["hoverColor"] = sf::Color(206,212,218);
	this->defaultTheme["activeColor"] = sf::Color(248,249,250);
	this->defaultTheme["accentIdleColor"] = sf::Color(33,37,41);
	this->defaultTheme["accentHoverColor"] = sf::Color(233,236,239);
	this->defaultTheme["accentActiveColor"] = sf::Color(206,212,218);
	this->defaultTheme["textIdleColor"] = sf::Color(222,226,230);
	this->defaultTheme["textHoverColor"] = sf::Color(130,130,130);
	this->defaultTheme["textActiveColor"] = sf::Color(173,181,189);

}

// Initialize keybind
void MainMenuState::initKeybinds() {

	std::ifstream ifs(keybindFile);

	//DEBUG
	if(!ifs.is_open()){
		std::cout << "Keybinds not opened!" << "\n";
	}

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->globalData->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

// Initialize UI
void MainMenuState::initUI() {
	/* Making the UI for main menu */

	// This is important for getting the proper pixels depending on resolution
	GraphicsConverter gfx = GraphicsConverter(this->globalData->gfxSettings->resolution);

	// Background

	// Title

	/* Buttons */

	// Play Game
	UIButton* playGame = new UIButton(gfx.getX(35), gfx.getY(10), gfx.getX(30), gfx.getY(20), this->defaultTheme, gfx.getY(1),
	"Play", gfx.getCharSize(40), &this->fonts["default"], true); //changed theme to test
	UIObject* playGameObj = playGame;
	this->uiList.add(playGameObj);
	this->buttons["Play_Game"] = playGame;

	// Settings Menu
	UIButton* settingsMenu = new UIButton(gfx.getX(35), gfx.getY(40), gfx.getX(30), gfx.getY(20), this->defaultTheme, gfx.getY(1),
	"Settings", gfx.getCharSize(40), &this->fonts["default"], true);
	UIObject* settingsMenuObj = settingsMenu;
	this->uiList.add(settingsMenuObj);
	this->buttons["Settings_Menu"] = settingsMenu;

	// Quit Game
	UIButton* quitGame = new UIButton(gfx.getX(35), gfx.getY(70), gfx.getX(30), gfx.getY(20), this->defaultTheme, gfx.getY(1),
	"Quit", gfx.getCharSize(40), &this->fonts["default"], true);
	UIObject* quitGameObj = quitGame;
	this->uiList.add(quitGameObj);
	this->buttons["Quit_Game"] = quitGame;

}

/* Constructors/Destructors */
MainMenuState::MainMenuState(GlobalData* global_data) : State(global_data) {
	this->initVariables();
	this->initFonts();
	this->initColors();
	this->initKeybinds();
	this->initUI();
}

MainMenuState::~MainMenuState() {

}

/* Functions */
void MainMenuState::resetUI() {
}

// Tick and render

// Runs through all the button's functionality
void MainMenuState::updateButtons() {
	/* Handles all of the button's functionality */

	// New Game
	if(this->buttons["Play_Game"]->isClicked()) {
		std::cout << "CLICKED!!!!!" << std::endl;
		//this->states->push(new GameState(this->stateData));
		this->globalData->states->push(new GameState(this->globalData));
	}

	// Setting Menu
	if(this->buttons["Settings_Menu"]->isClicked()) {

	}

	// Quit Game
	if(this->buttons["Quit_Game"]->isClicked()) {
		this->endState();
	}

}

// Update key input
void MainMenuState::updateKeyInput() {
    /* This checks to see if the keyboard has inputted a choice
	Note: This section should only handle inputs that are accepted to only
	receive 1 input at a time */


	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeyDelay()) {
		std::cout << "KEY PRESSED" << std::endl;
	}
}

// Main tick function
void MainMenuState::tick(const float& dt) {
    /* Will have to link all the other update functions here */

	this->uiList.tick(dt, this->globalData->window);

	this->updateKeyTime(dt);
	this->updateKeyInput();
	this->updateButtons();
}

// Main render function
void MainMenuState::render(sf::RenderTarget* target) {
    /* Will have to link all the other render functions here */

	if (!target)
		target = this->globalData->window;

	this->uiList.render(target);
	this->renderMousePos();
}

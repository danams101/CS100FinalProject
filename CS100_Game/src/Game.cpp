#include "stdafx.h"
#include "Game.h"

// Initialization Functions

// Initialize variables
void Game::initVariables() {
	/* Any private variables that need to be set up */

	this->window = NULL;
	this->dt = 0.f;
}

//Load in gfxSettings
void Game::initGraphicsSettings() {
	/* Load in graphics settings */

	this->gfxSettings.loadFromFile(this->gfxFile);
}

//Initialize window settings
void Game::initWindow() {
	/*Creates a SFML window. */

	if(this->gfxSettings.fullscreen) {
		this->window = new sf::RenderWindow(
			this->gfxSettings.resolution,
			this->gfxSettings.title,
			sf::Style::Fullscreen,
			this->gfxSettings.contextSettings);
	}
	else {
		this->window = new sf::RenderWindow(
			this->gfxSettings.resolution,
			this->gfxSettings.title,
			sf::Style::Titlebar | sf::Style::Close,
			this->gfxSettings.contextSettings);
	}

	this->window->setFramerateLimit(this->gfxSettings.frameRateLimit);
	this->window->setVerticalSyncEnabled(this->gfxSettings.verticalSync);
}

// To do later
void Game::initKeys() {
	/* To do later */

	// std::ifstream ifs("Config/supported_keys.ini");

	// if (ifs.is_open())
	// {
		// std::string key = "";
		// int key_value = 0;

		// while (ifs >> key >> key_value)
		// {
			// this->supportedKeys[key] = key_value;
		// }
	// }

	// ifs.close();

	// DEBUG REMOVE LATER!
	// for (auto i : this->supportedKeys)
	// {
		// std::cout << i.first << " " << i.second << "\n";
	// }
}

void Game::initGlobalData() {
	/* To do later */

	this->globalData.window = this->window;
	this->globalData.gfxSettings = &this->gfxSettings;
	// this->globalData.supportedKeys = &this->supportedKeys;
	this->globalData.states = &this->states;
}

// Load in MainMenuState
void Game::initStates() {
	/* Adding in the MainMenuState by passing in globalData */

	this->states.push(new MainMenuState(&this->globalData));
}

// Constructors/Destructors
Game::Game() {

	this->initVariables();
	this->initGraphicsSettings();
	this->initWindow();
	this->initKeys();
	this->initGlobalData();
	this->initStates();
}

Game::~Game() {
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

// Functions

// End application
void Game::endApplication() {
	/* Prints ending message to console */

	std::cout << "Ending Application!" << "\n";
}

// Update delta time
void Game::updateDt() {
	/*Updates the dt variable with the time it takes to update and render one frame.*/

	this->dt = this->dtClock.restart().asSeconds();
}

// Update SFML Events
void Game::updateSFMLEvents() {
    /* Needs to be added properly */

	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

// Main update function
void Game::update() {
	/* Will update SFML Events and top most state.
	If no states, will end application */

	this->updateSFMLEvents();

	if (!this->states.empty())
	{
		if (this->window->hasFocus())
		{
			this->states.top()->update(this->dt);

			if (this->states.top()->getQuit())
			{
				this->states.top()->endState();
				delete this->states.top();
				this->states.pop();
			}
		}
	}
	// Application end
	else
	{
		this->endApplication();
		this->window->close();
	}
}

// Main render function
void Game::render() {
	/* Clear window, and
	then call the top most state's render function */

	this->window->clear();

	//Render items
	if (!this->states.empty())
		this->states.top()->render();

	this->window->display();
}

// Main run function
void Game::run() {
	/* Main run function
		This will repeatedly call the update and render functions */

	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}

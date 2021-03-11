#ifndef GAME_H
#define GAME_H

#include "states/MainMenuState.h"

class Game {
	private:

		// Resources needed
		const std::string gfxFile = "res/config/graphics.ini";//Note: added correct file navigation
		const std::string supportedKeysFile = "res/config/supported_keys.ini";

		/* Variables */
		GraphicsSettings gfxSettings;
		GlobalData globalData;
		sf::RenderWindow *window;
		sf::Event sfEvent;

		sf::Clock dtClock;
		float dt;

		std::stack<State*> states;

		std::map<std::string, int> supportedKeys;

		/* Initializer Functions */
		void initVariables();
		void initGraphicsSettings();
		void initWindow();
		void initKeys();
		void initGlobalData();
		void initStates();

	public:

		/* Constructors/Destructors */
		Game();
		virtual ~Game();

		/* Functions */
		void endApplication();

		// Tick
		void updateDt();
		void updateSFMLEvents();
		void tick();

		// Render
		void render();

		// Core
		void run();
};

#endif // GAME_H

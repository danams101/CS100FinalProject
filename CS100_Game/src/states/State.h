#ifndef STATE_H
#define STATE_H

#include "../gfx/GraphicsSettings.h"
#include "../gfx/GraphicsConverter.h"
#include "../gui/UIList.h"
#include "../gui/UIButton.h"

#include "../gui/UIStatBar.h"
#include "../gui/UIDisplayText.h"

class GraphicsSettings;
class State;

class GlobalData {
	public:
		GlobalData() {};

		/* Global variables */
		sf::RenderWindow* window;
		GraphicsSettings* gfxSettings;
		std::map<std::string, int>* supportedKeys;
		std::stack<State*>* states;
};

class State {
	private:

	protected:

		/* Variables */

		// Global data to manipulate Game.h
		GlobalData* globalData;

		// State data
		bool quit;
		bool paused;
		std::map<std::string, int> keybinds;

		float keytime;
		// in seconds
		float keytimeMax = 0.3f;

		// Resources
		// std::map<std::string, sf::Texture> textures;

		// Functions
		// virtual void initKeybinds() = 0;

	public:
		State(GlobalData* global_data);
		virtual ~State();

		/* Accessors */
		const bool& getQuit() const;
		bool getKeyDelay();

		/* Functions */
		void endState();
		void pauseState();
		void unpauseState();

		// Ticks and Render
		void updateKeyTime(const float& dt);
		void renderMousePos();

		// Virtual functions
		virtual void updateKeyInput() = 0;
		virtual void tick(const float& dt) = 0;
		virtual void render(sf::RenderTarget* target = NULL) = 0;
};

#endif // STATE_H

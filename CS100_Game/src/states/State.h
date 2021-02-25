#ifndef STATE_H
#define STATE_H

#include "../gfx/GraphicsSettings.h"

class GraphicsSettings;
class State;

class GlobalData {
public:
	GlobalData() {};

	// Global variables
	sf::RenderWindow* window;
	GraphicsSettings* gfxSettings;
	// std::map<std::string, int>* supportedKeys;
	std::stack<State*>* states;
};

class State {
	private:

	protected:

		// Global data to manipulate Game.h
		GlobalData* globalData;

		// State data
		bool quit;
		bool paused;
		std::map<std::string, int> keybinds;

		// Resources
		// std::map<std::string, sf::Texture> textures;

		// Functions
		// virtual void initKeybinds() = 0;

	public:
		State(GlobalData* global_data);
		virtual ~State();

		// Accessors
		const bool& getQuit() const;

		// Functions
		void endState();
		void pauseState();
		void unpauseState();

		virtual void updateInput(const float& dt) = 0;
		virtual void update(const float& dt) = 0;
		virtual void render(sf::RenderTarget* target = NULL) = 0;
};

#endif // STATE_H

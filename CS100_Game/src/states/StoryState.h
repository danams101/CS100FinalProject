#ifndef STORYSTATE_H
#define STORYSTATE_H

#include "State.h"
#include "GameState.h"

/*
Can have derived story state classes that have different dialogue phases and
initialize different dialogues and buttons

the derived state will have to implement 
initDialogues 
initButtonLists

initUI //i think

updateButtons
*/

class StoryState : public State{
    private:
		int state;
		float timer = 0;
		float displayDelay = 0;

		sf::RectangleShape grad;

		UIButtonList phase1_0;
		UIButtonList phase1_1;
		UIButtonList phase2_0;

		UIButtonList listToRender;

		std::map<std::string, std::string> brianBlitz;

		std::list<uiText*> textList;

		//sf::Clock clock;
		float currentTime;

	protected:
        //Resources needed
		const std::string keybindFile = "../res/config/keybinds_gamestate.ini";
		const std::string defaultFontFile = "../res/fonts/UbuntuMono-R.ttf";

		const std::string brianBlitzFile = "../res/config/BrianBlitzDia.ini";

		//Variables
		std::map<std::string, sf::Font> fonts;
		
		std::map<std::string, sf::Color> defaultTheme;
		std::map<std::string, sf::Color> debugTheme;
		
		//UIList uiList;
		
		//std::map<std::string, UIButton*> buttons;


		/* Initializer Functions */
		void initVariables();
		void initFonts();
		void initColors();
		void initKeybinds();

        void initDialogues();

		//void initButtonLists();

		void initUI();
    public:
        StoryState(GlobalData* global_data);
        virtual ~StoryState();

        void resetUI(); //can be used to clear screen for next dialogue
        //or can have a function in object that checks if should be shown
        //or make a proper delete object function that doesnt leak memory :/

		void configureDialogues(std::list<uiText*>& list);

		void updateCurrentTime(const float& dt);

        void updateButtons();

        void updateKeyInput();//where textbox lays

		void updateGradient(const float& dt);

		void renderDialogues(sf::RenderTarget* target);

		void renderGradient(sf::RenderTarget* target);

        void tick(const float& dt);
        void render(sf::RenderTarget* target = nullptr);
};



#endif
#include "../stdafx.h"
#include "GameState.h"

/* Initializer Functions */

void GameState::initVariables(){
    // inventory, health and stuff
}
void GameState::initFonts(){
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
void GameState::initColors(){
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
	this->debugTheme["normalTextColor"] = sf::Color::White;

	this->defaultTheme["idleColor"] = sf::Color(52,58,64);
	this->defaultTheme["hoverColor"] = sf::Color(206,212,218);
	this->defaultTheme["activeColor"] = sf::Color(248,249,250);
	this->defaultTheme["accentIdleColor"] = sf::Color(33,37,41);
	this->defaultTheme["accentHoverColor"] = sf::Color(233,236,239);
	this->defaultTheme["accentActiveColor"] = sf::Color(206,212,218);
	this->defaultTheme["textIdleColor"] = sf::Color(222,226,230);
	this->defaultTheme["textHoverColor"] = sf::Color(130,130,130);
	this->defaultTheme["textActiveColor"] = sf::Color(173,181,189);
	this->defaultTheme["normalTextColor"] = sf::Color(32,37,41);
	this->defaultTheme["backgroundColor"] = sf::Color(173,181,189);
}

// Initialize keybinds
void GameState::initKeybinds(){
    std::ifstream ifs(keybindFile);//NEED TO MAKE
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
void GameState::initUI(){
	GraphicsConverter gfx = GraphicsConverter(this->globalData->gfxSettings->resolution);

	UIButton* wakeUp = new UIButton(gfx.getX(35), gfx.getY(10), gfx.getX(30), gfx.getY(20), this->defaultTheme, gfx.getY(1),
	"Wake up", gfx.getCharSize(40), &this->fonts["default"], true); //changed theme to test
	
	UIObject* wakeUpObj = wakeUp;
	this->uiList.add(wakeUpObj);

	this->buttons["Wake_up"] = wakeUp;

	UIButton* mainMenu = new UIButton(gfx.getX(35), gfx.getY(80), gfx.getX(10), gfx.getY(5), this->defaultTheme, gfx.getY(1),
	"Main Menu", gfx.getCharSize(80), &this->fonts["default"], true); //changed theme to test
	
	UIObject* mainMenuObj = mainMenu;
	this->uiList.add(mainMenuObj);

	this->buttons["Main_Menu"] = mainMenu;


	UIButton* fire = new UIButton(gfx.getX(35), gfx.getY(40), gfx.getX(30), gfx.getY(20), this->defaultTheme, gfx.getY(1),
	"stoke the fire", gfx.getCharSize(50), &this->fonts["default"], true); //changed theme to test
	
	UIObject* fireObj = fire;
	this->uiList.add(fireObj);

	this->buttons["Stoke_Fire"] = fire;

	UIDisplayText* t = new UIDisplayText(gfx.getX(5),gfx.getY(5), defaultTheme, "fire started", gfx.getCharSize(80), &this->fonts["default"]);
	UIObject* tObj = t;
	this->uiList.add(tObj);

	this->texts["F1"] = t;

}

GameState::GameState(GlobalData* global_data) : State(global_data){
	this->initVariables();
	this->initFonts();
	this->initColors();
	this->initKeybinds();
	this->initUI();
}
GameState::~GameState(){

}

/* Functions */
void GameState::resetUI(){

}

//Ticks and render
void GameState::updateButtons(){
	// if(showGame){
	// 	buttons.erase("Wake_up");
	// }
	if(this->buttons["Wake_up"]->isClicked()){
		std::cout << "Wake up pushed" << std::endl;
		showGame = true;
	}
	if(this->buttons["Main_Menu"]->isClicked()) {
		this->endState();
	}
	if(buttons["Stoke_Fire"]->isClicked()){
		std::cout << "fire stoked" << std::endl;
		texts["F1"]->move(5.f, 50.f);
	}
}
void GameState::updateKeyInput(){

}//prob where can fix testbox
void GameState::tick(const float& dt){
	this->uiList.tick(dt, this->globalData->window);

	this->updateKeyTime(dt);
	this->updateKeyInput();
	this->updateButtons();
}

void GameState::renderBackground(sf::RenderTarget* target){
	GraphicsConverter gfx = GraphicsConverter(this->globalData->gfxSettings->resolution);
		
	sf::RectangleShape leftScreen;
	leftScreen.setFillColor(sf::Color::Transparent);
	leftScreen.setOutlineThickness(4.f);
	leftScreen.setOutlineColor(this->defaultTheme["normalTextColor"]);
	leftScreen.setPosition(sf::Vector2f(gfx.getX(1), gfx.getY(2)));
	leftScreen.setSize(sf::Vector2f(gfx.getX(31), gfx.getY(90)));
	sf::RectangleShape midScreen;
	midScreen.setFillColor(sf::Color::Transparent);
	midScreen.setOutlineThickness(4.f);
	midScreen.setOutlineColor(this->defaultTheme["normalTextColor"]);
	midScreen.setPosition(sf::Vector2f(gfx.getX(33.5), gfx.getY(2)));
	midScreen.setSize(sf::Vector2f(gfx.getX(33), gfx.getY(90)));
	sf::RectangleShape rightScreen;
	rightScreen.setFillColor(sf::Color::Transparent);
	rightScreen.setOutlineThickness(4.f);
	rightScreen.setOutlineColor(this->defaultTheme["normalTextColor"]);
	rightScreen.setPosition(sf::Vector2f(gfx.getX(68), gfx.getY(2)));
	rightScreen.setSize(sf::Vector2f(gfx.getX(31), gfx.getY(90)));

	//we could use a grad texture instead

	// sf::VertexArray gradient(sf::Quads, 4);
	// gradient[0].position = sf::Vector2f(gfx.getX(2), gfx.getY(50));
	// gradient[1].position = sf::Vector2f(gfx.getX(30), gfx.getY(50));
	// gradient[2].position = sf::Vector2f(gfx.getX(30), gfx.getY(89));
	// gradient[3].position = sf::Vector2f(gfx.getX(2), gfx.getY(89));

	// gradient[0].color = sf::Color::Transparent;
	// gradient[1].color = sf::Color::Transparent;
	// gradient[2].color = sf::Color(173,181,189);
	// gradient[3].color = sf::Color(173,181,189);
	target->draw(leftScreen);
	target->draw(midScreen);
	target->draw(rightScreen);
}

void GameState::render(sf::RenderTarget* target){

	if (!target)
		target = this->globalData->window;

	if(showGame){
		//uiList.remove(buttons["Wake_up"]);
		if(asleep){
			uiList.popBack();
			asleep = false;
		}
		renderBackground(target);

		this->uiList.render(target);
	}
	else{
		buttons["Wake_up"]->render(target);
	}


	this->renderMousePos();
}
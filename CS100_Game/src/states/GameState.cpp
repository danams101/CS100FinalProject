#include "../stdafx.h"
#include "GameState.h"

/* Initializer Functions */

void GameState::initVariables(){
    // inventory, health and stuff maybe
}

void GameState::initFonts(){
        /* Implementation to load in fonts
	In the future, should be able to load multiple fonts
	Using a gfx loader class from a .ini file*/

	sf::Font font;

	if (!font.loadFromFile(this->defaultFontFile))
	{
		throw("ERROR::GAMESTATE::COULD NOT LOAD FONT");
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

	this->tabButtonTheme["idleColor"] = sf::Color::Transparent;
	this->tabButtonTheme["hoverColor"] = sf::Color::Transparent; 
	this->tabButtonTheme["activeColor"] = sf::Color::Transparent;
	this->tabButtonTheme["accentIdleColor"] = sf::Color(32,37,41);
	this->tabButtonTheme["accentHoverColor"] = sf::Color(130,130,130);
	this->tabButtonTheme["accentActiveColor"] = sf::Color(206,212,218);
}

/* make a tab button
pushes back a new state
maybe a new gamestate*/

// Initialize keybinds
void GameState::initKeybinds(){
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

// Initialize the text map from text file
void GameState::initTexts(){
	GraphicsConverter gfx = GraphicsConverter(this->globalData->gfxSettings->resolution);

	std::ifstream ifs("../res/config/updateTexts.ini");
	//DEBUG
	if(!ifs.is_open()){
		std::cout << "update texts not opened!" << "\n";
	}

	if(ifs.is_open()){
		std::string key = "";
		std::string text = "";
		while(getline(ifs, key)){
			getline(ifs, text);
			this->texts[key] = text;
		}
	}
	ifs.close();

	// DEBUG REMOVE LATER!
	// for (auto i : this->texts)
	// {
	// 	std::cout << i.first << " " << i.second << "\n";
	// }
}

// Initialize UI
void GameState::initUI(){
	GraphicsConverter gfx = GraphicsConverter(this->globalData->gfxSettings->resolution);

	UIButton* wakeUp = new UIButton(gfx.getX(40), gfx.getY(60), gfx.getX(20), gfx.getY(15), this->defaultTheme, gfx.getY(1),
	"Wake up", gfx.getCharSize(40), &this->fonts["default"], true); //changed theme to test
	
	UIObject* wakeUpObj = wakeUp;
	this->uiList.add(wakeUpObj);

	this->buttons["Wake_up"] = wakeUp;

	// a dark forest tab
	UIButton* forest = new UIButton(gfx.getX(50), gfx.getY(1.65), gfx.getX(16.7), gfx.getY(8), this->tabButtonTheme, gfx.getY(0.4),
	"A Dark Forest", gfx.getCharSize(80), &this->fonts["default"], true); //changed theme to test
	
	UIObject* forestObj = forest;
	this->uiList.add(forestObj);

	this->buttons["Forest"] = forest;

	UIDisplayText* campfireTab = new UIDisplayText(gfx.getX(37), gfx.getY(4), gfx.getX(8), gfx.getY(4), this->defaultTheme, "Camp Fire", gfx.getCharSize(80), &this->fonts["default"]); //changed theme to test
	campfireTab->setTextBold();
	this->uiList.add(campfireTab);
	

	UIButton* mainMenu = new UIButton(gfx.getX(35), gfx.getY(80), gfx.getX(10), gfx.getY(5), this->defaultTheme, gfx.getY(1),
	"Main Menu", gfx.getCharSize(80), &this->fonts["default"], true); //changed theme to test
	
	UIObject* mainMenuObj = mainMenu;
	this->uiList.add(mainMenuObj);

	this->buttons["Main_Menu"] = mainMenu;


	UIButton* fire = new UIButton(gfx.getX(35), gfx.getY(20), gfx.getX(20), gfx.getY(10), this->defaultTheme, gfx.getY(1),
	"Stoke fire", gfx.getCharSize(60), &this->fonts["default"], true); //changed theme to test
	
	UIObject* fireObj = fire;
	this->uiList.add(fireObj);

	this->buttons["Stoke_Fire"] = fire;

	UIButtonTimer* gatherWood = new UIButtonTimer(gfx.getX(35), gfx.getY(32), gfx.getX(20), gfx.getY(10), this->defaultTheme, gfx.getY(1),
	"Gather Wood", gfx.getCharSize(60), &this->fonts["default"], true, 10.f, false);///del
	UIObject* woodObj = gatherWood;
	this->uiList.add(woodObj);
	this->timers["Gather_Wood"] = gatherWood;

	UIDisplayText* inventoryText = new UIDisplayText(gfx.getX(78), gfx.getY(4), gfx.getX(8), gfx.getY(4), this->defaultTheme, "Inventory: \n", gfx.getCharSize(80), &this->fonts["default"]);
	this->uiList.add(inventoryText);
	inventoryText->setTextBold();

	UIDisplayText* woodText = new UIDisplayText(gfx.getX(75), gfx.getY(10), gfx.getX(8), gfx.getY(4), this->defaultTheme, "Wood:    ", gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(woodText);
	UIDisplayText* meatText = new UIDisplayText(gfx.getX(75), gfx.getY(15), gfx.getX(8), gfx.getY(4), this->defaultTheme, "Meat:    ", gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(meatText);
	UIDisplayText* metalText = new UIDisplayText(gfx.getX(75), gfx.getY(20), gfx.getX(8), gfx.getY(4), this->defaultTheme, "Metal:    ", gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(metalText);
	UIDisplayText* clothText = new UIDisplayText(gfx.getX(75), gfx.getY(25), gfx.getX(8), gfx.getY(4), this->defaultTheme, "Cloth:    ", gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(clothText);//add to inventory

	UIDisplayText* woodNum = new UIDisplayText(gfx.getX(80), gfx.getY(10), gfx.getX(8), gfx.getY(4), this->defaultTheme, std::to_string(inventory.getnumWood()), gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(woodNum);
	UIDisplayText* meatNum = new UIDisplayText(gfx.getX(80), gfx.getY(15), gfx.getX(8), gfx.getY(4), this->defaultTheme, std::to_string(inventory.getnumMeat()), gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(meatNum);
	UIDisplayText* metalNum = new UIDisplayText(gfx.getX(80), gfx.getY(20), gfx.getX(8), gfx.getY(4), this->defaultTheme, std::to_string(inventory.getnumMetal()), gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(metalNum);
	// UIDisplayText* clothNum = new UIDisplayText(gfx.getX(75), gfx.getY(25), gfx.getX(8), gfx.getY(4), this->defaultTheme, std::to_string(inventory.getnumCloth()), gfx.getCharSize(85), &this->fonts["default"]);
	// this->uiList.add(clothNum);//add to inventory

	// UIDisplayText* t = new UIDisplayText(gfx.getX(5),gfx.getY(5), defaultTheme, "fire started", gfx.getCharSize(80), &this->fonts["default"]);
	// UIObject* tObj = t;
	// this->uiList.add(tObj);

	// this->displayTexts["F1"] = t;

}

GameState::GameState(GlobalData* global_data) : State(global_data){
	this->initVariables();
	this->initFonts();
	this->initColors();
	this->initKeybinds();
	this->initTexts();
	this->initUI();
}
GameState::~GameState(){

	// for(std::map<std::string, UIButton*>::iterator it = buttons.begin(); it != buttons.end(); it++){
	// 	delete (it->second);
	// }
	// buttons.clear();

	//causes segmentation fault

}

/* Functions */
void GameState::resetUI(){

}

void GameState::configureTextList(std::list<uiText*>& list){
	GraphicsConverter gfx = GraphicsConverter(this->globalData->gfxSettings->resolution);
	for (auto it: list){
		it->move(0, gfx.getY(5));
		it->setColor(sf::Color(it->getColor().r, it->getColor().g, it->getColor().b,it->getColor().a-10));
	}
	if(list.size() > 17){
		list.pop_front();
	}

}

//Ticks and render
void GameState::updateButtons(){
	// if(showGame){
	// 	buttons.erase("Wake_up");
	// }
	GraphicsConverter gfx = GraphicsConverter(this->globalData->gfxSettings->resolution);
	if(this->buttons["Wake_up"]->isClicked() && !showGame){
		//std::cout << "Wake up pushed" << std::endl;
		showGame = true;
	}
	if(this->buttons["Main_Menu"]->isClicked()) {
		this->endState();
	}
	if(buttons["Stoke_Fire"]->isClicked()){
		if(fireState == 0){
			uiTexts.push_back(new uiText(gfx.getCharSize(92), defaultTheme["normalTextColor"], this->texts["FireState0"], this->fonts["default"], sf::Vector2f(gfx.getX(2), gfx.getY(0.5))));
		}
		else if (fireState == 1){
			uiTexts.push_back(new uiText(gfx.getCharSize(92), defaultTheme["normalTextColor"], this->texts["FireState1"], this->fonts["default"], sf::Vector2f(gfx.getX(2), gfx.getY(0.5))));
		}
		else {
			uiTexts.push_back(new uiText(gfx.getCharSize(92), defaultTheme["normalTextColor"], this->texts["FireState2"], this->fonts["default"], sf::Vector2f(gfx.getX(2), gfx.getY(0.5))));
		}
		configureTextList(this->uiTexts);

		if(fireState < 2){
			++fireState;
		}
	}

	if(buttons["Forest"]->isClicked()){
		std::cout << "To the Dark Forest!" << std::endl;
		//this->globalData->states->push(new ForestState(this->globalData));
	}

	if(timers["Gather_Wood"]->isClicked()){
		if(timers["Gather_Wood"]->getTimerActivation() == false){
			int randWood = rand() % 10;
			this->inventory.SetWood(inventory.getnumWood() + randWood);
			std::string s = "You gathered " + std::to_string(randWood) + " wood.";
			uiTexts.push_back(new uiText(gfx.getCharSize(92), defaultTheme["normalTextColor"], s, this->fonts["default"], sf::Vector2f(gfx.getX(2), gfx.getY(0.5))));
			configureTextList(uiTexts);
		}
		timers["Gather_Wood"]->setTimerActivation(true);

		std::cout << inventory.getnumWood() << std::endl;
	}


}

void GameState::updateInventory(){
	//make a map for inventory
	//update to new inventory values
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

	target->draw(leftScreen);
	target->draw(midScreen);
	target->draw(rightScreen);
}

void GameState::renderUpdateTexts(sf::RenderTarget* target){
	GraphicsConverter gfx = GraphicsConverter(this->globalData->gfxSettings->resolution);
	// for(auto it : this->scrolledText){
	// 	it->render(target);
	// 	//it->move(gfx.getX(0),gfx.getY(10));
    // }
	// disT = new UIDisplayText(gfx.getX(10), gfx.getY(8), gfx.getX(10), gfx.getY(6), this->defaultTheme, "firestoked", gfx.getCharSize(80), &this->fonts["default"]);
	// disT->render(target);
	// disT->setPosition(disT->getX()+10, disT->getY()+10);

	// sf::VertexArray gradient(sf::Quads, 4);
	// gradient[0].position = sf::Vector2f(gfx.getX(2), gfx.getY(50));
	// gradient[1].position = sf::Vector2f(gfx.getX(30), gfx.getY(50));
	// gradient[2].position = sf::Vector2f(gfx.getX(30), gfx.getY(89));
	// gradient[3].position = sf::Vector2f(gfx.getX(2), gfx.getY(89));

	// gradient[0].color = sf::Color::Transparent;
	// gradient[1].color = sf::Color::Transparent;
	// gradient[2].color = sf::Color(173,181,189);
	// gradient[3].color = sf::Color(173,181,189);

	// //load gradient image
    // sf::Texture grad;
    // if(!grad.loadFromFile("grad1.png")){
    //     std::cout << "COULD NOT LOAD GRADIENT" << std::endl;
    // }

    // sf::Sprite gradSprite;
    // gradSprite.setTexture(grad);
	// //gradSprite.setColor(sf::Color(0, 255, 0));

	sf::RectangleShape gradHalf;
	gradHalf.setFillColor(sf::Color(173,181,189,128));
	gradHalf.setPosition(sf::Vector2f(gfx.getX(2), gfx.getY(50)));
	gradHalf.setSize(sf::Vector2f(gfx.getX(29), gfx.getY(40)));

	sf::RectangleShape gradFull;
	gradFull.setFillColor(sf::Color(173,181,189,192));
	gradFull.setPosition(sf::Vector2f(gfx.getX(2), gfx.getY(75)));
	gradFull.setSize(sf::Vector2f(gfx.getX(29), gfx.getY(10)));

	for (auto it : uiTexts){
		it->render(target);
	}

	// target->draw(gradHalf);
	// target->draw(gradFull);
	
}

void GameState::render(sf::RenderTarget* target){

	if (!target)
		target = this->globalData->window;

	if(showGame){
		if(asleep){
			uiList.popBack();
			asleep = false;
		}
		renderBackground(target);
		renderUpdateTexts(target);

		this->uiList.render(target);
		
	}
	else{
		target->clear(sf::Color::Black);
		buttons["Wake_up"]->render(target);
	}


	this->renderMousePos();
}
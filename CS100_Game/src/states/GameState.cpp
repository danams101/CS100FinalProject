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

	std::ifstream ifs("res/config/updateTexts.ini");
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

}

// Initialize UI
void GameState::initUI(){
	GraphicsConverter gfx = GraphicsConverter(this->globalData->gfxSettings->resolution);

	UIButton* wakeUp = new UIButton(gfx.getX(40), gfx.getY(60), gfx.getX(20), gfx.getY(15), this->defaultTheme, gfx.getY(1),
	"Wake up", gfx.getCharSize(40), &this->fonts["default"], true);
	
	//UIObject* wakeUpObj = wakeUp;////////////////////////////
	//this->uiList.add(wakeUpObj);
	this->uiList.add(wakeUp);

	this->buttons["Wake_up"] = wakeUp;

	// a dark forest tab
	UIButton* forest = new UIButton(gfx.getX(50), gfx.getY(1.65), gfx.getX(16.7), gfx.getY(8), this->tabButtonTheme, gfx.getY(0.4),
	"A Dark Forest", gfx.getCharSize(80), &this->fonts["default"], true);
	
	// UIObject* forestObj = forest;
	// this->uiList.add(forestObj);
	this->uiList.add(forest);

	this->buttons["Forest"] = forest;

	UIDisplayText* campfireTab = new UIDisplayText(gfx.getX(37), gfx.getY(4), gfx.getX(8), gfx.getY(4), this->defaultTheme, "Camp Fire", gfx.getCharSize(80), &this->fonts["default"]); //changed theme to test
	campfireTab->setTextBold();
	this->uiList.add(campfireTab);
	

	UIButton* mainMenu = new UIButton(gfx.getX(35), gfx.getY(85), gfx.getX(10), gfx.getY(5), this->defaultTheme, gfx.getY(1),
	"Main Menu", gfx.getCharSize(80), &this->fonts["default"], true);
	
	// UIObject* mainMenuObj = mainMenu;/////////////////
	// this->uiList.add(mainMenuObj);
	this->uiList.add(mainMenu);

	this->buttons["Main_Menu"] = mainMenu;


	UIButton* fire = new UIButton(gfx.getX(35), gfx.getY(20), gfx.getX(14), gfx.getY(8), this->defaultTheme, gfx.getY(1),
	"Stoke fire", gfx.getCharSize(66), &this->fonts["default"], true);
	
	// UIObject* fireObj = fire;
	// this->uiList.add(fireObj);
	this->uiList.add(fire);

	this->buttons["Stoke_Fire"] = fire;

	UIDisplayText* Build = new UIDisplayText(gfx.getX(35), gfx.getY(30), gfx.getX(8), gfx.getY(4), this->defaultTheme, "Build:", gfx.getCharSize(80), &this->fonts["default"]);
	Build->setTextBold();
	this->uiList.add(Build);


	UIButton* tent = new UIButton(gfx.getX(35), gfx.getY(35), gfx.getX(14), gfx.getY(8), this->defaultTheme, gfx.getY(1),
	"Tent", gfx.getCharSize(66), &this->fonts["default"], true);
	
	// UIObject* tentObj = tent;
	// this->uiList.add(tentObj);
	this->uiList.add(tent);

	this->buttons["Build_Tent"] = tent;

	UIButton* trap = new UIButton(gfx.getX(35), gfx.getY(45), gfx.getX(14), gfx.getY(8), this->defaultTheme, gfx.getY(1),
	"Trap", gfx.getCharSize(66), &this->fonts["default"], true);
	
	// UIObject* trapObj = trap;
	// this->uiList.add(trapObj);
	this->uiList.add(trap);

	this->buttons["Build_Trap"] = trap;
	
	UIDisplayText* Craft = new UIDisplayText(gfx.getX(35), gfx.getY(55), gfx.getX(8), gfx.getY(4), this->defaultTheme, "Craft:", gfx.getCharSize(80), &this->fonts["default"]);
	Craft->setTextBold();
	this->uiList.add(Craft);

	UIButtonTimer* craftElec = new UIButtonTimer(gfx.getX(35), gfx.getY(60), gfx.getX(14), gfx.getY(8), this->defaultTheme, gfx.getY(1),
	"Craft Electronics", gfx.getCharSize(98), &this->fonts["default"], true, 20.f, false);
	// UIObject* elecObj = craftElec;
	// this->uiList.add(elecObj);
	this->uiList.add(craftElec);

	this->timers["Craft_Electronics"] = craftElec;

	UIButton* radio = new UIButton(gfx.getX(35), gfx.getY(70), gfx.getX(14), gfx.getY(8), this->defaultTheme, gfx.getY(1),
	"Build Radio", gfx.getCharSize(66), &this->fonts["default"], true);
	
	// UIObject* radioObj = radio;
	// this->uiList.add(radioObj);
	this->uiList.add(radio);

	this->buttons["Build_Radio"] = radio;

	UIButtonTimer* gatherWood = new UIButtonTimer(gfx.getX(51), gfx.getY(20), gfx.getX(14), gfx.getY(8), this->defaultTheme, gfx.getY(1),
	"Gather Wood", gfx.getCharSize(70), &this->fonts["default"], true, 10.f, false);
	// UIObject* woodObj = gatherWood;
	// this->uiList.add(woodObj);
	this->uiList.add(gatherWood);
	this->timers["Gather_Wood"] = gatherWood;

	UIButtonTimer* gatherCloths = new UIButtonTimer(gfx.getX(51), gfx.getY(30), gfx.getX(14), gfx.getY(8), this->defaultTheme, gfx.getY(1),
	"Gather Cloth", gfx.getCharSize(70), &this->fonts["default"], true, 10.f, false);
	// UIObject* clothObj = gatherCloths;
	// this->uiList.add(clothObj);
	this->uiList.add(gatherCloths);
	this->timers["Gather_Cloth"] = gatherCloths;

	UIButtonTimer* forageMetals = new UIButtonTimer(gfx.getX(51), gfx.getY(40), gfx.getX(14), gfx.getY(8), this->defaultTheme, gfx.getY(1),
	"Forage Metal", gfx.getCharSize(70), &this->fonts["default"], true, 15.f, false);
	// UIObject* metalObj = forageMetals;
	// this->uiList.add(metalObj);
	this->uiList.add(forageMetals);
	this->timers["Forage_Metal"] = forageMetals;

	UIButtonTimer* checkTraps = new UIButtonTimer(gfx.getX(51), gfx.getY(50), gfx.getX(14), gfx.getY(8), this->defaultTheme, gfx.getY(1),
	"Check Traps", gfx.getCharSize(70), &this->fonts["default"], true, 15.f, false);
	// UIObject* trapsObj = checkTraps;
	// this->uiList.add(trapsObj);
	this->uiList.add(checkTraps);
	this->timers["Check_Traps"] = checkTraps;

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
	this->uiList.add(clothText);
	UIDisplayText* electronicsText = new UIDisplayText(gfx.getX(75), gfx.getY(30), gfx.getX(8), gfx.getY(4), this->defaultTheme, "Electronics:    ", gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(electronicsText);

	UIDisplayText* woodNum = new UIDisplayText(gfx.getX(83), gfx.getY(10), gfx.getX(8), gfx.getY(4), this->defaultTheme, std::to_string(inventory.getnumWood()), gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(woodNum);
	inventoryMap["Wood"] = woodNum;
	UIDisplayText* meatNum = new UIDisplayText(gfx.getX(83), gfx.getY(15), gfx.getX(8), gfx.getY(4), this->defaultTheme, std::to_string(inventory.getnumMeat()), gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(meatNum);
	inventoryMap["Meat"] = meatNum;
	UIDisplayText* metalNum = new UIDisplayText(gfx.getX(83), gfx.getY(20), gfx.getX(8), gfx.getY(4), this->defaultTheme, std::to_string(inventory.getnumMetal()), gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(metalNum);
	inventoryMap["Metal"] = metalNum;
	UIDisplayText* clothNum = new UIDisplayText(gfx.getX(83), gfx.getY(25), gfx.getX(8), gfx.getY(4), this->defaultTheme, std::to_string(inventory.getnumCloth()), gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(clothNum);
	inventoryMap["Cloth"] = clothNum;
	UIDisplayText* elecNum = new UIDisplayText(gfx.getX(90), gfx.getY(30), gfx.getX(8), gfx.getY(4), this->defaultTheme, std::to_string(inventory.getnumElectronics()), gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(elecNum);
	inventoryMap["Electronics"] = elecNum;


	UIDisplayText* campText = new UIDisplayText(gfx.getX(78), gfx.getY(50), gfx.getX(8), gfx.getY(4), this->defaultTheme, "Camp:", gfx.getCharSize(80), &this->fonts["default"]);
	this->uiList.add(campText);
	campText->setTextBold();

	UIDisplayText* tentText = new UIDisplayText(gfx.getX(75), gfx.getY(55), gfx.getX(8), gfx.getY(4), this->defaultTheme, "Tents:    ", gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(tentText);
	UIDisplayText* trapText = new UIDisplayText(gfx.getX(75), gfx.getY(60), gfx.getX(8), gfx.getY(4), this->defaultTheme, "Traps:    ", gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(trapText);
	UIDisplayText* radioProgText = new UIDisplayText(gfx.getX(75), gfx.getY(65), gfx.getX(8), gfx.getY(4), this->defaultTheme, "Radio Progress:    ", gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(radioProgText);

	UIDisplayText* tentNum = new UIDisplayText(gfx.getX(83), gfx.getY(55), gfx.getX(8), gfx.getY(4), this->defaultTheme, std::to_string(camp.getNumTents()), gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(tentNum);
	inventoryMap["Tent"] = tentNum;
	UIDisplayText* trapNum = new UIDisplayText(gfx.getX(83), gfx.getY(60), gfx.getX(8), gfx.getY(4), this->defaultTheme, std::to_string(camp.getNumTraps()), gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(trapNum);
	inventoryMap["Trap"] = trapNum;
	UIDisplayText* radioProg = new UIDisplayText(gfx.getX(90), gfx.getY(65), gfx.getX(8), gfx.getY(4), this->defaultTheme, std::to_string(camp.getRadioProgress()), gfx.getCharSize(85), &this->fonts["default"]);
	this->uiList.add(radioProg);
	inventoryMap["RadioProg"] = radioProg;

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
	// 	it->
	// }
	//uiList.~UIList();/////////????????????NOPE

	buttons.clear();
	timers.clear();
	inventoryMap.clear();

	//causes segmentation fault

	for(auto it : this->uiTexts){
        delete it;
    }
    this->uiTexts.clear();

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
	
	GraphicsConverter gfx = GraphicsConverter(this->globalData->gfxSettings->resolution);
	if(this->buttons["Wake_up"]->isClicked() && !showGame){
		showGame = true;
		buttons["Wake_up"]->setPosition(gfx.getX(150),gfx.getY(150));
	}
	if(this->buttons["Main_Menu"]->isClicked()) {
		this->endState();
	}
	if(buttons["Stoke_Fire"]->isClicked()){
		if(inventory.getnumWood() > 0){
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
			inventory.SetWood(inventory.getnumWood()-1);
		}
		else {
			uiTexts.push_back(new uiText(gfx.getCharSize(92), defaultTheme["normalTextColor"], "..theres nothing to use.", this->fonts["default"], sf::Vector2f(gfx.getX(2), gfx.getY(0.5))));
			configureTextList(this->uiTexts);
		}
	}

	if(buttons["Build_Tent"]->isClicked()){
		if(inventory.getnumWood() >= camp.getReqWoodsTent() && inventory.getnumCloth() >= camp.getReqClothsTent()){
			inventory.SetWood(inventory.getnumWood()-camp.getReqWoodsTent());
			inventory.SetCloth(inventory.getnumCloth()-camp.getReqClothsTent());
			camp.incrementTents();
			
			uiTexts.push_back(new uiText(gfx.getCharSize(92), defaultTheme["normalTextColor"], this->texts["BuiltTent"], this->fonts["default"], sf::Vector2f(gfx.getX(2), gfx.getY(0.5))));
			configureTextList(this->uiTexts);
			camp.updateReqMaterials();

			//std::cout << camp.getNumTents() << " " << camp.getReqWoodsTent() << std::endl;
		}
		else {
			uiTexts.push_back(new uiText(gfx.getCharSize(92), defaultTheme["normalTextColor"], this->texts["NotEnough"], this->fonts["default"], sf::Vector2f(gfx.getX(2), gfx.getY(0.5))));
			configureTextList(this->uiTexts);
			
		}
	}

	if(buttons["Build_Trap"]->isClicked()){
		if(inventory.getnumWood() >= camp.getReqWoodsTrap() && inventory.getnumMetal() >= camp.getReqMetalsTrap()){
			inventory.SetWood(inventory.getnumWood()-camp.getReqWoodsTrap());
			inventory.SetMetal(inventory.getnumMetal()-camp.getReqMetalsTrap());
			camp.incrementTraps();
			
			uiTexts.push_back(new uiText(gfx.getCharSize(92), defaultTheme["normalTextColor"], this->texts["BuiltTrap"], this->fonts["default"], sf::Vector2f(gfx.getX(2), gfx.getY(0.5))));
			configureTextList(this->uiTexts);
			camp.updateReqMaterials();

			//std::cout << "Traps: " << camp.getNumTraps() << std::endl;
		}
		else {
			uiTexts.push_back(new uiText(gfx.getCharSize(92), defaultTheme["normalTextColor"], this->texts["NotEnough"], this->fonts["default"], sf::Vector2f(gfx.getX(2), gfx.getY(0.5))));
			configureTextList(this->uiTexts);

		}
	}
	
	if(buttons["Build_Radio"]->isClicked()){
		if(inventory.getnumMetal() >= camp.getReqMetalsRadio() && inventory.getnumElectronics() >= camp.getReqElectronicsRadio()){
			inventory.SetMetal(inventory.getnumMetal()-camp.getReqMetalsRadio());
			inventory.SetElectronics(inventory.getnumElectronics()-camp.getReqElectronicsRadio());
			camp.incrementRadioProgress();
			
			uiTexts.push_back(new uiText(gfx.getCharSize(92), defaultTheme["normalTextColor"], this->texts["RadioProgress"], this->fonts["default"], sf::Vector2f(gfx.getX(2), gfx.getY(0.5))));
			configureTextList(this->uiTexts);
			camp.updateReqMaterials();

		}
		else {
			uiTexts.push_back(new uiText(gfx.getCharSize(92), defaultTheme["normalTextColor"], this->texts["NotEnough"], this->fonts["default"], sf::Vector2f(gfx.getX(2), gfx.getY(0.5))));
			configureTextList(this->uiTexts);

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

		//std::cout << inventory.getnumWood() << std::endl;
	}

	if(timers["Gather_Cloth"]->isClicked()){
		if(timers["Gather_Cloth"]->getTimerActivation() == false){
			int randCloth = rand() % 10;
			this->inventory.SetCloth(inventory.getnumCloth() + randCloth);
			std::string s = "You gathered " + std::to_string(randCloth) + " cloth.";
			uiTexts.push_back(new uiText(gfx.getCharSize(92), defaultTheme["normalTextColor"], s, this->fonts["default"], sf::Vector2f(gfx.getX(2), gfx.getY(0.5))));
			configureTextList(uiTexts);
		}
		timers["Gather_Cloth"]->setTimerActivation(true);

		//std::cout << "Cloth: " << inventory.getnumCloth() << std::endl;
	}

	if(timers["Forage_Metal"]->isClicked()){
		if(timers["Forage_Metal"]->getTimerActivation() == false){
			int randMetal = rand() % 10;
			this->inventory.SetMetal(inventory.getnumMetal() + randMetal);
			std::string s = "You gathered " + std::to_string(randMetal) + " metal.";
			uiTexts.push_back(new uiText(gfx.getCharSize(92), defaultTheme["normalTextColor"], s, this->fonts["default"], sf::Vector2f(gfx.getX(2), gfx.getY(0.5))));
			configureTextList(uiTexts);
		}
		timers["Forage_Metal"]->setTimerActivation(true);

		//std::cout << "Metal: " << inventory.getnumCloth() << std::endl;
	}

	if(timers["Check_Traps"]->isClicked()){
		if(timers["Check_Traps"]->getTimerActivation() == false){
			int randMeat = rand() % 10;
			this->inventory.SetMeat(inventory.getnumMeat() + (randMeat * camp.getNumTraps()));
			std::string s = "You gathered " + std::to_string(randMeat * camp.getNumTraps()) + " meat.";
			uiTexts.push_back(new uiText(gfx.getCharSize(92), defaultTheme["normalTextColor"], s, this->fonts["default"], sf::Vector2f(gfx.getX(2), gfx.getY(0.5))));
			configureTextList(uiTexts);
		}
		timers["Check_Traps"]->setTimerActivation(true);

		//std::cout << "Meat: " << inventory.getnumMeat() << std::endl;
	}

	if(timers["Craft_Electronics"]->isClicked()){
		if(timers["Craft_Electronics"]->getTimerActivation() == false){
			int randElec = rand() % 5 + 1;
			this->inventory.SetElectronics(inventory.getnumElectronics() + randElec);
			std::string s = "You crafted " + std::to_string(randElec) + " electronics.";
			uiTexts.push_back(new uiText(gfx.getCharSize(92), defaultTheme["normalTextColor"], s, this->fonts["default"], sf::Vector2f(gfx.getX(2), gfx.getY(0.5))));
			configureTextList(uiTexts);
		}
		timers["Craft_Electronics"]->setTimerActivation(true);
	}


}

void GameState::updateInventory(){
	
	std::string currentWood = std::to_string(inventory.getnumWood());
	std::string currentMeat = std::to_string(inventory.getnumMeat());
	std::string currentMetal = std::to_string(inventory.getnumMetal());
	std::string currentCloth = std::to_string(inventory.getnumCloth());
	std::string currentElec = std::to_string(inventory.getnumElectronics());
	std::string currentTents = std::to_string(camp.getNumTents());
	std::string currentTraps = std::to_string(camp.getNumTraps());
	std::string currentRadioProg = std::to_string(camp.getRadioProgress());

	inventoryMap["Wood"]->setText(currentWood);
	inventoryMap["Meat"]->setText(currentMeat);
	inventoryMap["Metal"]->setText(currentMetal);
	inventoryMap["Cloth"]->setText(currentCloth);
	inventoryMap["Electronics"]->setText(currentElec);
	inventoryMap["Tent"]->setText(currentTents);
	inventoryMap["Trap"]->setText(currentTraps);
	inventoryMap["RadioProg"]->setText(currentRadioProg);
}

void GameState::updateKeyInput(){

}//prob where can fix testbox
void GameState::tick(const float& dt){
	this->uiList.tick(dt, this->globalData->window);

	this->updateKeyTime(dt);
	this->updateKeyInput();
	this->updateButtons();
	this->updateInventory();
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

	target->draw(leftScreen);
	target->draw(midScreen);
	target->draw(rightScreen);
}

void GameState::renderUpdateTexts(sf::RenderTarget* target){

	for (auto it : uiTexts){
		it->render(target);
	}
	
}

void GameState::render(sf::RenderTarget* target){

	if (!target)
		target = this->globalData->window;

	if(showGame){
		if(asleep){
			//uiList.popBack();
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
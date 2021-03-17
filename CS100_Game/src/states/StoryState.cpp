#include "../stdafx.h"

#include "StoryState.h"


void StoryState::initVariables(){
	state = 0;
	currentTime = 0.f;
}
void StoryState::initFonts(){
    sf::Font font;

	if (!font.loadFromFile(this->defaultFontFile))
	{
		throw("ERROR::GAMESTATE::COULD NOT LOAD FONT");
		return;
	}
	this->fonts["default"] = font;
}
void StoryState::initColors(){
    /* NOTE: want to have a ini file to initialize this from */

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
void StoryState::initKeybinds(){
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

void StoryState::initDialogues(){
    std::ifstream ifs(brianBlitzFile);

	//DEBUG
	if(!ifs.is_open()){
		std::cout << "brian blitz dialogues not opened!" << "\n";
	}

	if(ifs.is_open()){
		std::string key = "";
		std::string text = "";
		while(getline(ifs, key)){
			getline(ifs, text);
			this->brianBlitz[key] = text;
		}
	}
	ifs.close();
}

// void StoryState::initButtonLists(){
    
// }

void StoryState::initUI(){

/*
Initialize multiple UILists that represent 
different phases of interations.

Hopefully wont have to use maps for each.

maybe if i implement getChild in UIList?
*/
	GraphicsConverter gfx = GraphicsConverter(this->globalData->gfxSettings->resolution);

	grad.setPosition(gfx.getX(10), gfx.getY(60));
	grad.setSize(sf::Vector2f(gfx.getX(80), gfx.getY(40)));
	grad.setFillColor(sf::Color(173,181,189));
	
	textList.push_front(new uiText(gfx.getCharSize(80), this->defaultTheme["normalTextColor"], "A voice: ", this->fonts["default"], sf::Vector2f(gfx.getX(10), gfx.getY(5))));
	textList.push_front(new uiText(gfx.getCharSize(80), this->defaultTheme["normalTextColor"], brianBlitz["start"], this->fonts["default"], sf::Vector2f(gfx.getX(10), gfx.getY(10))));
	
	
	UIButton* Option1A = new UIButton(gfx.getX(10), gfx.getY(60), gfx.getX(20), gfx.getY(15), this->defaultTheme, gfx.getY(1),
	"(Wake up)", gfx.getCharSize(40), &this->fonts["default"], true);
	phase1_0.add(Option1A);

	UIButton* Option1B = new UIButton(gfx.getX(40), gfx.getY(60), gfx.getX(20), gfx.getY(15), this->defaultTheme, gfx.getY(1),
	"...Huh?", gfx.getCharSize(40), &this->fonts["default"], true);
	phase1_0.add(Option1B);

	UIButton* Option1C = new UIButton(gfx.getX(70), gfx.getY(60), gfx.getX(20), gfx.getY(15), this->defaultTheme, gfx.getY(1),
	"5 more minutes...", gfx.getCharSize(50), &this->fonts["default"], true);
	phase1_0.add(Option1C);

	UIButton* Option1_1A = new UIButton(gfx.getX(40), gfx.getY(60), gfx.getX(20), gfx.getY(15), this->defaultTheme, gfx.getY(1),
	"(Wake up)", gfx.getCharSize(40), &this->fonts["default"], true);
	phase1_1.add(Option1_1A);


}

StoryState::StoryState(GlobalData *global_data) : State(global_data){
	this->initVariables();
	this->initFonts();
	this->initColors();
	this->initKeybinds();
	this->initDialogues();
	this->initUI();
}
StoryState::~StoryState(){

}
void StoryState::resetUI(){
	//listToRender = phase1_0;
	
	switch (state){
		case 1:
			listToRender = phase1_0;
			break;

		case 2:
			listToRender = phase1_1;
			break;

		case 3:
			listToRender = phase2_0;
		break;
	}
}

void StoryState::configureDialogues(std::list<uiText*>& list){
	if(!list.empty()){
		// GraphicsConverter gfx = GraphicsConverter(this->globalData->gfxSettings->resolution);
		// for (auto it: list){
		// 	it->move(0, gfx.getY(5));
		// 	//it->setColor(sf::Color(it->getColor().r, it->getColor().g, it->getColor().b,it->getColor().a-10));
		// }
		if(list.size() > 2){
			list.pop_back();
			list.pop_back();
		}
	}
}

void StoryState::updateCurrentTime(const float& dt){
	currentTime += dt;
}


void StoryState::updateButtons(){
	
	// if(this->buttons["Main_Menu"]->isClicked()) {
	// 	this->endState();
	// }
	GraphicsConverter gfx = GraphicsConverter(this->globalData->gfxSettings->resolution);
	// textList.push_front(new uiText(gfx.getCharSize(80), this->defaultTheme["normalTextColor"], "A voice: ", this->fonts["default"], sf::Vector2f(gfx.getX(10), gfx.getY(5))));
	//textList.push_front(new uiText(gfx.getCharSize(80), this->defaultTheme["normalTextColor"], brianBlitz["start"], this->fonts["default"], sf::Vector2f(gfx.getX(10), gfx.getY(10))));
	// //configureDialogues(textList);

	//currentTime = clock.getElapsedTime().asSeconds();
	if(currentTime > 5.f && state == 0){
		//clock.restart();
		currentTime = 0.f;
		state++;
		resetUI();
	}


	if(state == 1){
		//clock.restart();
		if(phase1_0.GetButton(2)->isClicked()){
			//textList.pop_back();
			std::cout << "WAKE UP was clicked!" << std::endl;
			textList.push_front(new uiText(gfx.getCharSize(80), this->defaultTheme["normalTextColor"], "A voice: ", this->fonts["default"], sf::Vector2f(gfx.getX(10), gfx.getY(5))));
			//configureDialogues(textList);
			
			textList.push_front(new uiText(gfx.getCharSize(80), this->defaultTheme["normalTextColor"], brianBlitz["1A"], this->fonts["default"], sf::Vector2f(gfx.getX(10), gfx.getY(10))));
			configureDialogues(textList);
			// if(currentTime >5.f){
			// 	state++;////////////////////NOPE
			// }
			currentTime = 0;
			state+= 2;
			resetUI();
		}
		if(phase1_0.GetButton(1)->isClicked()){
			//textList.pop_back();
			
			std::cout << "HUH? was clicked!" << std::endl;
			textList.push_front(new uiText(gfx.getCharSize(80), this->defaultTheme["normalTextColor"], "A voice: ", this->fonts["default"], sf::Vector2f(gfx.getX(10), gfx.getY(5))));
			//configureDialogues(textList);
			
			textList.push_front(new uiText(gfx.getCharSize(80), this->defaultTheme["normalTextColor"], brianBlitz["1B"], this->fonts["default"], sf::Vector2f(gfx.getX(10), gfx.getY(10))));
			configureDialogues(textList);

			currentTime = 0;
			state++;
			resetUI();
		}
		if(phase1_0.GetButton(0)->isClicked()){
			//textList.pop_back();
			
			std::cout << "5 MORE MIN was clicked!" << std::endl;
			textList.push_front(new uiText(gfx.getCharSize(80), this->defaultTheme["normalTextColor"], "A voice: ", this->fonts["default"], sf::Vector2f(gfx.getX(10), gfx.getY(5))));
			//configureDialogues(textList);
			
			textList.push_front(new uiText(gfx.getCharSize(80), this->defaultTheme["normalTextColor"], brianBlitz["1C"], this->fonts["default"], sf::Vector2f(gfx.getX(10), gfx.getY(10))));
			configureDialogues(textList);

			currentTime = 0;
			state++;
			resetUI();
		}
	}
	//if(this->getKeyDelay()){
	if(state==2 && currentTime > 5.f){

		if(phase1_1.GetButton(0)->isClicked()){
			std::cout << "Phase1.1 wakeup clicked!" << std::endl;
			textList.push_front(new uiText(gfx.getCharSize(80), this->defaultTheme["normalTextColor"], "A voice: ", this->fonts["default"], sf::Vector2f(gfx.getX(10), gfx.getY(5))));
			//configureDialogues(textList);
			
			textList.push_front(new uiText(gfx.getCharSize(80), this->defaultTheme["normalTextColor"], brianBlitz["1_1A"], this->fonts["default"], sf::Vector2f(gfx.getX(10), gfx.getY(10))));
			configureDialogues(textList);
			state++;
			resetUI();

			currentTime = 0;
		}
		
	}

//FINISH SETTING UP
	if(state==3 && currentTime > 5.f){

		if(phase2_0.GetButton(0)->isClicked()){
			std::cout << "Phase2.0 clicked!" << std::endl;
			textList.push_front(new uiText(gfx.getCharSize(80), this->defaultTheme["normalTextColor"], "A voice: ", this->fonts["default"], sf::Vector2f(gfx.getX(10), gfx.getY(5))));
			//configureDialogues(textList);
			
			textList.push_front(new uiText(gfx.getCharSize(80), this->defaultTheme["normalTextColor"], brianBlitz["1_1A"], this->fonts["default"], sf::Vector2f(gfx.getX(10), gfx.getY(10))));
			configureDialogues(textList);
			state++;
			resetUI();

			currentTime = 0;
		}
		
	}


	
}

void StoryState::updateKeyInput(){

}

void StoryState::updateGradient(const float& dt){
	//float timer = 0;
	timer += dt;
	if(grad.getFillColor().a > 0 && timer > 0.1){
		grad.setFillColor(sf::Color(grad.getFillColor().r, grad.getFillColor().g, grad.getFillColor().b,grad.getFillColor().a-5));
		timer = 0;
	}
}

void StoryState::tick(const float &dt){
	updateCurrentTime(dt);

	this->updateKeyTime(dt);
	this->updateKeyInput();
	this->updateButtons();
	this->updateGradient(dt);
	
	//if(state == 1)
		this->phase1_0.tick(dt, this->globalData->window);
	//if(state == 2)
		this->phase1_1.tick(dt, this->globalData->window);

	// sf::Time time = clock.getElapsedTime();
	// currentTime = time.asSeconds();
	// std::cout<< currentTime << std::endl;


}

void StoryState::renderDialogues(sf::RenderTarget* target){

	for (auto it : textList){
		it->render(target);
	}

}

void StoryState::renderGradient(sf::RenderTarget* target){
	GraphicsConverter gfx = GraphicsConverter(this->globalData->gfxSettings->resolution);
	
	
	// sf::RectangleShape grad;
	// grad.setPosition(gfx.getX(10), gfx.getY(60));
	// grad.setSize(sf::Vector2f(gfx.getX(80), gfx.getY(40)));
	// grad.setFillColor(sf::Color(173,181,189));
	// //if(grad.getFillColor().a>0)
	// 	grad.setFillColor(sf::Color(grad.getFillColor().r, grad.getFillColor().g, grad.getFillColor().b,grad.getFillColor().a-10));

	target->draw(grad);

}

void StoryState::render(sf::RenderTarget *target){
	if (!target)
		target = this->globalData->window;

	//target->clear(sf::Color::Black);
	
	renderDialogues(target);

	// if(state == 1){
	// 	this->phase1_0.render(target);
	// 	renderGradient(target);
	// }
	// if(state == 2 && currentTime > 5.f){
	// 	this->phase1_1.render(target);
	// 	renderGradient(target);
	// }

	//listToRender = phase1_1;
	if(currentTime > 5.f){
		listToRender.render(target);

		//currentTime = 0;
	}

	// listToRender.render(target);
	// //renderGradient(target);
}

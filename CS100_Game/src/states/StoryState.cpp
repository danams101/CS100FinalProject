#include "StoryState.h"


void StoryState::initVariables(){

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
    
}

void StoryState::initUI(){

}
StoryState::StoryState(GlobalData *global_data){

}
StoryState::~StoryState(){

}
void StoryState::resetUI(){

}
void StoryState::updateButtons(){

}
void StoryState::tick(const float &dt){

}
void StoryState::render(sf::RenderTarget *target = (sf::RenderTarget *)nullptr){

}

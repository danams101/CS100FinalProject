#include "ForestState.h"

void ForestState::initUI(){
    GraphicsConverter gfx = GraphicsConverter(this->globalData->gfxSettings->resolution);

	UIButton* forestTest = new UIButton(gfx.getX(40), gfx.getY(60), gfx.getX(20), gfx.getY(15), this->defaultTheme, gfx.getY(1),
	"ForestTest", gfx.getCharSize(40), &this->fonts["default"], true); //changed theme to test
	
	UIObject* ForestTestObj = forestTest;
	this->uiList.add(ForestTestObj);

	this->buttons["Forest_test"] = forestTest;

}

ForestState::ForestState(GlobalData* global_data) : GameState(global_data){
    initUI();
}

// void ForestState::renderBackground(sf::RenderTarget* target){

// }

void ForestState::updateButtons(){
    if(this->buttons["Forest_test"]->isClicked()){
        std::cout << "test button pushed" << std::endl;
    }
}

void ForestState::render(sf::RenderTarget* target){
    GameState::renderBackground(target);
    this->uiList.render(target);
}
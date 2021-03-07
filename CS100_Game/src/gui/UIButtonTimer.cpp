#include "../stdafx.h"
#include "UIButtonTimer.h"


UIButtonTimer::UIButtonTimer(float x, float y, float width, float height, std::map<std::string, sf::Color> colors, float thickness,
		std::string text, int textSize, sf::Font* font, bool centered,float duration, bool activated) : UIButton(x, y, width, height, colors, thickness,
		text, textSize, font, centered){
    status = new UIStatBar(this->x, this->y, this->width, this->height, this->colors, duration, activated);
}
// void UIButtonTimer::initStatBar(){
//     status->setSize(this->width, this->height);
//     status->setPosition(this->x, this->y);
//     status->
// }
void UIButtonTimer::updateState(sf::Window* window){
    this->clicked = false;
    if( (!(sf::Mouse::isButtonPressed(sf::Mouse::Left))) && this->state == ACTIVE) {

		// If the mouse is no longer pressed and it was pressed, then we clicked
		this->clicked = true;
	}

    this->state = IDLE;

    sf::Vector2i mousePosInt = sf::Mouse::getPosition(*window);
	sf::Vector2f mousePosFloat = static_cast<sf::Vector2f>(mousePosInt);

	// Hover
	if(this->bounds.getGlobalBounds().contains(mousePosFloat)){
        this->state = HOVER;

		// Pressed
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !status->isDone()) {
			this->state = ACTIVE;
            status->setActivation(true);
            clickable = false;//idk yet
		}
    }

}

/*
Need a function in statbar to determin if timer is done
and a way to reset the statbar
*/

void UIButtonTimer::renderButton(sf::RenderTarget* target){

}
void UIButtonTimer::renderText(sf::RenderTarget* target){

}
void UIButtonTimer::renderStatbar(sf::RenderTarget* target){

}
void UIButtonTimer::tick(const float&dt, sf::Window* window){

}
void UIButtonTimer::render(sf::RenderTarget* target){

}
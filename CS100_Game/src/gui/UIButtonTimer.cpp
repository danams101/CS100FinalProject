#include "../stdafx.h"
#include "UIButtonTimer.h"

/* Constructor (UIButton constuctor + initialization of UIStatBar) */
UIButtonTimer::UIButtonTimer(float x, float y, float width, float height, std::map<std::string, sf::Color> colors, float thickness,
		std::string text, int textSize, sf::Font* font, bool centered,float duration, bool activated) : UIButton(x, y, width, height, colors, thickness,
		text, textSize, font, centered){
    status = new UIStatBar(this->x, this->y, this->width, this->height, this->colors, duration, activated);
}

/* UIButtonTimer Accessors */
bool UIButtonTimer::isTimerDone(){
	return this->status->isDone();
}
bool UIButtonTimer::isClickable(){
	return this->clickable;
}

bool UIButtonTimer::getTimerActivation(){
	status->isActivated();
}

/* UIButtonTimer Functions */
void UIButtonTimer::setTimerActivation(bool tof){
	status->setActivation(tof);
}

// Ticks and Render

//Updates the state of button
void UIButtonTimer::updateState(sf::Window* window){
    this->clicked = false;
    if( (!(sf::Mouse::isButtonPressed(sf::Mouse::Left))) && this->state == ACTIVE) {

		// If the mouse is no longer pressed and it was pressed, then we clicked
		this->clicked = true;
	}
	if(clickable)
    	this->state = IDLE;

    sf::Vector2i mousePosInt = sf::Mouse::getPosition(*window);
	sf::Vector2f mousePosFloat = static_cast<sf::Vector2f>(mousePosInt);

	// Hover
	if(this->bounds.getGlobalBounds().contains(mousePosFloat)){
        this->state = HOVER;

		// Pressed
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            clickable = false;//idk yet
			if (!clickable)
				this->state = ACTIVE;
		}
		if(status->isDone()){
			clickable = true;
		}
    }

}
// Renders the button
void UIButtonTimer::renderButton(sf::RenderTarget* target){
	sf::RectangleShape rect;

	// Set color
	switch(this->state) {
		case IDLE:
			rect.setFillColor(sf::Color::Transparent);
			rect.setOutlineColor(this->colors["accentIdleColor"]);
			break;
		case HOVER:
			rect.setFillColor(this->colors["hoverColor"]);
			rect.setOutlineColor(this->colors["accentHoverColor"]);
			break;
		case ACTIVE:
			rect.setFillColor(sf::Color::Transparent);
			rect.setOutlineColor(this->colors["accentActiveColor"]);
			break;
	}
	rect.setOutlineThickness(this->thickness);
	rect.setSize(sf::Vector2f(this->width-2*this->thickness, this->height-2*this->thickness));
	rect.setPosition(this->x+this->thickness, this->y+this->thickness);

	target->draw(rect);
}

//renders the starBar (Note: colors not working, but functionality seems to be??)
void UIButtonTimer::renderStatbar(sf::RenderTarget* target){
	switch(this->state) {
		case IDLE:
			status->setStatBarColor(this->colors["idleColor"]);
			break;
		case HOVER:
			status->setStatBarColor(this->colors["hoverColor"]);
			break;
		case ACTIVE:
			status->setStatBarColor(this->colors["activeColor"]);
			break;
	}

	status->render(target);
}

// Main tick
void UIButtonTimer::tick(const float& dt, sf::Window* window){
	UIButton::updateBounds();
	UIButton::updateState(window);
	status->tick(dt, window);
}

//Main Render
void UIButtonTimer::render(sf::RenderTarget* target){
	this->renderStatbar(target);

	this->renderButton(target);
	if(this->text.getString() != "") {
		this->renderText(target);
	}

	// If you want to debug collission detection
	//UIButton::renderBounds(target);
}
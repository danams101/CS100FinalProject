#include "../stdafx.h"
#include "State.h"

/* Constructors/Destructors */
State::State(GlobalData* global_data) {
	this->globalData = global_data;

	this->quit = false;
	this->paused = false;
}

State::~State() {

}

/* Accessors */
const bool& State::getQuit() const {
	return this->quit;
}

bool State::getKeyDelay() {
	if(this->keytime >= this->keytimeMax) {
		this->keytime = 0;
		return true;
	}
	return false;
}

/* Functions */

// Set quit to true
void State::endState() {
    /* Setting quit to true */
	this->quit = true;
}

// Set pause to true
void State::pauseState() {
    /* Setting pause to true */
	this->paused = true;
}

// Set pause to false
void State::unpauseState() {
    /* Setting pause to false */
	this->paused = false;
}

// Ticks and Render

// Set key time
void State::updateKeyTime(const float& dt) {
	if(this->keytime < this->keytimeMax)
		this->keytime += dt;
}

// Shows the position of the mouse for debugging
void State::renderMousePos() {
	/* NEED TO CLEAN THIS UP LATER */
	sf::Text mouseText;
	sf::Vector2i mousePosInt = sf::Mouse::getPosition(*this->globalData->window);
	mouseText.setPosition(mousePosInt.x, mousePosInt.y - 50);
	sf::Font font;
	font.loadFromFile("res/fonts/UbuntuMono-R.ttf");
	mouseText.setFont(font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << mousePosInt.x << " " << mousePosInt.y;
	mouseText.setString(ss.str());
	this->globalData->window->draw(mouseText);
}

#include "../stdafx.h"
#include "State.h"

// Constructors/Destructors
State::State(GlobalData* global_data) {
	this->globalData = global_data;

	this->quit = false;
	this->paused = false;
}

State::~State() {

}

// Accessors
const bool & State::getQuit() const {
	return this->quit;
}

// Functions

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

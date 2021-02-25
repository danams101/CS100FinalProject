#include "../stdafx.h"
#include "UIButton.h"

/* Constructors/Destructors */
UIButton::UIButton(float x, float y, float width, float height, std::map<std::string, sf::Color> colors, float thickness,
		std::string text, int textSize, sf::Font* font, bool centered) : UIObject(x, y, width, height) {

	this->state = IDLE;
	this->colors = colors;
	this->centered = centered;
	this->thickness = thickness;

	// If has text, add text
	if(text != "") {
		this->font = font;

		this->text.setString(text);
		this->text.setCharacterSize(textSize);
		this->text.setFont(*this->font);

		// If centered, center text
		if(this->centered) {
			float xPos = x + ((this->bounds.getLocalBounds().width - this->text.getLocalBounds().width)/2);
			float yPos = y + ((this->bounds.getLocalBounds().height - this->text.getLocalBounds().height)/2)
			- (this->text.getLocalBounds().height/4);
			this->text.setPosition({xPos, yPos});
		}
	}
}

UIButton::~UIButton() {

}

/* Accessors */

bool UIButton::isCentered() {
	return this->centered;
}

bool UIButton::isHovered() {
	if(this->state == HOVER)
		return true;
	return false;
}

bool UIButton::isActive() {
	if(this->state == ACTIVE)
		return true;
	return false;
}

bool UIButton::isClicked() {
	return clicked;
}

std::string UIButton::getText() {
	return this->text.getString();
}

/* Functions */

void UIButton::setState(std::string state) {

    this->state = IDLE;

    if(state == "idle")
        this->state = IDLE;
    if(state == "hover")
        this->state = HOVER;
    if(state == "active")
        this->state = ACTIVE;
}

void UIButton::setText(std::string text) {
	this->text.setString(text);
}

void UIButton::setThickness(float thickness) {
	this->thickness = thickness;
}

void UIButton::setColor(std::string colorName, sf::Color color) {
	this->colors[colorName] = color;
}

void UIButton::setColors(std::map<std::string, sf::Color> colors) {
	this->colors = colors;
}

void UIButton::setFont(sf::Font* font) {
	this->font = font;
}

// Sets position of button
void UIButton::setPosition(float x, float y){
    /* Sets position of the button and centers the text within the button. */

    this->bounds.setPosition(sf::Vector2f(x, y));

    if(this->centered) {
		float xPos = x + ((this->bounds.getLocalBounds().width - this->text.getLocalBounds().width)/2);
		float yPos = y + ((this->bounds.getLocalBounds().height - this->text.getLocalBounds().height)/2)
		- (this->text.getLocalBounds().height/4);
		this->text.setPosition({xPos, yPos});
	}
}

// Ticks and Render

// Updates the state of the button
void UIButton::updateState(sf::Window* window) {
	/* Updates the state for hover and pressed */

	this->clicked = false;

	// Clicked
	if( (!(sf::Mouse::isButtonPressed(sf::Mouse::Left))) && this->state == ACTIVE) {

		// If the mouse is no longer pressed and it was pressed, then we clicked
		this->clicked = true;
	}
	
	// Idle
	this->state = IDLE;

	sf::Vector2i mousePosInt = sf::Mouse::getPosition(*window);
	sf::Vector2f mousePosFloat = static_cast<sf::Vector2f>(mousePosInt);

	// Hover
	if(this->bounds.getGlobalBounds().contains(mousePosFloat)){
        this->state = HOVER;

		// Pressed
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->state = ACTIVE;
		}
    }
}

// Render the button
void UIButton::renderButton(sf::RenderTarget* target) {
	sf::RectangleShape rect;

	// Set color
	switch(this->state) {
		case IDLE:
			rect.setFillColor(this->colors["idleColor"]);
			rect.setOutlineColor(this->colors["accentIdleColor"]);
			break;
		case HOVER:
			rect.setFillColor(this->colors["hoverColor"]);
			rect.setOutlineColor(this->colors["accentHoverColor"]);
			break;
		case ACTIVE:
			rect.setFillColor(this->colors["activeColor"]);
			rect.setOutlineColor(this->colors["accentActiveColor"]);
			break;
	}
	rect.setOutlineThickness(this->thickness);
	rect.setSize(sf::Vector2f(this->width-2*this->thickness, this->height-2*this->thickness));
	rect.setPosition(this->x+this->thickness, this->y+this->thickness);

	target->draw(rect);
}

void UIButton::renderText(sf::RenderTarget* target) {

	// Set color
	switch(this->state) {
		case IDLE:
			this->text.setFillColor(this->colors["textIdleColor"]);
			break;
		case HOVER:
			this->text.setFillColor(this->colors["textHoverColor"]);
			break;
		case ACTIVE:
			this->text.setFillColor(this->colors["textActiveColor"]);
			break;
	}

	target->draw(this->text);
}

// Main tick function
void UIButton::tick(const float& dt, sf::Window* window) {
	UIButton::updateBounds();
	UIButton::updateState(window);
}

// Main render function
void UIButton::render(sf::RenderTarget* target) {
	this->renderButton(target);
	if(this->text.getString() != "") {
		this->renderText(target);
	}

	// If you want to debug collission detection
	UIButton::renderBounds(target);
}

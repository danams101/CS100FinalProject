#include "../stdafx.h"
#include "UIObject.h"

// Constructors/Destructors
UIObject::UIObject(float x, float y) {
	this->x = x;
	this->y = y;
}
UIObject::UIObject(float x, float y, float width, float height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	this->bounds.setSize(sf::Vector2f(width, height));
	this->bounds.setPosition(x, y);
}

UIObject::~UIObject() {
}

// Accessors

float UIObject::getX() {
	return this->x;
}

float UIObject::getY() {
	return this->y;
}

float UIObject::getWidth() {
	return this->width;
}

float UIObject::getHeight() {
	return this->height;
}

// Functions

void UIObject::setPosition(float x, float y) {
	this->x = x;
	this->y = y;
}

void UIObject::setSize(float width, float height) {
	this->width = width;
	this->height = height;
}

// Updates the bounds rectangle to the UIObject's pos and size
void UIObject::updateBounds() {
	this->bounds.setSize(sf::Vector2f(this->width, this->height));
	this->bounds.setPosition(this->x, this->y);
}

// Renders the bounds for debugging (such as collision detection)
void UIObject::renderBounds(sf::RenderTarget* target) {
	this->bounds.setOutlineThickness(1);
	
	this->bounds.setFillColor(sf::Color::Transparent);
	this->bounds.setOutlineColor(sf::Color::Red);
	
	// Need to adjust the bound size due to outline problem
	this->bounds.setSize(sf::Vector2f(this->width-2, this->height-2));
	this->bounds.setPosition(this->x+1, this->y+1);
	
	target->draw(this->bounds);
	
	// Reset the bounds size after displaying
	this->updateBounds();
}

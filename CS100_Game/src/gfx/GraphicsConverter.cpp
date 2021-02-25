#include "../stdafx.h"
#include "GraphicsConverter.h"

/* Constructors/Destructors */
GraphicsConverter::GraphicsConverter(sf::VideoMode& vm) {
	this->resolution = vm;
}

GraphicsConverter::GraphicsConverter::~GraphicsConverter() {
}

/* Functions */

float GraphicsConverter::getX(float percentage) {
	/*
	 * Converts a percentage value to pixels relative to the current resolution in the x-axis.
	 *
	 * @param		float perc				The percentage value.
	 * @param		sf::VideoMode& vm		The current videomode of the window (resolution).
	 *
	 * @return		float					The calculated pixel value.
	 */

	return std::floor(static_cast<float>(this->resolution.width) * (percentage / 100.f));
}

float GraphicsConverter::getY(float percentage) {
	/*
	 * Converts a percentage value to pixels relative to the current resolution in the x-axis.
	 *
	 * @param		float perc				The percentage value.
	 * @param		sf::VideoMode& vm		The current videomode of the window (resolution).
	 *
	 * @return		float					The calculated pixel value.
	 */

	return std::floor(static_cast<float>(this->resolution.height) * (percentage / 100.f));
}

int GraphicsConverter::getCharSize(int modifier) {
	/*
	 * Calculates the character size for text using the current resolution and a constant.
	 *
	 * @param		sf::VideoMode& vm		The current videomode of the window (resolution).
	 * @param		unsigned modifier		Used to modify the character size in a more custom way.
	 *
	 * @return		unsigned				The calculated character size value.
	 */

	return static_cast<unsigned>((this->resolution.width + this->resolution.height) / modifier);
}

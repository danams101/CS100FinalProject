#ifndef GRAPHICSCONVERTER_H
#define GRAPHICSCONVERTER_H

class GraphicsConverter {

    public:
        GraphicsConverter(sf::VideoMode& vm);
		virtual ~GraphicsConverter();

        /* Variables */
        sf::VideoMode resolution;
        // bool fullscreen;
        // bool verticalSync;
        // sf::ContextSettings contextSettings;
        // std::vector<sf::VideoMode> videoModes;

        /* Functions */
        float getX(float percentage);
		float getY(float percentage);
		int getCharSize(int modifier);
};

#endif // GRAPHICSCONVERT_H

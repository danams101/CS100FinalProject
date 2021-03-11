#ifndef UITEXT_HPP
#define UITEXT_HPP

#include "SFML/Graphics.hpp"

#include <iostream>

class uiText {
    private:
        sf::Text t;


    public:
        uiText(int size, sf::Color color, const std::string& text, sf::Font& font, sf::Vector2f pos){
            t.setCharacterSize(size);
            t.setFillColor(color);
            t.setString(text);
            t.setFont(font);
            t.setPosition(pos);
        }

        sf::Color getColor(){
            return t.getFillColor();
        }

        std::string getString(){
            return t.getString();
        }

        void move(float x, float y){
            t.move(x, y);
        }

        void setPosition(sf::Vector2f pos){
            t.setPosition(pos);
        }

        void setColor(sf::Color color){
            t.setFillColor(color);
        }

        void render(sf::RenderTarget* target){
            target->draw(t);
        }

};

#endif 
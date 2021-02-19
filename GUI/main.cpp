#include <SFML/Graphics.hpp>
#include <iostream>

#include "UIObject.hpp"
#include "UIObjectComposite.hpp"
#include "UIButton.hpp"

int main() {
    // Create the window using a sf::RenderWindow and set frame rate and position.
    // Note: The size and position go by pixels, so a different res moniter would look different.
    // TODO: make a window that would change its size based on screen res.

    sf::RenderWindow window(sf::VideoMode(800, 600), "Exo-Ventures");

    window.setFramerateLimit(60);

    window.setPosition(sf::Vector2i(500,50));

    //Load in fonts
    

    //load background textures

    //create objects
    UIObjectComposite* comp = new UIObjectComposite();
    UIObject* b1 = new UIButton(sf::Vector2f(100, 50), sf::Color::Green, sf::Vector2f(100,100));
    UIObject* b2 = new UIButton(sf::Vector2f(75, 25), sf::Color::White, sf::Vector2f(110,110));
    UIObject* b3 = new UIButton(sf::Vector2f(36, 12), sf::Color::Blue, sf::Vector2f(120,120));

    comp->Add(b3);
    comp->Add(b2);
    comp->Add(b1);
    

    //Game loop

    while(window.isOpen()){
        //check events

        sf::Event event;

        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();

                //other cases; mouse moved, button clicked, etc.
                //Note: most of this would go in the state classes
            }

            
        }

        //clear window with color(or picture) every frame
        window.clear(sf::Color::Black);

        //draw things here
        comp->drawTo(window);

        //display every frame
        window.display();
    }

    return 0;
}
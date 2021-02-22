#include <SFML/Graphics.hpp>
#include <iostream>

#include "UIObject.hpp"
#include "UIObjectComposite.hpp"
#include "UIButton.hpp"
#include "UITextbox.hpp"

int main() {
    // Create the window using a sf::RenderWindow and set frame rate and position.
    // Note: The size and position go by pixels, so a different res moniter would look different.
    // TODO: make a window that would change its size based on screen res.

    sf::RenderWindow window(sf::VideoMode(800, 600), "Exo-Ventures");

    window.setFramerateLimit(60);

    window.setPosition(sf::Vector2i(500,50));

    //Load in fonts
    sf::Font font;
    if(!font.loadFromFile("UbuntuMono-R.ttf")){
        //error
    }

    //load background textures

    //create objects
    UIObjectComposite* comp = new UIObjectComposite();
    UIButton* b1 = new UIButton("hi", 24, sf::Vector2f(100, 50), sf::Color::Black, sf::Color::Green);
    UIButton* b2 = new UIButton("CLICK", 24, sf::Vector2f(100, 50), sf::Color::Black, sf::Color::Green);
    //UIObject* b3 = new UIButton(sf::Vector2f(36, 12), sf::Color::Blue, sf::Vector2f(120,120));
    UITextbox* t = new UITextbox(24, sf::Color::Green, false, 16);

    b1->setFont(font);
    b2->setFont(font);
    t->setFont(font);

    b1->setPosition(sf::Vector2f(100,100));
    b2->setPosition(sf::Vector2f(210,100));
    t->setPosition(sf::Vector2f(100,200));

    //comp->Add(b3);
    comp->Add(b2);
    comp->Add(b1);
    comp->Add(t);
    

    //Game loop

    while(window.isOpen()){
        //check events

        sf::Event event;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)){
            t->setSelection(true);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
            t->setSelection(false);
        }

        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::TextEntered:
                    t->typedOn(event);
                
                case sf::Event::MouseMoved:
                    b2->highlightBehavior(window);
                    b1->highlightBehavior(window);
                    break;

                //other cases; mouse moved, button clicked, etc.
                //Note: most of this would go in the state classes
            }

            
        }

        //clear window with color(or picture) every frame
        window.clear(sf::Color::Black);

        //draw things here
        comp->drawTo(window);
        // b1->drawTo(window);
        // b2->drawTo(window);

        //display every frame
        window.display();
    }

    return 0;
}
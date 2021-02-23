#include "UIObjectComposite.hpp"

UIObjectComposite::UIObjectComposite(){

}

UIObjectComposite::~UIObjectComposite(){
    for(auto const& it : objects){
        delete it;
    }
    objects.clear();
}

// Adds object to composite
void UIObjectComposite::Add(UIObject* obj) {
    objects.push_front(obj);
}

// Removes object from composite
void UIObjectComposite::Remove(UIObject* obj) {
    if(objects.size() > 0){
        objects.remove(obj);
    }
}

//Draws all objects in composite to window.
void UIObjectComposite::drawTo(sf::RenderWindow& window) {
    for(auto const& it : objects){
        it->drawTo(window);
    }
}
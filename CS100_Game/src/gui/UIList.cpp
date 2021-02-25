#include "UIList.hpp"

UIList::UIList(){

}

UIList::~UIList(){
    for(auto const& it : objects){
        delete it;
    }
    objects.clear();
}

// Adds object to composite
void UIList::Add(UIObject* obj) {
    objects.push_front(obj);
}

// Removes object from composite
void UIList::Remove(UIObject* obj) {
    if(objects.size() > 0){
        objects.remove(obj);
    }
}

//Draws all objects in composite to window.
void UIList::render(sf::RenderWindow& window) {
    for(auto const& it : objects){
        it->render(window);
    }
}
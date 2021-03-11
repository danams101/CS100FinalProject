#include "../stdafx.h"
#include "UIList.h"

/* Constructors/Destructors */
UIList::UIList() : UIObject(0, 0) {

}

UIList::~UIList(){
    for(auto it : this->objects){
        delete it;
    }
    this->objects.clear();
}

/* Functions */

// Adds object to list
void UIList::add(UIObject* obj) {
    this->objects.push_front(obj);
}

// Removes object from list
void UIList::remove(UIObject* obj) {
    if(this->objects.size() > 0){
        this->objects.remove(obj);
    }
}

void UIList::pushBack(UIObject* obj){
    this->objects.push_back(obj);
}

void UIList::popBack(){
    if(this->objects.size()>0){
        this->objects.pop_back();
    }
}

// Main tick function TODO?
void UIList::tick(const float& dt, sf::Window* window) {
	for(auto const& it : this->objects){
        it->tick(dt, window);
    }
}

//Main render function
void UIList::render(sf::RenderTarget* target) {
    for(auto const& it : this->objects){
        it->render(target);
    }
}

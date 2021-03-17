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

UIObject* UIList::GetObject(int objNum){
    int index = 0;
    UIObject* obj = nullptr;
    for(auto const& it : this->objects){
        if(index == objNum){
            obj = it;
        }
        ++index;
    }

    if(obj == nullptr){
        std::cout<<"NO SUCH OBJECT EXISTS" << std::endl;
    }
    return obj;
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


/*  UIButtonList */
/* Constructors/Destructors */
UIButtonList::UIButtonList() : UIList() {

}

UIButtonList::~UIButtonList(){
    for(auto it : this->buttons){
        delete it;
    }
    this->buttons.clear();
}

/* Functions */

// Adds object to list
void UIButtonList::add(UIButton* obj) {
    this->buttons.push_front(obj);
}

// Removes object from list
void UIButtonList::remove(UIButton* obj) {
    if(this->buttons.size() > 0){
        this->buttons.remove(obj);
    }
}

void UIButtonList::pushBack(UIButton* obj){
    this->buttons.push_back(obj);
}

void UIButtonList::popBack(){
    if(this->buttons.size()>0){
        this->buttons.pop_back();
    }
}

UIButton* UIButtonList::GetButton(int buttonNum){
    if(!this->buttons.empty()){
        int index = 0;
        UIButton* button = nullptr;
        for(auto it : this->buttons){
            if(index == buttonNum){
                button = it;
            }
            ++index;
        }

        if(button == nullptr){
            std::cout<<"NO SUCH OBJECT EXISTS" << std::endl;
        }
        return button;
    }
}



// Main tick function TODO?
void UIButtonList::tick(const float& dt, sf::Window* window) {
	for(auto const& it : this->buttons){
        it->tick(dt, window);
    }
}

//Main render function
void UIButtonList::render(sf::RenderTarget* target) {
    for(auto const& it : this->buttons){
        it->render(target);
    }
}
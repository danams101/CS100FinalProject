#include "UIObjectComposite.hpp"

UIObjectComposite::UIObjectComposite(){

}

UIObjectComposite::~UIObjectComposite(){
    for(auto const& it : objects){
        delete it;
    }
    objects.clear();
}

void UIObjectComposite::Add(UIObject* obj) {
    objects.push_front(obj);
}

void UIObjectComposite::Remove(UIObject* obj) {
    if(objects.size() > 0){
        objects.remove(obj);
    }
}

// UIObject* UIObjectComposite::GetChild(int objNum) {

// }

void UIObjectComposite::drawTo(sf::RenderWindow& window) {
    for(auto const& it : objects){
        it->drawTo(window);
    }
}
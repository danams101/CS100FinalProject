#ifndef _UIOBJECTCOMPOSITE_HPP_
#define _UIOBJECTCOMPOSITE_HPP_

#include "UIObject.hpp"
#include <list>

class UIObjectComposite : public UIObject{
    public:
        UIObjectComposite();

        virtual ~UIObjectComposite();

        virtual void Add(UIObject* obj);
        virtual void Remove(UIObject* obj);
        //virtual UIObject* GetChild(int objNum);

        virtual void drawTo(sf::RenderWindow& window);

    private:
        std::list<UIObject*> objects;

};

#endif //_UIOBJECTCOMPOSITE_HPP_
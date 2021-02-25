#ifndef _UIList_HPP_
#define _UIList_HPP_

#include "UIObject.hpp"
#include <list>

class UIList : public UIObject{
    public:
        //Constructor
        UIList();

        //Destructor
        virtual ~UIList();

        //Virtual functions
        virtual void add(UIObject* obj);
        virtual void remove(UIObject* obj);

        //Note: We might need a method to access object in a composite later.
        //virtual UIObject* GetChild(int objNum);

        virtual void render(sf::RenderWindow& window);

    private:
        std::list<UIObject*> objects;

};

#endif //_UIOBJECTCOMPOSITE_HPP_
#ifndef _UIOBJECT_HPP_
#define _UIOBJECT_HPP_

#include <SFML/Graphics.hpp>
//#include <list>
#include <vector>

class UIObject {
    public:

        //UIObject(){}

        virtual ~UIObject(){}

        //composite implement
        virtual void Add(UIObject* obj) {}
        virtual void Remove(UIObject* obj) {}
        //virtual UIObject* GetChild(int objNum) {}
        //virtual std::iterator<UIObject*>* CreateIterator();

        //Leaf and coomposite implement
        virtual void drawTo(sf::RenderWindow& window) = 0;

    private:
        //not sure of private variables yet
};

#endif //_UIOBJECT_HPP_
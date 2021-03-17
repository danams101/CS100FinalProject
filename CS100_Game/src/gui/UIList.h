#ifndef _UIList_H_
#define _UIList_H_

#include "UIObject.h"
#include "UIButton.h"

class UIList : public UIObject{
	protected:
        std::list<UIObject*> objects;
	
    public:
        UIList();
        virtual ~UIList();

		/* Functions */
        void add(UIObject* obj);
        void remove(UIObject* obj);

        void pushBack(UIObject* obj);
        void popBack();

        //Might need to add an iterator in order to incorperate the guiText class into the UIObject tree.

        // Note: We might need a method to access object in a composite later.
        UIObject* GetObject(int objNum);

		// Virtual function from UIObject class
		void tick(const float& dt, sf::Window* window);
        void render(sf::RenderTarget* target);
};



//uiButtonList maybe
class UIButtonList : public UIList{
	protected:
        std::list<UIButton*> buttons;
        //std::map<std::string, UIButton*> buttonMap;
	
    public:
        UIButtonList();
        virtual ~UIButtonList();

		/* Functions */
        void add(UIButton* obj);
        void remove(UIButton* obj);

        void pushBack(UIButton* obj);
        void popBack();

        //Might need to add an iterator in order to incorperate the guiText class into the UIObject tree.

        // Note: We might need a method to access object in a composite later.
        UIButton* GetButton(int buttonNum);

		// Virtual function from UIObject class
		void tick(const float& dt, sf::Window* window);
        void render(sf::RenderTarget* target);
};


#endif //_UIList_H_
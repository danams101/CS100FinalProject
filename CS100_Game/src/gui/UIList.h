#ifndef _UIList_H_
#define _UIList_H_

#include "UIObject.h"

class UIList : public UIObject{
	private:
        std::list<UIObject*> objects;
	
    public:
        UIList();
        virtual ~UIList();

		/* Functions */
        void add(UIObject* obj);
        void remove(UIObject* obj);

        // Note: We might need a method to access object in a composite later.
        // virtual UIObject* GetChild(int objNum);

		// Virtual function from UIObject class
		void tick(const float& dt, sf::Window* window);
        void render(sf::RenderTarget* target);
};

#endif //_UIList_H_
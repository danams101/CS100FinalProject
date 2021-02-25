#ifndef _UIOBJECT_H_
#define _UIOBJECT_H_

class UIObject {
    
	protected:
		float x, y;
		float width, height;
		
		sf::RectangleShape bounds;
	
	public:
        UIObject(float x, float y);
		UIObject(float x, float y, float width, float height);
        virtual ~UIObject();
		
		/* Accessors */
		float getX();
		float getY();
		float getWidth();
		float getHeight();
		
        /* Functions */
		void setPosition(float x, float y);
		void setSize(float width, float height);

		// Ticks and render
		void updateBounds();
		void renderBounds(sf::RenderTarget* target);
	
		//composite implement
		virtual void tick(const float& dt, sf::Window* window) = 0;
        virtual void render(sf::RenderTarget* target) = 0;

};

#endif //_UIOBJECT_H_
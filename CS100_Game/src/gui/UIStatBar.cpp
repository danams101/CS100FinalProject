#include "UIStatBar.h"

/* Constructors/Destructors */
UIStatBar::UIStatBar(float x, float y, float width, float height, std::map<std::string, sf::Color> colors, float duration, bool activated)
 : UIObject(x, y, width, height) {
    /*
    Initialized the barLength and timer as well.
    */

    bar.setSize(sf::Vector2f(width, height));
    //barLength = barSize.x;
    //isActivated = active;

    this->activated = activated;
    this->barLength = width;
    this->timerDuration = duration;
    
    timer = 0.f;
    
    this->colors = colors;
}

UIStatBar::~UIStatBar(){

}

/* Accessors */

bool UIStatBar::isActivated(){
    return this->activated;
}
float UIStatBar::getTimerDuration(){
    return this->timerDuration;
}
float UIStatBar::getBarLength(){
    return this->barLength;
}
// Function to return progress, might need it later.
float UIStatBar::getProgress(){
    /*  
    Returns the width of the bar which signifies the progress. 
    Note: We can change this to a percentage or different value type later if need be.
    */
    return bar.getSize().x;
}

/* Functions */

// Sets if the timer should start/stop.
void UIStatBar::setActivation(bool activated){
    this->activated = activated;
}
// Sets color of bar.
void UIStatBar::setColor(std::string colorName, sf::Color color){
    this->colors[colorName] = color;
}

void UIStatBar::setColors(std::map<std::string, sf::Color> colors) {
	this->colors = colors;
}

// Sets bar position.
void UIStatBar::setPosition(float x, float y){
    this->bounds.setPosition(sf::Vector2f(x,y));

}
void UIStatBar::setSize(float width, float height){

}

// Ticks and Render

// Implements timer behavior.
void UIStatBar::updateProgress(const float& dt){
    /*
    Uses timeDuration to calculate speed of progress bar.

    EX:
        duration =10 sec
        bar.size.x = 100 pixels
        -> 1 px per 0.1 sec

        duration = 45 sec
        bar.size.x = 100 pixels
        -> 1 px/0.45 sec
    */
   float initialBarSize = barLength;
   float timeInterval = timerDuration / barLength;
    
    
    if (activated){
        //time between frames
        //sf::Time dt = clock.restart();

        //keeps track of time, so the bar updates by 1 pixel per time interval
        timer += dt;
        
        if(timer>timeInterval && bar.getSize().x>0){
            bar.setSize({bar.getSize().x - 1, bar.getSize().y});
            timer = 0;
        }
    }
}


// Render the StatBar
void UIStatBar::renderStatBar(sf::RenderTarget* target){
    bar.setFillColor(this->colors["idleColor"]);
    //bar.setSize(sf::Vector2f(this->width, this->height));
    bar.setPosition(this->x, this->y);

    target->draw(bar);
}

void UIStatBar::tick(const float& dt, sf::Window* window){
    updateBounds(); //UIButton:: ???
    updateProgress(dt);
}

void UIStatBar::render(sf::RenderTarget* target){
    renderStatBar(target);

    renderBounds(target);
}
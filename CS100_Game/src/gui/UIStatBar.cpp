#include "UIStatBar.h"

/* Constructors/Destructors */
UIStatBar::UIStatBar(float x, float y, float width, float height, std::map<std::string, sf::Color> colors, float duration, bool activated)
 : UIObject(x, y, width, height) {
    /*
    Initialized the barLength and timer as well.
    */

    bar.setSize(sf::Vector2f(width, height));

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
bool UIStatBar::isDone(){
    return done;
}

float UIStatBar::getTimerDuration(){
    return this->timerDuration;
}
float UIStatBar::getBarLength(){
    return this->barLength;
}

/* Functions */

// Sets if the timer should start/stop.
void UIStatBar::setActivation(bool activated){
    this->activated = activated;
}
void UIStatBar::setColor(std::string colorName, sf::Color color){
    this->colors[colorName] = color;
}

void UIStatBar::setColors(std::map<std::string, sf::Color> colors) {
	this->colors = colors;
}

// Sets color of bar.
void UIStatBar::setStatBarColor(sf::Color color){
    bar.setFillColor(color);
}

// Resets bar to original size
void UIStatBar::resetBar(){
    bar.setSize(sf::Vector2f(this->width, this->height));
    this->activated = false;
    done = false;
    this->barLength = this->width;
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
        //keeps track of time, so the bar updates by 1 pixel per time interval
        timer += dt;
        
        if(timer>timeInterval && bar.getSize().x>0){
            bar.setSize({bar.getSize().x - 1, bar.getSize().y});
            timer = 0;
        }
        //To check if the timer is done, and needs to be reset.
        if(bar.getSize().x <= 0){
            done = true;
            activated = false;
            resetBar();
        }
    }
}


// Render the StatBar
void UIStatBar::renderStatBar(sf::RenderTarget* target){
    bar.setFillColor(this->colors["idleColor"]);
    bar.setPosition(this->x, this->y);

    target->draw(bar);
}

void UIStatBar::tick(const float& dt, sf::Window* window){
    updateBounds();
    updateProgress(dt);
}

void UIStatBar::render(sf::RenderTarget* target){
    renderStatBar(target);

    //renderBounds(target);
}
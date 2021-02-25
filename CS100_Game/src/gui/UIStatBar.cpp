#include "UIStatBar.hpp"

// Sets bar size, active or not, timer duration.
UIStatBar::UIStatBar(sf::Vector2f barSize, bool active, float duration){
    /*
    Initialized the barLength and timer as well.
    */

    bar.setSize(barSize);
    barLength = barSize.x;
    isActivated = active;
    
    timer = 0.f;
    timerDuration = duration;
}

// Sets color of bar.
void UIStatBar::setColor(sf::Color color){
    bar.setFillColor(color);
}

// Sets bar position.
void UIStatBar::setPosition(sf::Vector2f pos){
    bar.setPosition(pos);
}

// Sets if the timer should start/stop.
void UIStatBar::setActivation(bool active){
    isActivated = active;
}

// Implements timer behavior.
void UIStatBar::updateProgress(){
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
    
    
    if (isActivated){
        //time between frames
        sf::Time dt = clock.restart();

        //keeps track of time, so the bar updates by 1 pixel per time interval
        timer += dt.asSeconds();
        
        if(timer>timeInterval && bar.getSize().x>0){
            bar.setSize({bar.getSize().x - 1, bar.getSize().y});
            timer = 0;
        }
    }
}

// Returns progress of bar.
float UIStatBar::getProgress(){
    /*  
    Returns the width of the bar which signifies the progress. 
    Note: We can change this to a percentage or different value type later if need be.
    */
    return bar.getSize().x;
}

// Draws object to window.
void UIStatBar::drawTo(sf::RenderWindow& window){
    /* 
    Calls updateProgress for the bar, then draws each frame.
    */
    updateProgress();
    window.draw(bar);
}

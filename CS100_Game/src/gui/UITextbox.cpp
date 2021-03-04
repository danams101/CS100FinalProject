#include "UITextbox.h"

// Sets text size, the color of text, default selection (if the user can type in it),
// and the charater limit.
UITextbox::UITextbox(float x, float y, std::map<std::string, sf::Color> colors, int textSize, sf::Font* font, bool selected, int limit)
 : UIObject(x, y, width, height){
    /*
    Initializes everything.
    A selected textbox is indicated by an underscore appearing.
    Note: A textbox is selected by pressing TAB.
          and deselected by pressing ENTER.
          This is implemented in main, might make that a function later.
    */

    this->colors = colors;
    this->font = font;
    this->selected = selected;
    this->limit = limit;

    textbox.setCharacterSize(textSize);
    textbox.setFont(*this->font);

    //textbox.setFillColor(sf::Color(10,230,10));

    if(selected){
        textbox.setString("_");
    }
    else{
        textbox.setString("");
    }
}

UITextbox::~UITextbox(){

}

/* Accessors */

bool UITextbox::isSelected(){
    return this->selected;
}

int UITextbox::getCharLimit(){
    return this->limit;
}

std::string UITextbox::getText(){
    return ss.str();
}

//Sets whether a textbox is selected.
void UITextbox::setSelected(bool ToF){
    /*
    If the textbox is not selected/unselected, the string is saved.
    */
    
    selected = ToF;
    if(!selected){
        std::string s = "";
        for(int i = 0; i < ss.str().length(); ++i){
            s += ss.str()[i];
        }
        textbox.setString(s);
    }
}

void UITextbox::setTextColor(sf::Color color){
    textbox.setFillColor(color);
}

void UITextbox::setColor(std::string colorName, sf::Color color){
    this->colors[colorName] = color;
}

void UITextbox::setColors(std::map<std::string, sf::Color> colors){
    this->colors = colors;
}

void UITextbox::setFont(sf::Font* font){
    textbox.setFont(*this->font);
}

//Controls behavior of textbox when the user types in it.
void UITextbox::typedOn(sf::Event textEntered){
    /*
    Activates if the textbox is selected.

    Takes in an SFML event (sf::Event::TextEntered), uses this event to grab the 
    characters the user entered in unicode. 
    Checks if the charaters are valid. ( <128 ), calls private InputLogic function.
    Checks if character limit is reached, if it is only allows delete behavior (backspace()).
    */
    if(selected){
        int charTypedValue = textEntered.text.unicode;

        //valid characters
        if(charTypedValue < 128){
            if(ss.str().length() < limit){
                InputLogic(charTypedValue);
            }
            else if(ss.str().length()>=limit && charTypedValue == DELETE_KEY){
                backspace();
            }
        }
    }
}


//Sets position
void UITextbox::setPosition(float x, float y){
    this->bounds.setPosition(sf::Vector2f(x,y));
}

// Ticks and Render
void UITextbox::updateSelected(sf::Window* window){
    sf::Event event;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)){
        setSelected(true);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        setSelected(false);
    }
    while(window->pollEvent(event)){///???
        if(event.type == sf::Event::TextEntered){
            this->typedOn(event);
        }
    }
}

void UITextbox::renderTextbox(sf::RenderTarget* target){
    //set color

    setColor("TextColor", sf::Color(10,230,10));

    textbox.setFillColor(this->colors["TextColor"]);
    //set position
    textbox.setPosition(this->x, this->y);

    //draw
    target->draw(textbox);
}

        //Virtual function from UIObject class
void UITextbox::tick(const float& dt, sf::Window* window){
    updateSelected(window);
}
void UITextbox::render(sf::RenderTarget* target){
    renderTextbox(target);
}



//Private functions

// Handles input logic for typedOn function.
void UITextbox::InputLogic(int charTypedVal){
    /*
    Checks for special key inputs, if no special keys, it outputs the char to the
    string stream ss.

    If the typed key is the delete key, call backspace function.
    */
    
    if(charTypedVal != DELETE_KEY && charTypedVal!= TAB_KEY && charTypedVal != DELETE_KEY){
        ss << static_cast<char>(charTypedVal);
    }
    else if (charTypedVal == DELETE_KEY){
        if (ss.str().length() > 0){
            backspace();
        }
    }
    textbox.setString(ss.str() + "_");
}

//Deletes the last character of the string.
void UITextbox::backspace(){
    /*
    Simple delete function.
    Copys old string to new string with one less char,
    clears string stream, outputs new string to ss.

    Sets the textbox's string to the new ss.str().
    */

    std::string origS = ss.str();
    std::string newS = "";

    for(int i = 0; i < origS.length()-1; ++i){
        newS += origS[i];
    }

    ss.str("");
    ss << newS;

    textbox.setString(ss.str());
}
#include "UITextbox.hpp"

// Sets text size, the color of text, default selection (if the user can type in it),
// and the charater limit.
UITextbox::UITextbox(int textSize, sf::Color color, bool isSel, int charLimit){
    /*
    Initializes everything.
    A selected textbox is indicated by an underscore appearing.
    Note: A textbox is selected by pressing TAB.
          and deselected by pressing ENTER.
          This is implemented in main, might make that a function later.
    */
    textbox.setCharacterSize(textSize);
    textbox.setFillColor(color);
    isSelected = isSel;  
    limit = charLimit; 

    if(isSelected){
        textbox.setString("_");
    }
    else{
        textbox.setString("");
    }
}

//Sets text color.
void UITextbox::setTextColor(sf::Color color){
    textbox.setFillColor(color);
}

//Sets the font, needs to be set when called.
void UITextbox::setFont(sf::Font& font){
    textbox.setFont(font);
}

//Sets position, needs to be set when called.
void UITextbox::setPosition(sf::Vector2f pos){
    textbox.setPosition(pos);
}

//Sets whether a textbox is selected.
void UITextbox::setSelection(bool ToF){
    /*
    If the textbox is not selected/unselected, the string is saved.
    */
    
    isSelected = ToF;
    if(!isSelected){
        std::string s = "";
        for(int i = 0; i < ss.str().length(); ++i){
            s += ss.str()[i];
        }
        textbox.setString(s);
    }
}

//Returns string that user typed.
std::string UITextbox::getText(){
    return ss.str();
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
    if(isSelected){
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

//Draws object to window.
void UITextbox::drawTo(sf::RenderWindow& window){
    window.draw(textbox);
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
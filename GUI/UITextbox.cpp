#include "UITextbox.hpp"

UITextbox::UITextbox(int textSize, sf::Color color, bool isSel, int charLimit){
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

void UITextbox::setTextColor(sf::Color color){
    textbox.setFillColor(color);
}

void UITextbox::setFont(sf::Font& font){
    textbox.setFont(font);
}

void UITextbox::setPosition(sf::Vector2f pos){
    textbox.setPosition(pos);
}

void UITextbox::setSelection(bool ToF){
    isSelected = ToF;
    if(!isSelected){
        std::string s = "";
        for(int i = 0; i < ss.str().length(); ++i){
            s += ss.str()[i];
        }
        textbox.setString(s);
    }
}

std::string UITextbox::getText(){
    return ss.str();
}

void UITextbox::typedOn(sf::Event textEntered){
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

void UITextbox::drawTo(sf::RenderWindow& window){
    window.draw(textbox);
}

void UITextbox::InputLogic(int charTypedVal){
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

void UITextbox::backspace(){
    std::string origS = ss.str();
    std::string newS = "";

    for(int i = 0; i < origS.length()-1; ++i){
        newS += origS[i];
    }

    ss.str("");
    ss << newS;

    textbox.setString(ss.str());
}
#ifndef _LINK_HPP_
#define _LINK_HPP_

#include "../stdafx.h"
#include "../gui/guiText.hpp"
#include "../gui/UIButton.h"
//#include "node.hpp"

class Node;

class Link {
    private:
        uiText* npcName;
        uiText* npcDialogue;

        UIButton* playerChoice;

        bool chosen;

        //Node* prevNode;
        Node* nextNode; 

    public:

        /* Constructors/ Destructors */
        Link(){
            npcName = nullptr;
            npcDialogue = nullptr;
            playerChoice = nullptr;

            chosen = false;

            //prevNode = nullptr;
            nextNode = nullptr;
        }
        Link(uiText* name, uiText* dialogue, UIButton* choice, Node* nextNode = nullptr){
            npcName = name;
            npcDialogue = dialogue;
            playerChoice = choice;

            chosen = false;

            //this->prevNode = prevNode;
            this->nextNode = nextNode;
        }

        ~Link(){}


        /* Accessors */
        uiText* getNpcName(){
            return npcName;
        }

        uiText* getNpcDialogue(){
            return npcDialogue;
        }

        UIButton* getPlayerChoiceButton(){
            return playerChoice;
        }

        Node* getNextNode(){
            return nextNode;
        }

        bool isChosen(){
            return chosen;
        }

        /* Mutators */
        void setNpcName(uiText* name){
            npcName = name;
        }

        void setNpcDialogue(uiText* dialogue){
            npcDialogue = dialogue;
        }

        void setPlayerChoice(UIButton* choice){
            playerChoice = choice;
        }

        void setIsChosen(bool tof){
            chosen = tof;
        }

        // void setPreviousNode(Node* node){
        //     prevNode = node;
        // }

        void setNextNode(Node* node){
            nextNode = node;
        }

        // void setNodeNext(){
        //     prevNode->setNext(nextNode);
        // }

        /* Functions */
        void render(sf::RenderTarget* target){
            npcName->render(target);
            npcDialogue->render(target);
            if(playerChoice != nullptr){
                this->playerChoice->renderButton(target);
                this->playerChoice->renderText(target);
            }
        }
};


#endif
#ifndef _NODE_HPP_
#define _NODE_HPP_

#include "../stdafx.h"
#include <vector>
//#include "../gui/guiText.hpp"

class Link;

class Node {
    private:

        std::string id;

        Node* next;

        std::list<Link*> links;

    public:
        /* Constructors/ Destructors */
        Node(){
            this->id = "";
            this->next = nullptr;
        }
        Node(std::string id){
            this->id = id;
            this->next = nullptr;
        }
        Node(std::string id, std::list<Link*> links){
            this->id = id;
            this->next = nullptr;
            this->links = links;
        }
        ~Node(){

        }

        /* Accessors */
        std::string getID(){
            return id;
        }

        std::list<Link*> getLinks(){
            return links;
        }

        Node* getNext(){
            // Might need to add a conditional, to make sure not a nullptr but idk yet.
            return next;
        }


        /* Mutators */
        void setID(std::string id){
            this->id = id;
        }

        void setLinks(std::list<Link*> links){
            this->links = links;
        }

        void addLink(Link* link){
            this->links.push_back(link);
        }

        void removeLink(Link* link){
            if(!links.empty()){
                this->links.remove(link);
            }
        }

        void removeAllLinks(){
            
        }

        void setNext(Node* node){
            this->next = node;
        }

        /* Functions */

        // void render(sf::RenderTarget* target){

        // }

};

#endif
#include "dialogueGraph.h"

DialogueGraph::DialogueGraph(){
    activeNode = nullptr;
}

DialogueGraph::DialogueGraph(std::list<Node*> nodes){
    this->nodes = nodes;
    activeNode = nodes.front();
}

DialogueGraph::~DialogueGraph(){

}

void DialogueGraph::autoPopulateNodeListAndIDs(std::string idChar, int N){
    for (int i = 0; i < N; i++){
        std::string s = std::to_string(i);
        Node* newNode = new Node(idChar+s);
        nodes.push_back(newNode);
    }
    activeNode = nodes.front();
}

void DialogueGraph::initializeAdjecencyList(std::string id, std::list<Link*> links){
    for (auto it : nodes){
        if(it->getID() == id){
            it->setLinks(links);
        }
    }
}

void DialogueGraph::updateCurrentButtons(const float& dt){
    std::list<Link*> tempLinkList = activeNode->getLinks();

    for( auto it : tempLinkList){
        if(it->getPlayerChoiceButton()->isClicked()){
            it->setIsChosen(true);
        }
        else {
            it->setIsChosen(false);
        }
    }
}

void DialogueGraph::update(const float& dt){
    //activeNode = nodes.front();

    for(auto it : activeNode->getLinks()){
        if(it->isChosen()){
            activeNode->setNext(it->getNextNode());
        }
    }

    if(activeNode->getNext() != nullptr){
        activeNode = activeNode->getNext();
    }
}

void DialogueGraph::render(sf::RenderTarget* target){
    if (activeNode != nullptr){
        for (auto it : activeNode->getLinks()){
            it->render(target);
        }
    }
}
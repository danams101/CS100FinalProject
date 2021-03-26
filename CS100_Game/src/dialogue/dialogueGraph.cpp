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

std::list<Node*> DialogueGraph::getNodeList(){
    return this->nodes;
}

Node* DialogueGraph::getNode(std::string id){
    for (auto it : nodes){
        if(it->getID() == id){
            return it;
        }
    }
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

void DialogueGraph::addLink(Node* n1, Link* l, Node* n2){
    l->setNextNode(n2);
    n1->addLink(l);
}

void DialogueGraph::emplaceLink(Node* n1, uiText* npcName, uiText* npcDialogue, UIButton* choice, Node* n2){
    Link* link = new Link(npcName,npcDialogue, choice, n2);
    n1->addLink(link);
}

void DialogueGraph::addNode(Node* n){
    nodes.push_back(n);
}



void DialogueGraph::updateCurrentButtons(const float& dt, sf::Window* window){
    std::list<Link*> tempLinkList = activeNode->getLinks();

    for(auto it : tempLinkList){
        it->getPlayerChoiceButton()->updateState(window);
    }

    for( auto it : tempLinkList){
        if(it->getPlayerChoiceButton()->isClicked()){
            it->setIsChosen(true);
        }
        else {
            it->setIsChosen(false);
        }
    }
}

void DialogueGraph::update(){
    //activeNode = nodes.front();

    for(auto it : activeNode->getLinks()){
        if(it->isChosen()){
            activeNode->setNext(it->getNextNode());
        }
    }

    if(activeNode->getNext() != nullptr){
        activeNode = activeNode->getNext();
        //nodes.pop_front();//////
    }
}

void DialogueGraph::render(sf::RenderTarget* target){
    if (activeNode != nullptr){
        //causes segmentation fault
        //activeNode->getLinks().front()->getNpcName()->render(target);
        //activeNode->getLinks().front()->getNpcDialogue()->render(target);
        for (auto it : activeNode->getLinks()){
            it->render(target);
        }
    }
}
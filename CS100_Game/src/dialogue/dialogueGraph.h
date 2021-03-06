#ifndef _DIALOGUEGRAPH_H_
#define _DIALOGUEGRAPH_H_

#include "node.hpp"
#include "link.hpp"

// class Node;
// class Link;

class DialogueGraph {
    private:
        std::list<Node*> nodes;

        Node* activeNode;

    public:
        DialogueGraph();
        DialogueGraph(std::list<Node*> nodes);

        ~DialogueGraph();

        std::list<Node*> getNodeList();

        Node* getNode(std::string id);

        void autoPopulateNodeListAndIDs(std::string idChar, int N);

        void initializeAdjecencyList(std::string id, std::list<Link*> links);

        /////////
        void addLink(Node* n1, Link* l, Node* n2);
        void emplaceLink(Node* n1, uiText* npcName, uiText* npcDialogue, UIButton* choice, Node* n2);

        void addNode(Node* n);
        ////////

        void updateCurrentButtons(const float& dt, sf::Window* window);

        void update();
        // grabs npcName and dialogue from one of the links, renders the name and text and the Link
        void render(sf::RenderTarget* target = nullptr);
};

#endif


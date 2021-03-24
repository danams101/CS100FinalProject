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

        void autoPopulateNodeListAndIDs(std::string idChar, int N);

        void initializeAdjecencyList(std::string id, std::list<Link*> links);

        void update(const float& dt);
        // grabs npcName and dialogue from one of the links, renders the name and text and the Link
        void render(sf::RenderTarget* target = nullptr);
};

#endif


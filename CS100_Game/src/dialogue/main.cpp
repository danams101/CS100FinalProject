#include "../stdafx.h"
#include "dialogueGraph.h"
//#include "../gfx/GraphicsConverter.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    sf::Clock clock;
    float dt = clock.restart().asSeconds();

    std::map<std::string, sf::Color> debugTheme;

    debugTheme["idleColor"] = sf::Color::White;
	debugTheme["hoverColor"] = sf::Color::Yellow;
	debugTheme["activeColor"] = sf::Color::Green;
	debugTheme["accentIdleColor"] = sf::Color::Blue;
	debugTheme["accentHoverColor"] = sf::Color::Red;
	debugTheme["accentActiveColor"] = sf::Color::Cyan;
	debugTheme["textIdleColor"] = sf::Color::Blue;
	debugTheme["textHoverColor"] = sf::Color::Red;
	debugTheme["textActiveColor"] = sf::Color::Cyan;
	debugTheme["normalTextColor"] = sf::Color::Green;

    std::map<std::string, sf::Font> fonts;

    sf::Font font;
    if(!font.loadFromFile("../res/fonts/UbuntuMono-R.ttf")){
        std::cout << "ERROR::FontNotLoaded" << std::endl;
    }

    fonts["default"] = font;

/////////BASIC TEST OF DIALOGUE GRAPH/////////////////
    uiText* npcName = new uiText(15, sf::Color::White, "Lt. Blitz:", fonts["default"], sf::Vector2f(50.f, 50.f));
    uiText* npcDialogue = new uiText(15, sf::Color::White, "...Wake up.. cap..", fonts["default"], sf::Vector2f(50.f, 70.f));
    uiText* npcDialogue2 = new uiText(15, sf::Color::White, "hey there", fonts["default"], sf::Vector2f(50.f, 70.f));
	
	
	UIButton* Option1A = new UIButton(100.f, 300.f, 200.f, 50.f, debugTheme, 5.f,
	"(Wake up)", 15.f, &fonts["default"], true);

    UIButton* Option1B = new UIButton(550.f, 300.f, 200.f, 50.f, debugTheme, 5.f,
	"...huh..", 15.f, &fonts["default"], true);

    UIButton* Option2A = new UIButton(100.f, 300.f, 200.f, 50.f, debugTheme, 5.f,
	"Welcome", 15.f, &fonts["default"], true);

    Node* N1 = new Node("b1");
    Node* N2 = new Node("b2");
    Node* N3 = new Node("b3");
    //Node* N4 = new Node("b4");//terminating node

    std::list<Node*> nodes;
    nodes.push_back(N1);
    nodes.push_back(N2);
    nodes.push_back(N3);
    //nodes.push_back(N4);


    Link* l1 = new Link(npcName, npcDialogue, Option1A, N2);
    Link* l2 = new Link(npcName, npcDialogue, Option1B, N3);
    
    std::list<Link*> links1;
    links1.push_back(l1);
    links1.push_back(l2);
    
    Link* l3 = new Link(npcName, npcDialogue2, Option2A);//, N4);
    std::list<Link*> links2;
    links2.push_back(l3);///ughh dummmy

    DialogueGraph* graph = new DialogueGraph(nodes);

    graph->initializeAdjecencyList("b1", links1);
    graph->initializeAdjecencyList("b2", links2);
    graph->initializeAdjecencyList("b3", links2);

///////TESTING AUTO POPULATED GRAPH///////////
    DialogueGraph* graphAuto = new DialogueGraph();
    graphAuto->autoPopulateNodeListAndIDs("A", 4);

    for (auto it : graphAuto->getNodeList()){
        std::cout << it->getID() << std::endl;
    }

    Link* lA1 = new Link(npcName, npcDialogue, Option1A, graphAuto->getNode("A1"));
    Link* lA2 = new Link(npcName, npcDialogue, Option1B, graphAuto->getNode("A2"));
    std::list<Link*> linksAuto1;
    linksAuto1.push_back(lA1);
    linksAuto1.push_back(lA2);

    Link* lA3 = new Link(npcName, npcDialogue2, Option2A, graphAuto->getNode("A3"));
    std::list<Link*> linksAuto2;
    linksAuto2.push_back(lA3);

    graphAuto->initializeAdjecencyList("A0", linksAuto1);
    graphAuto->initializeAdjecencyList("A1", linksAuto2);

    /* Test addLink
    Link* addLink = new Link(npcName, npcDialogue2, Option2A);

    graphAuto->addLink(graphAuto->getNode("A2"), addLink, graphAuto->getNode("A3"));
    */

   /* Test emplaceLink */
   graphAuto->emplaceLink(graphAuto->getNode("A2"), npcName, npcDialogue2, Option2A, graphAuto->getNode("A3"));




    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        graphAuto->updateCurrentButtons(dt, &window);
        graphAuto->update();
        graphAuto->render(&window);
        

        /* General test
        graph->updateCurrentButtons(dt, &window);
        graph->update();

        // npcName->render(&window);
        // npcDialogue->render(&window);

        graph->render(&window);
        // for (auto it : links1){
        //     it->render(&window);
        // }*/
        
        //window.draw(shape);
        window.display();
    }

    return 0;


}
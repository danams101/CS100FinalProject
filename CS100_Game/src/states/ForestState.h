#ifndef FORESTSTATE_H
#define FORESTSTATE_H

#include "GameState.h"

class ForestState : public GameState {
    private:
    void initUI();

    public:

    ForestState(GlobalData* global_data);
    //virtual ~ForestState();

    //void renderBackground(sf::RenderTarget* target = nullptr);

    void updateButtons();
    void render(sf::RenderTarget* target = nullptr);

};

#endif
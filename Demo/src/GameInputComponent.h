//
// Created by Juan on 16/08/2021.
//

#ifndef SDL_INPUTHANDLING_GAMEINPUTCOMPONENT_H
#define SDL_INPUTHANDLING_GAMEINPUTCOMPONENT_H

#include "GameEvent.h"
#include "InputComponent.h"

class GameInputComponent : public InputComponent{
    private:
        int *quit;
    public:
        GameInputComponent(GameObject *parent, int *q);
        int process(GameEvent e) override;

};

#endif

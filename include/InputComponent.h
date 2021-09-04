//
// Created by Juan on 16/08/2021.
//

#ifndef SDL_INPUTHANDLING_INPUTCOMPONENT_H
#define SDL_INPUTHANDLING_INPUTCOMPONENT_H

#include "GameEvent.h"

class GameObject;

class InputComponent {
    protected:
        GameObject *parent;
    public:
        InputComponent() = default;
        InputComponent(GameObject *parent);
        virtual int process(GameEvent e) = 0;
};

#endif

//
// Created by Juan on 10/09/2021.
//

#ifndef SDL_INPUTHANDLING_EXITBUTTONINPUTCOMPONENT_H
#define SDL_INPUTHANDLING_EXITBUTTONINPUTCOMPONENT_H

#include "InputComponent.h"

class ExitButtonInputComponent : public InputComponent{
    public:
        ExitButtonInputComponent(GameObject *parent);
        int process(GameEvent e) override;
};


#endif //SDL_INPUTHANDLING_EXITBUTTONINPUTCOMPONENT_H

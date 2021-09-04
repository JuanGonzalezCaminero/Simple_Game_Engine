//
// Created by Juan on 01/09/2021.
//

#ifndef SDL_INPUTHANDLING_SNAKEINPUTCOMPONENT_H
#define SDL_INPUTHANDLING_SNAKEINPUTCOMPONENT_H

#include "../../../include/InputComponent.h"
#include "SnakeHead.h"

class SnakeInputComponent : public InputComponent {
    public:
        SnakeHead *parent;
        SnakeInputComponent(SnakeHead *parent);
        int process(GameEvent e) override;
};


#endif //SDL_INPUTHANDLING_SNAKEINPUTCOMPONENT_H

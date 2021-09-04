//
// Created by Juan on 01/09/2021.
//

#include "../../include/snake/SnakeInputComponent.h"

int SnakeInputComponent::process(GameEvent e) {
    if(e.type == GameEventType::MoveUp)
    {
        parent->moving=1;
        parent->direction=3;
    }
    else if(e.type == GameEventType::MoveRight)
    {
        parent->moving=1;
        parent->direction=0;
    }
    else if(e.type == GameEventType::MoveDown)
    {
        parent->moving=1;
        parent->direction=1;
    }
    else if(e.type == GameEventType::MoveLeft)
    {
        parent->moving=1;
        parent->direction=2;
    }

    return 0;
}

SnakeInputComponent::SnakeInputComponent(SnakeHead *parent): parent(parent) {}

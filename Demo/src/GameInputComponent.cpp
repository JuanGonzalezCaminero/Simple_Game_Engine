//
// Created by Juan on 16/08/2021.
//

#include "GameInputComponent.h"

GameInputComponent::GameInputComponent(GameObject *parent, int *q)
        : InputComponent(), quit(q) {}

int GameInputComponent::process(GameEvent e) {
    switch(e.get_type())
    {
        case(GameEventType::Quit):
            *quit = 1;
            break;
        default:
            return 0;
    }
    return 1;
}

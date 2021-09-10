//
// Created by Juan on 16/08/2021.
//

#include "../include/GameInputComponent.h"

GameInputComponent::GameInputComponent(GameObject *parent, SDL_Window *win, SDL_Renderer *rend, int *q)
        : InputComponent(), window(win), renderer(rend), quit(q) {}

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

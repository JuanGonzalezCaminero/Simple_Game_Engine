//
// Created by Juan on 16/08/2021.
//

#ifndef SDL_INPUTHANDLING_GAMEINPUTCOMPONENT_H
#define SDL_INPUTHANDLING_GAMEINPUTCOMPONENT_H

#include "SDL.h"
#include "../../include/GameEvent.h"
#include "../../include/InputComponent.h"

class GameInputComponent : public InputComponent{
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        int *quit;
    public:
        GameInputComponent(GameObject *parent, SDL_Window *win, SDL_Renderer *rend, int *q);
        int process(GameEvent e) override;

};

#endif

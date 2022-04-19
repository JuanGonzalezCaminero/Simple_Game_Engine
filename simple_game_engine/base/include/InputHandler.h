
/*
 * The purpose of this class is to generate the appropriate high-level commands
 * based on input from the system.
 * This class will map each input to its associated action
 */

#ifndef SDL_INPUTHANDLING_INPUTHANDLER_H
#define SDL_INPUTHANDLING_INPUTHANDLER_H

#include "SDL.h"
#include "GameEvent.h"
#include "InputComponent.h"
#include <vector>

class InputHandler {
    private:
        SDL_Event event;
        std::vector<InputComponent*> observers;
    public:
        InputHandler();
        void add(InputComponent *i);
        void notify(GameEvent e);
        void process_input();
};

#endif
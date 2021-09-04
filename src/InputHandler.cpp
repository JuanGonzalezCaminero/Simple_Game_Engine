//
// Created by Juan on 10/08/2021.
//

#include "../include/InputHandler.h"
#include <iostream>

InputHandler::InputHandler() {}


void InputHandler::process_input()
{
    //Process events since the last call
    while (SDL_PollEvent(&event) != 0)
    {
        switch (event.type)
        {
            case SDL_QUIT:
                notify(GameEvent(GameEventType::Quit));
                break;
            case SDL_WINDOWEVENT:
                switch (event.window.event)
                {
                    case SDL_WINDOWEVENT_RESIZED:
                        //SDL_GetWindowSize(window, &window_width, &window_height);
                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYDOWN:
                if(*SDL_GetKeyName(event.key.keysym.sym) == 'A')
                {
                    notify(GameEvent(GameEventType::MoveLeft));
                }
                else if(*SDL_GetKeyName(event.key.keysym.sym) == 'D')
                {
                    notify(GameEvent(GameEventType::MoveRight));
                }
                else if(*SDL_GetKeyName(event.key.keysym.sym) == 'S')
                {
                    notify(GameEvent(GameEventType::MoveDown));
                }
                else if(*SDL_GetKeyName(event.key.keysym.sym) == 'W')
                {
                    notify(GameEvent(GameEventType::MoveUp));
                }
                break;
            case SDL_CONTROLLERBUTTONDOWN:
                //std::cout << "Hey" << std::endl;
                //std::cout << event.cbutton.button << std::endl;
                if(event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT)
                {
                    notify(GameEvent(GameEventType::MoveLeft));
                }
                else if(event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT)
                {
                    notify(GameEvent(GameEventType::MoveRight));
                }
                else if(event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_DOWN)
                {
                    notify(GameEvent(GameEventType::MoveDown));
                }
                else if(event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_UP)
                {
                    notify(GameEvent(GameEventType::MoveUp));
                }
                break;
            default:
                break;
        }
    }
}

void InputHandler::add(InputComponent *i) {
    observers.push_back(i);
}

void InputHandler::notify(GameEvent e) {
    for (auto input_component: observers) {
        if(input_component->process(e) != 0)
            break;
    }
}

//
// Created by Juan on 10/08/2021.
//

#include "../include/InputHandler.h"
#include <iostream>
#include "unordered_map"

InputHandler::InputHandler() {}


void InputHandler::process_input()
{
    GameEvent game_event = GameEvent();
    //Process events since the last call
    while (SDL_PollEvent(&event) != 0)
    {
        switch (event.type)
        {
            case SDL_QUIT:
                game_event.set_type(GameEventType::Quit);
                break;
            case SDL_WINDOWEVENT:
                switch (event.window.event)
                {
                    case SDL_WINDOWEVENT_RESIZED:
                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYDOWN:
                if(*SDL_GetKeyName(event.key.keysym.sym) == 'A')
                {
                    game_event.set_type(GameEventType::LeftPressed);
                }
                else if(*SDL_GetKeyName(event.key.keysym.sym) == 'D')
                {
                    game_event.set_type(GameEventType::RightPressed);
                }
                else if(*SDL_GetKeyName(event.key.keysym.sym) == 'S')
                {
                    game_event.set_type(GameEventType::DownPressed);
                }
                else if(*SDL_GetKeyName(event.key.keysym.sym) == 'W')
                {
                    game_event.set_type(GameEventType::UpPressed);
                }
                break;
            case SDL_CONTROLLERBUTTONDOWN:
                //std::cout << "Hey" << std::endl;
                //std::cout << event.cbutton.button << std::endl;
                if(event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT)
                {
                    game_event.set_type(GameEventType::LeftPressed);
                }
                else if(event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT)
                {
                    game_event.set_type(GameEventType::RightPressed);
                }
                else if(event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_DOWN)
                {
                    game_event.set_type(GameEventType::DownPressed);
                }
                else if(event.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_UP)
                {
                    game_event.set_type(GameEventType::UpPressed);
                }
                break;
            case SDL_MOUSEMOTION:
                game_event.set_type(GameEventType::MouseMove);
                game_event.set_x(event.motion.x);
                game_event.set_y(event.motion.y);
                break;
            default:
                break;
        }

        notify(game_event);
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

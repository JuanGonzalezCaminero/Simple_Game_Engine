//
// Created by Juan on 16/08/2021.
//

#ifndef SDL_INPUTHANDLING_INPUTCOMPONENT_H
#define SDL_INPUTHANDLING_INPUTCOMPONENT_H

#include "GameEvent.h"
#include "unordered_map"

class GameObject;

class InputComponent {
    protected:
        GameObject *parent;
        bool mouse_over=false;
    public:
            InputComponent() = default;
            InputComponent(GameObject *parent);
            virtual int process(GameEvent e) = 0;
            bool check_mouse_over(int mouse_x, int mouse_y);
            bool is_mouse_over() const;
};

#endif

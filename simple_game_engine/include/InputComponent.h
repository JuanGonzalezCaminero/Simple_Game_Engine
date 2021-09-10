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
        InputComponent();
        virtual int process(GameEvent e) = 0;
        bool check_mouse_over(int mouse_x, int mouse_y);
        bool is_mouse_over() const;

        virtual GameObject *get_parent() const;
        virtual void set_parent(GameObject *parent);
};

#endif

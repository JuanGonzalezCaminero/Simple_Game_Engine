//
// Created by Juan on 01/09/2021.
//

#ifndef SDL_INPUTHANDLING_SNAKEINPUTCOMPONENT_H
#define SDL_INPUTHANDLING_SNAKEINPUTCOMPONENT_H

#include "InputComponent.h"
#include "SnakeHead.h"

class SnakeInputComponent : public InputComponent {
    private:
        SnakeHead *parent = NULL;

    public:
        SnakeInputComponent();
        int process(GameEvent e) override;

        SnakeHead *get_parent() const override;
        void set_parent(GameObject *parent) override;
};


#endif //SDL_INPUTHANDLING_SNAKEINPUTCOMPONENT_H

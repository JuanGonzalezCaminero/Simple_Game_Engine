//
// Created by Juan on 16/08/2021.
//

#ifndef SDL_INPUTHANDLING_SIMPLEOBJECT_H
#define SDL_INPUTHANDLING_SIMPLEOBJECT_H

#include "GameObject.h"

class SimpleObject : public GameObject{
    public:
        SimpleObject(int pos_x, int pos_y, int width, int height);
        void update(std::chrono::duration<double> delta) override;
        void render() override;
};

#endif

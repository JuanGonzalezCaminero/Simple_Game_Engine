//
// Created by Juan on 01/09/2021.
//

#ifndef SDL_INPUTHANDLING_SNAKEBODY_H
#define SDL_INPUTHANDLING_SNAKEBODY_H

#include "SimpleObject.h"

class SnakeBody : public SimpleObject{
    public:
        int ttl;
        SnakeBody(int pos_x, int pos_y, int size_x, int size_y, int ttl);
        void update(std::chrono::duration<double> delta) override;
};


#endif //SDL_INPUTHANDLING_SNAKEBODY_H

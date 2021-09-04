//
// Created by Juan on 03/09/2021.
//

#ifndef SDL_INPUTHANDLING_SNAKEWORLD_H
#define SDL_INPUTHANDLING_SNAKEWORLD_H

#include "../../../include/ContainerObject.h"
#include "../../../include/SimpleObject.h"
#include "SnakeHead.h"

class SnakeWorld : public ContainerObject{
    private:
        SimpleObject *fruit = NULL;
        int tiles;
        int tile_size;
    public:
        SnakeWorld(int pos_x, int pos_y, int size_x, int size_y, int tiles);
        void update(std::chrono::duration<double> delta) override;
        void add_snake(SnakeHead *s);
};


#endif //SDL_INPUTHANDLING_SNAKEWORLD_H

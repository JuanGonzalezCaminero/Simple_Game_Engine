//
// Created by Juan on 03/09/2021.
//

#ifndef SDL_INPUTHANDLING_SNAKEWORLD_H
#define SDL_INPUTHANDLING_SNAKEWORLD_H

#include "ContainerObject.h"
#include "SimpleObject.h"
#include "SnakeHead.h"
#include "../../../simple_game_engine/common_elements/include/CounterTextObject.h"

class SnakeWorld : public ContainerObject{
    private:
        SimpleObject *fruit = NULL;
        SnakeHead *snake = NULL;
        ContainerObject *scoreboard = NULL;
        CounterTextObject<int> *score_count = NULL;
        int tiles;
        int tile_size;
    public:
        SnakeWorld(int x, int y, int width, int height, struct UnitType unit_type, int tiles,
                   ContainerObject *scoreboard,
                   CounterTextObject<int> *score_count);
        void update(std::chrono::duration<double> delta) override;
};


#endif //SDL_INPUTHANDLING_SNAKEWORLD_H

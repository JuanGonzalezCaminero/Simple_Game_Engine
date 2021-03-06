//
// Created by Juan on 01/09/2021.
//

#ifndef SDL_INPUTHANDLING_SNAKEHEAD_H
#define SDL_INPUTHANDLING_SNAKEHEAD_H

#include "ContainerObject.h"
#include "SnakeBody.h"

class SnakeHead : public ContainerObject{
    public:
        //0-right, 1-down, 2-left, 3-up
        int direction = 0;
        int length;
        int moving = 0;
        double moves_per_second;
        double accumulated_wait = 0;
        ContainerObject *world;
        SnakeHead(int x, int y, int width, int height, struct UnitType unit_type, int length, int moves_per_second,
                  ContainerObject *world);
        void update(std::chrono::duration<double> delta) override;
        void increase_length(int increase);
};


#endif //SDL_INPUTHANDLING_SNAKEHEAD_H

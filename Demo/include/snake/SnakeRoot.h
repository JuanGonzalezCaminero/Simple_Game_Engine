//
// Created by Juan on 04/09/2021.
//

#ifndef SDL_INPUTHANDLING_SNAKEROOT_H
#define SDL_INPUTHANDLING_SNAKEROOT_H

#include "../../../include/ContainerObject.h"

class SnakeRoot : public ContainerObject{
    public:
        SnakeRoot(int pos_x, int pos_y, int width, int height);
        void update(std::chrono::duration<double> delta) override;
};


#endif //SDL_INPUTHANDLING_SNAKEROOT_H

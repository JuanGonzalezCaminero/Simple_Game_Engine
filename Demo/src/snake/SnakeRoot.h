//
// Created by Juan on 04/09/2021.
//

#ifndef SDL_INPUTHANDLING_SNAKEROOT_H
#define SDL_INPUTHANDLING_SNAKEROOT_H

#include "ContainerObject.h"
#include "InputHandler.h"

class SnakeRoot : public ContainerObject{
    private:
        InputHandler *input_handler;
        SDL_Renderer *renderer;
        int window_width;
        int window_height;
    public:
        SnakeRoot(int pos_x, int pos_y, int width, int height, InputHandler *input_handler, int window_width,
                  int window_height, SDL_Renderer *renderer);
        void update(std::chrono::duration<double> delta) override;
};


#endif //SDL_INPUTHANDLING_SNAKEROOT_H

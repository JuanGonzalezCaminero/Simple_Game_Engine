//
// Created by Juan on 16/08/2021.
//

#ifndef SDL_INPUTHANDLING_GAMEOBJECT_H
#define SDL_INPUTHANDLING_GAMEOBJECT_H

#include "InputComponent.h"
#include "GraphicsComponent.h"
#include "PhysicsComponent.h"
#include "chrono"

class GameObject {
    protected:
        GraphicsComponent *graphics_component = NULL;
        InputComponent *input_component = NULL;
        PhysicsComponent *physics_component = NULL;
    public:
        int pos_x;
        int pos_y;
        int width;
        int height;

        GameObject(int pos_x, int pos_y, int width, int height);
        virtual void update(std::chrono::duration<double> delta) = 0;
        virtual void render() = 0;
        void add_input(InputComponent *input);
        void add_graphics(GraphicsComponent *graphics);
        void add_physics(PhysicsComponent *physics);

        GraphicsComponent *get_graphics() const;
        InputComponent *get_input() const;
        PhysicsComponent *get_physics() const;

        virtual ~GameObject();
};

#endif
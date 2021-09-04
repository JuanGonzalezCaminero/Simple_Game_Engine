//
// Created by Juan on 16/08/2021.
//

#include "../include/GameObject.h"

GameObject::GameObject(int pos_x, int pos_y, int width, int height)
{
    this -> pos_x = pos_x;
    this -> pos_y = pos_y;
    this -> width = width;
    this -> height = height;
}

void GameObject::add_input(InputComponent *input)
{
    input_component = input;
}

void GameObject::add_graphics(GraphicsComponent *graphics)
{
    graphics_component = graphics;
}

void GameObject::add_physics(PhysicsComponent *physics) {
    physics_component = physics;
}

GameObject::~GameObject() {
    delete graphics_component;
}

GraphicsComponent *GameObject::get_graphics() const {
    return graphics_component;
}

InputComponent *GameObject::get_input() const {
    return input_component;
}

PhysicsComponent *GameObject::get_physics() const {
    return physics_component;
}



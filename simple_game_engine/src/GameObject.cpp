//
// Created by Juan on 16/08/2021.
//

#include "../include/GameObject.h"

GameObject::GameObject(int pos_x, int pos_y, int width, int height)
{
    this -> x = pos_x;
    this -> y = pos_y;
    this -> width = width;
    this -> height = height;
}

void GameObject::add_input(InputComponent *input)
{
    input->set_parent(this);
    input_component = input;
}

void GameObject::add_graphics(GraphicsComponent *graphics)
{
    graphics->set_parent(this);
    graphics_component = graphics;
}

void GameObject::add_physics(PhysicsComponent *physics) {
    physics->set_parent(this);
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

int GameObject::get_x() const {
    return x;
}

void GameObject::set_x(int pos_x) {
    GameObject::x = pos_x;
}

int GameObject::get_y() const {
    return y;
}

void GameObject::set_y(int pos_y) {
    GameObject::y = pos_y;
}

int GameObject::get_width() const {
    return width;
}

void GameObject::set_width(int width) {
    GameObject::width = width;
}

int GameObject::get_height() const {
    return height;
}

void GameObject::set_height(int height) {
    GameObject::height = height;
}





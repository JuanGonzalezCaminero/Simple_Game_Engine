//
// Created by Juan on 01/09/2021.
//

#include "../include/GameObject.h"
#include "../include/InputComponent.h"

InputComponent::InputComponent(GameObject *parent): parent(parent) {}

bool InputComponent::check_mouse_over(int mouse_x, int mouse_y) {
    if(mouse_x > parent->get_x() && mouse_y > parent->get_y() &&
    mouse_x < parent->get_x() + parent->get_width() && mouse_y < parent->get_y() + parent->get_height())
    {
        mouse_over = true;
        return true;
    }
    mouse_over = false;
    return false;
}

bool InputComponent::is_mouse_over() const {
    return mouse_over;
}
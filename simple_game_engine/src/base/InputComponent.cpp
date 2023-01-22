//
// Created by Juan on 01/09/2021.
//

#include "GameObject.h"
#include "InputComponent.h"

InputComponent::InputComponent() {}

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

GameObject *InputComponent::get_parent() const {
    return parent;
}

void InputComponent::set_parent(GameObject *parent) {
    InputComponent::parent = parent;
}

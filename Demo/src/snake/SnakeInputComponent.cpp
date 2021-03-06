//
// Created by Juan on 01/09/2021.
//

#include "SnakeInputComponent.h"

int SnakeInputComponent::process(GameEvent e) {
    if(e.get_type() == GameEventType::UpPressed)
    {
        parent->moving=1;
        parent->direction=3;
    }
    else if(e.get_type() == GameEventType::RightPressed)
    {
        parent->moving=1;
        parent->direction=0;
    }
    else if(e.get_type() == GameEventType::DownPressed)
    {
        parent->moving=1;
        parent->direction=1;
    }
    else if(e.get_type() == GameEventType::LeftPressed)
    {
        parent->moving=1;
        parent->direction=2;
    }

    return 0;
}

SnakeInputComponent::SnakeInputComponent(): InputComponent() {}

SnakeHead *SnakeInputComponent::get_parent() const {
    return parent;
}

void SnakeInputComponent::set_parent(GameObject *parent) {
    SnakeInputComponent::parent = dynamic_cast<SnakeHead*>(parent);
}

//
// Created by Juan on 16/08/2021.
//

#include "../include/SimpleObject.h"


SimpleObject::SimpleObject(int pos_x, int pos_y, int width, int height) : GameObject(pos_x, pos_y, width, height) {}

void SimpleObject::update(std::chrono::duration<double> delta)
{

}

void SimpleObject::render() {
    if(graphics_component != NULL)
    {
        graphics_component->render();
    }
}



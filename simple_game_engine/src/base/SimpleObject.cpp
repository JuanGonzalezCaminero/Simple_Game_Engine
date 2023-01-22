//
// Created by Juan on 16/08/2021.
//

#include "SimpleObject.h"


SimpleObject::SimpleObject(int x, int y, int width, int height, struct UnitType unit_type) :
        GameObject(x, y, width, height, unit_type) {}

void SimpleObject::update(std::chrono::duration<double> delta)
{

}

void SimpleObject::render() {
    if(graphics_component != NULL)
    {
        graphics_component->render();
    }
}



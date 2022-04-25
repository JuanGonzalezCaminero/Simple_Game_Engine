//
// Created by Juan on 01/09/2021.
//

#include "SnakeBody.h"
#include "iostream"

SnakeBody::SnakeBody(int x, int y, int width, int height, struct UnitType unit_type, int ttl) :
        SimpleObject(x, y, width, height, unit_type), ttl(ttl) {}

void SnakeBody::update(std::chrono::duration<double> delta) {
    ttl-=1;
    SimpleObject::update(std::chrono::duration<double>());
}

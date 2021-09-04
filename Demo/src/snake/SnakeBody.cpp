//
// Created by Juan on 01/09/2021.
//

#include "../../include/snake/SnakeBody.h"
#include "iostream"

SnakeBody::SnakeBody(int pos_x, int pos_y, int size_x, int size_y, int ttl): SimpleObject(pos_x, pos_y, size_x, size_y), ttl(ttl) {}

void SnakeBody::update(std::chrono::duration<double> delta) {
    ttl-=1;
    SimpleObject::update(std::chrono::duration<double>());
}

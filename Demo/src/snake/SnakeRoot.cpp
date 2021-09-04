//
// Created by Juan on 04/09/2021.
//

#include "../../include/snake/SnakeRoot.h"

SnakeRoot::SnakeRoot(int pos_x, int pos_y, int width, int height) : ContainerObject(pos_x, pos_y, width, height) {}

void SnakeRoot::update(std::chrono::duration<double> delta) {
    ContainerObject::update(delta);
}

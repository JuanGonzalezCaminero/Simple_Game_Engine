//
// Created by Juan on 04/09/2021.
//

#include "../../include/snake/TextObject.h"

TextObject::TextObject(int pos_x, int pos_y, int width, int height, std::string text) : SimpleObject(pos_x, pos_y, width, height), text(text) {}

//
// Created by Juan on 04/09/2021.
//

#ifndef SDL_INPUTHANDLING_TEXTOBJECT_H
#define SDL_INPUTHANDLING_TEXTOBJECT_H

#include "../../../include/SimpleObject.h"

#include "string"

class TextObject : public SimpleObject{
    private:
        std::string text;
    public:
        TextObject(int pos_x, int pos_y, int width, int height, std::string text);
};


#endif //SDL_INPUTHANDLING_TEXTOBJECT_H

//
// Created by Juan on 04/09/2021.
//

#ifndef SDL_INPUTHANDLING_TEXTOBJECT_H
#define SDL_INPUTHANDLING_TEXTOBJECT_H

#include "../../../include/SimpleObject.h"
#include "SDL_ttf.h"

#include "iostream"
#include "string"

class TextObject : public SimpleObject{
    private:
        std::string text;
        TTF_Font *font;
        SDL_Color *text_color;
    public:
        TextObject(int pos_x, int pos_y, int width, int height, const std::string& text, TTF_Font *font, SDL_Color *text_color, SDL_Renderer *renderer);
        SDL_Texture *generate_texture(const std::string& t, TTF_Font *f, SDL_Color *c, SDL_Renderer *renderer);
        void set_text(const std::string& t);
};


#endif //SDL_INPUTHANDLING_TEXTOBJECT_H

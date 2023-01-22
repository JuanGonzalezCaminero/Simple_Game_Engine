//
// Created by Juan on 04/09/2021.
//

#ifndef SDL_INPUTHANDLING_TEXTOBJECT_H
#define SDL_INPUTHANDLING_TEXTOBJECT_H

#include "SimpleObject.h"
#include "SDL_ttf.h"

#include "iostream"
#include "string"

class TextObject : public SimpleObject{
    private:
        std::string text;
        TTF_Font *font;
        SDL_Color *text_color;
        bool adapt_to_text;
    public:
        //If adapt_to_text is true, the width and height will match those of the generated text texture
        TextObject(int x, int y, int width, int height, struct UnitType unit_type, const std::string &text,
                   TTF_Font *font,
                   SDL_Color *text_color, SDL_Renderer *renderer, bool adapt_to_text);
        SDL_Texture *generate_texture(const std::string& t, TTF_Font *f, SDL_Color *c, SDL_Renderer *renderer);
        void set_text(const std::string& t);
        void adapt_size(SDL_Texture *texture);
};


#endif //SDL_INPUTHANDLING_TEXTOBJECT_H

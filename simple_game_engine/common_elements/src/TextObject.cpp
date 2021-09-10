//
// Created by Juan on 04/09/2021.
//

#include "../include/TextObject.h"
#include "iostream"

TextObject::TextObject(int pos_x, int pos_y, int width, int height, const std::string &text, TTF_Font *font,
                       SDL_Color *text_color, SDL_Renderer *renderer, bool adapt_to_text) :
                       SimpleObject(pos_x, pos_y, width, height), text(text), font(font), text_color(text_color),
                       adapt_to_text(adapt_to_text)
{
    //A text object creates its own texture with the text
    SDL_Texture *texture = generate_texture(text, font, text_color, renderer);
    //If requested, change the object's size to match the text
    if(adapt_to_text)
    {
        adapt_size(texture);
    }
    //Indicate that the texture should be destroyed along with the GraphicsComponent
    add_graphics(new GraphicsComponent(texture, renderer, false));
}

SDL_Texture *TextObject::generate_texture(const std::string &t, TTF_Font *f,
                                          SDL_Color *c, SDL_Renderer *renderer) {
    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), *text_color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    return texture;
}



void TextObject::set_text(const std::string &t) {
    //Change the object's text
    text=t;
    //Generate the texture again
    SDL_Texture *texture = generate_texture(text, font, text_color, graphics_component->get_renderer());
    //If requested, change the object's size to match the text
    if(adapt_to_text)
    {
        adapt_size(texture);
    }
    graphics_component->set_texture(texture);
}

void TextObject::adapt_size(SDL_Texture *texture) {
    int access,w,h;
    Uint32 format;
    SDL_QueryTexture(texture, &format, &access, &w, &h);
    set_width(w);
    set_height(h);
}



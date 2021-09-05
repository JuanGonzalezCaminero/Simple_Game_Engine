//
// Created by Juan on 04/09/2021.
//

#include "../../include/snake/TextObject.h"

TextObject::TextObject(int pos_x, int pos_y, int width, int height,
                       const std::string& text, TTF_Font *font, SDL_Color *text_color, SDL_Renderer *renderer) :
                       SimpleObject(pos_x, pos_y, width, height), text(text), font(font), text_color(text_color)
{
    //A text object creates its own texture with the text
    //Indicate that the texture should be destroyed along with the GraphicsComponent
    add_graphics(new GraphicsComponent(generate_texture(text, font, text_color, renderer), renderer, this, false));
}

SDL_Texture *TextObject::generate_texture(const std::string &t, TTF_Font *f,
                                          SDL_Color *c, SDL_Renderer *renderer) {
    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), *text_color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    return texture;
}

void TextObject::set_text(const std::string &t) {
    text = t;
    //Generate the texture again
    graphics_component->set_texture(generate_texture(text, font, text_color, graphics_component->get_renderer()));
}



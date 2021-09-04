//
// Created by Juan on 17/08/2021.
//

#include "../include/GraphicsComponent.h"
#include "../include/GameObject.h"

#include "iostream"

GraphicsComponent::GraphicsComponent(char const *path, SDL_Renderer *r, GameObject *p): texture_path(path), renderer(r), parent(p)
{
    shared_texture = false;

    load_texture(texture_path);

    rect.w=parent->width;
    rect.h=parent->height;
    rect.x=parent->pos_x;
    rect.y=parent->pos_y;
}

GraphicsComponent::GraphicsComponent(SDL_Texture *texture, SDL_Renderer *renderer, GameObject *parent): texture(texture), renderer(renderer), parent(parent)
{
    shared_texture = true;

    rect.w=parent->width;
    rect.h=parent->height;
    rect.x=parent->pos_x;
    rect.y=parent->pos_y;
}

void GraphicsComponent::render() {
    rect.x=parent->pos_x;
    rect.y=parent->pos_y;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void GraphicsComponent::load_texture(const char *path) {
    texture = IMG_LoadTexture(renderer, path);
    std::cout << SDL_GetError();
}

GraphicsComponent::~GraphicsComponent()
{
    if(!shared_texture)
        SDL_DestroyTexture(texture);
}

SDL_Texture *GraphicsComponent::get_texture() const {
    return texture;
}

SDL_Renderer *GraphicsComponent::get_renderer() const {
    return renderer;
}

GameObject *GraphicsComponent::get_parent() const {
    return parent;
}






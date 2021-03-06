//
// Created by Juan on 17/08/2021.
//

#include "GraphicsComponent.h"
#include "GameObject.h"

#include "iostream"

GraphicsComponent::GraphicsComponent(char const *path, SDL_Renderer *r): texture_path(path), renderer(r)
{
    shared_texture = false;

    load_texture(texture_path);
}

GraphicsComponent::GraphicsComponent(SDL_Texture *texture, SDL_Renderer *renderer, bool shared):
texture(texture), renderer(renderer), shared_texture(shared) {}

void GraphicsComponent::render() {
    rect.w=parent->get_width();
    rect.h=parent->get_height();
    rect.x= parent->get_x();
    rect.y= parent->get_y();
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

void GraphicsComponent::set_texture(SDL_Texture *t) {
    texture = t;
}

void GraphicsComponent::set_parent(GameObject *parent) {
    GraphicsComponent::parent = parent;
}






//
// Created by Juan on 17/08/2021.
//

#ifndef SDL_INPUTHANDLING_GRAPHICSCOMPONENT_H
#define SDL_INPUTHANDLING_GRAPHICSCOMPONENT_H

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_render.h"

//Forward declaration of game object. This breaks the circular dependency
//between GameObject and its components, but we need to include game object
//in the implementation of GraphicsComponent Objects

class GameObject;

class GraphicsComponent{
    private:
        const char *texture_path;
        SDL_Texture *texture;
        SDL_Renderer *renderer;
        struct SDL_Rect rect = {0,0,0,0};
        GameObject *parent;
        bool shared_texture;

    public:
        SDL_Renderer *get_renderer() const;
        SDL_Texture *get_texture() const;

        //Constructor 1: Load texture from a file
        GraphicsComponent(char const *path, SDL_Renderer *renderer, GameObject *parent);
        //Constructor 2: Get the texture from the caller
        GraphicsComponent(SDL_Texture *texture, SDL_Renderer *renderer, GameObject *parent);

        void render();
        void load_texture(const char *path);
        virtual ~GraphicsComponent();

        GameObject *get_parent() const;
};


#endif

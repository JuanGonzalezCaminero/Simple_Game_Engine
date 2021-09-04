//
// Created by Juan on 16/08/2021.
//
#ifndef SDL_INPUTHANDLING_CONTAINEROBJECT_H
#define SDL_INPUTHANDLING_CONTAINEROBJECT_H

#include "GameObject.h"
#include "vector"
#include "list"

class ContainerObject : public GameObject{
    protected:
        std::list<GameObject*> components;
    public:
        ContainerObject(int pos_x, int pos_y, int width, int height);
        void add(GameObject *o);
        void remove(GameObject *o);
        void update(std::chrono::duration<double> delta) override;
        void render() override;
        void check_collisions();
};

#endif


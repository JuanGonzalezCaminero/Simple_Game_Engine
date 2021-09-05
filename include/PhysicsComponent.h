//
// Created by Juan on 03/09/2021.
//

#include "vector"

#ifndef SDL_INPUTHANDLING_PHYSICSCOMPONENT_H
#define SDL_INPUTHANDLING_PHYSICSCOMPONENT_H

class GameObject;

class PhysicsComponent {
    private:
        GameObject *parent;
    public:
        PhysicsComponent(GameObject *parent);
        std::vector<GameObject*> collisions;
        void check_collision(GameObject *o);
        void add_collision(GameObject *o);
        void clear_collisions();
};


#endif //SDL_INPUTHANDLING_PHYSICSCOMPONENT_H

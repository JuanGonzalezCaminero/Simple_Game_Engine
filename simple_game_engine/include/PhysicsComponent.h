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
        PhysicsComponent();
        std::vector<GameObject*> collisions;
        void check_collision(GameObject *o);
        void add_collision(GameObject *o);
        void clear_collisions();

        GameObject *get_parent() const;
        void set_parent(GameObject *parent);
};


#endif //SDL_INPUTHANDLING_PHYSICSCOMPONENT_H

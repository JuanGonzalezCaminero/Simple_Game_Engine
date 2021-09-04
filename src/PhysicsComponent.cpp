//
// Created by Juan on 03/09/2021.
//

#include "../include/PhysicsComponent.h"
#include "../include/GameObject.h"

PhysicsComponent::PhysicsComponent(GameObject *parent): parent(parent) {}

//Currently, this only works for square objects that are axis-aligned
void PhysicsComponent::check_collision(GameObject *o) {
    if (parent->pos_x < o->pos_x + o->width &&
    parent->pos_x + parent->width > o->pos_x &&
    parent->pos_y < o->pos_y + o->height &&
    parent->pos_y + parent->height > o->pos_y) {
        //Update the collisions list for both objects
        add_collision(o);
        //o->get_physics()->add_collision(parent);
    }
}

void PhysicsComponent::add_collision(GameObject *o) {
    collisions.push_back(o);
}

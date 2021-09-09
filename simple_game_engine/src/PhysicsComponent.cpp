//
// Created by Juan on 03/09/2021.
//

#include "../include/PhysicsComponent.h"
#include "../include/GameObject.h"

PhysicsComponent::PhysicsComponent(GameObject *parent): parent(parent) {}

//Currently, this only works for square objects that are axis-aligned
void PhysicsComponent::check_collision(GameObject *o) {
    if (parent->get_x() < o->get_x() + o->get_width() &&
            parent->get_x() + parent->get_width() > o->get_x() &&
            parent->get_y() < o->get_y() + o->get_height() &&
            parent->get_y() + parent->get_height() > o->get_y()) {
        //Update the collisions list for both objects
        add_collision(o);
        //o->get_physics()->add_collision(parent);
    }
}

void PhysicsComponent::add_collision(GameObject *o) {
    collisions.push_back(o);
}

void PhysicsComponent::clear_collisions() {
    collisions.clear();
}

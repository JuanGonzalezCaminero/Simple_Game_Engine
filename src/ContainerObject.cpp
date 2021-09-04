//
// Created by Juan on 16/08/2021.
//

#include "../include/ContainerObject.h"
#include "iostream"

void ContainerObject::add(GameObject *o)
{
    this -> components.push_back(o);
}

void ContainerObject::remove(GameObject *o)
{
    //Compare references and remove the requested object
    //std::remove_if(this -> components.begin(), this -> components.end(), [&](const auto& item){item == o});
}

/*
 * This function should be called by every ContainerObject's children's implementation of update
 * Calls update on all children
 * */
void ContainerObject::update(std::chrono::duration<double> delta) {
    for (auto o: components) {
        o->update(delta);
    }
}

/*
 * Renders this Object, if it has a graphics component, and calls render on all children
 */
void ContainerObject::render() {
    if(graphics_component != nullptr)
    {
        graphics_component->render();
    }
    for (auto o: components) {
        o->render();
    }
}

ContainerObject::ContainerObject(int pos_x, int pos_y, int width, int height) : GameObject(pos_x, pos_y, width, height) {}

void ContainerObject::check_collisions() {
    //This is a very inefficient way of checking for collisions.
    //This should be improved by making the inner loop only check for collisions for j=i...
    //And modifying the PhysicsComponent to add the collision to both objects
    for(auto object1: components)
    {
        for(auto object2: components)
        {
            if(object1==object2)
                continue;
            if(object1->get_physics()!=NULL && object2->get_physics()!=NULL)
            {
                object1->get_physics()->check_collision(object2);
            }
        }
    }
}






























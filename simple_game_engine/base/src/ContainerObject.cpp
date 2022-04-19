//
// Created by Juan on 16/08/2021.
//

#include "../include/ContainerObject.h"
#include "iostream"

void ContainerObject::add(GameObject *o)
{
    //Sets the object's parent
    o->set_parent(this);

    //Take the object's coordinates as local coordinates within this ContainerObject

    //Absolute positioning: Adds the object's coordinates to the parent's origin
    if(o->get_unit_type().x_type == ABS)
    {
        o->set_x(o->get_x() + x);
    }
    if(o->get_unit_type().y_type == ABS)
    {
        o->set_y(o->get_y() + y);
    }

    //Percentage positioning: Adds a percentage of the parent's width and height to the
    //parent's origin. For width and height, sets them to a percentage of the parent's size
    if(o->get_unit_type().x_type == REL)
    {
        o->set_x(o->get_x()/100.0 * width + x);
    }
    if(o->get_unit_type().y_type == REL)
    {
        o->set_y(o->get_y()/100.0 * height + y);
    }
    if(o->get_unit_type().width_type == REL)
    {
        o->set_width(o->get_width()/100.0 * width);
    }
    if(o->get_unit_type().height_type == REL)
    {
        o->set_height(o->get_height()/100.0 * height);
    }

    //Update the components list
    this -> components.push_back(o);
}

void ContainerObject::remove(GameObject *o)
{
    //Compare references and remove the requested object
    components.remove(o);
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

ContainerObject::ContainerObject(int x, int y, int width, int height, struct UnitType unit_type)
        : GameObject(x, y, width, height, unit_type) {}

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






























//
// Created by Juan on 01/09/2021.
//

#include "../../include/snake/SnakeHead.h"
#include "iostream"

SnakeHead::SnakeHead(int pos_x, int pos_y, int size_x, int size_y, int length, int moves_per_second,
                     ContainerObject *world) :
    ContainerObject(pos_x, pos_y, size_x, size_y),
    length(length),
    moves_per_second(moves_per_second),
    world(world)
    {

    }

void SnakeHead::update(std::chrono::duration<double> delta)
{

    if(moving && accumulated_wait > 1/moves_per_second)
    {
        accumulated_wait = 0;

        //Add a new body part at the head's position
        SnakeBody *new_part = new SnakeBody(0, 0, width, height, length);
        new_part->add_graphics(new GraphicsComponent(graphics_component->get_texture(), graphics_component->get_renderer(), new_part, true));
        new_part->add_physics(new PhysicsComponent(new_part));
        add(new_part);

        //Move in the current direction
        switch (direction) {
            case 0:
                x += width;
                break;
            case 1:
                y += height;
                break;
            case 2:
                x -= width;
                break;
            case 3:
                y -= height;
                break;
            default:
                break;
        }

        //Remove the last body part if it has exceeded its ttl
        auto *last = (SnakeBody*)components.front();
        if(last -> ttl == 0)
        {
            components.pop_front();
            delete last;
        }

        //Detect collisions with other body parts and with the world's borders
        for(auto body_part: components)
        {
            physics_component->check_collision(body_part);
        }

        if(!physics_component->collisions.empty())
        {
            moving=0;
        }

        //Collisions with the world`s borders
        if(x < world->get_x() ||
           y < world->get_y() ||
           x >= world->get_x() + world->get_width() ||
           y >= world->get_y() + world->get_height())
        {
            moving=0;
        }

        //Clear collisions list (In case the game is reset)
        physics_component->collisions.clear();

        //Call base class method (update call on all children)
        ContainerObject::update(delta);
    }
    else
    {
        accumulated_wait += delta.count();
    }
}

void SnakeHead::increase_length(int increase) {
    length+=increase;
}



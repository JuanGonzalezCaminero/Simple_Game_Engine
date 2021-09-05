//
// Created by Juan on 03/09/2021.
//

#include "../../include/snake/SnakeWorld.h"
#include "random"
#include "iostream"

void SnakeWorld::update(std::chrono::duration<double> delta) {
    //Generate a new fruit
    if(fruit==NULL)
    {
        fruit = new SimpleObject((rand()%(tiles))*tile_size, (rand()%(tiles))*tile_size, tile_size, tile_size);
        fruit->add_graphics(new GraphicsComponent("../assets/textures/snake_fruit.bmp", graphics_component->get_renderer(), fruit));
        fruit->add_physics(new PhysicsComponent(fruit));
        add(fruit);
    }

    //Check for collisions with the fruit
    check_collisions();
    if(!components.front()->get_physics()->collisions.empty())
    {
        components.pop_back();
        delete fruit;
        fruit=NULL;
        dynamic_cast<SnakeHead*>(components.front())->increase_length(1);
        components.front()->get_physics()->clear_collisions();
    }

    ContainerObject::update(delta);
}

SnakeWorld::SnakeWorld(int pos_x, int pos_y, int size_x, int size_y, int tiles) : ContainerObject(pos_x, pos_y, size_x, size_y), tiles(tiles)
{
    tile_size = size_x/tiles;
}

//
// Created by Juan on 16/08/2021.
//

#ifndef SDL_INPUTHANDLING_GAMEOBJECT_H
#define SDL_INPUTHANDLING_GAMEOBJECT_H

#include "InputComponent.h"
#include "GraphicsComponent.h"
#include "PhysicsComponent.h"
#include "const.h"
#include "chrono"

struct UnitType
{
    int x_type;
    int y_type;
    int width_type;
    int height_type;
};

class GameObject {
    protected:
        GameObject *parent = NULL;
        GraphicsComponent *graphics_component = NULL;
        InputComponent *input_component = NULL;
        PhysicsComponent *physics_component = NULL;
        int x;
        int y;
        int width;
        int height;
        struct UnitType unit_type = {ABS, ABS, ABS, ABS};

public:
        GameObject(int x, int y, int width, int height, UnitType unit_type);
        GameObject(int x, int y, int width, int height);
        virtual void update(std::chrono::duration<double> delta) = 0;
        virtual void render() = 0;

        void add_input(InputComponent *input);
        void add_graphics(GraphicsComponent *graphics);
        void add_physics(PhysicsComponent *physics);

        GraphicsComponent *get_graphics() const;
        InputComponent *get_input() const;
        PhysicsComponent *get_physics() const;

        int get_x() const;
        void set_x(int x);
        int get_y() const;
        void set_y(int y);
        int get_width() const;
        void set_width(int width);
        int get_height() const;
        void set_height(int height);

        GameObject *get_parent() const;
        void set_parent(GameObject *parent);

        const UnitType &get_unit_type() const;
        void set_unit_type(const UnitType &unit_type);

        virtual ~GameObject();
};

#endif
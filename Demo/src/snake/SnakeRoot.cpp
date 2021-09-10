//
// Created by Juan on 04/09/2021.
//

#include "../../include/snake/SnakeRoot.h"
#include "SDL_ttf.h"
#include "TextObject.h"
#include "CounterTextObject.h"
#include "../../include/snake/ExitButtonInputComponent.h"
#include "../../include/snake/SnakeWorld.h"
#include "../../include/snake/SnakeHead.h"
#include "../../include/snake/SnakeInputComponent.h"

SnakeRoot::SnakeRoot(int pos_x, int pos_y, int width, int height, InputHandler *input_handler, int window_width,
                     int window_height, SDL_Renderer *renderer) :
                    input_handler(input_handler), window_width(window_width), window_height(window_width), renderer(renderer),
                    ContainerObject(pos_x, pos_y, width, height)
{
    //Init game objects
    int scoreboard_width = window_width;
    int snake_world_size = window_width;
    int scoreboard_height = window_height-snake_world_size;
    int snake_world_tiles = 20;

    //Scoreboard
    ContainerObject *scoreboard = new ContainerObject(0, 0, scoreboard_width, scoreboard_height);
    scoreboard ->add_graphics(new GraphicsComponent("../assets/textures/snake_scoreboard.bmp", renderer));

    //Scoreboard text
    TTF_Font *font = TTF_OpenFont("../assets/fonts/arial.ttf", 24);
    TextObject *score_text = new TextObject(20, 20, 0, 0, "Score:", font, new SDL_Color{255, 255, 255}, renderer,
                                            true);

    //Scoreboard count
    CounterTextObject<int> *score_count = new CounterTextObject<int>(score_text->get_width() + score_text->get_x() + 5, 20, 0, 0, 0, font,
                                                                     new SDL_Color{255, 255, 255}, renderer, true);

    //Exit button text
    TextObject *exit_text = new TextObject(5, 5, 0, 0, "Exit", font, new SDL_Color{255, 255, 255}, renderer, true);

    //Exit button
    ContainerObject *exit_button = new ContainerObject(scoreboard_width-exit_text->get_width()-30, 10, exit_text->get_width()+15, exit_text->get_height()+10);
    exit_button->add_graphics(new GraphicsComponent("../assets/textures/snake_scoreboard.bmp", renderer));
    exit_button->add_input(new ExitButtonInputComponent());

    //Restart button text
    TextObject *restart_text = new TextObject(5, 5, 0, 0, "Exit", font, new SDL_Color{255, 255, 255}, renderer, true);

    //Restart button
    ContainerObject *restart_button = new ContainerObject(scoreboard_width-exit_text->get_width()-30, 10, exit_text->get_width()+15, exit_text->get_height()+10);
    exit_button->add_graphics(new GraphicsComponent("../assets/textures/snake_scoreboard.bmp", renderer));
    exit_button->add_input(new ExitButtonInputComponent());

    //World
    //The Game world gets a reference to the scoreboard and score counter, in order to update the score whenever the snake
    // eats a fruit and to activate the reset button on game over
    SnakeWorld *world = new SnakeWorld(0, scoreboard_height, snake_world_size, snake_world_size, snake_world_tiles,
                                       scoreboard, score_count);
    world->add_graphics(new GraphicsComponent("../assets/textures/snake_world.bmp", renderer));

    //Snake
    SnakeHead *snake = new SnakeHead(snake_world_size/2,
                                     snake_world_size/2,
                                     snake_world_size/snake_world_tiles,
                                     snake_world_size/snake_world_tiles,
                                     4,
                                     10,
                                     world);
    snake->add_graphics(new GraphicsComponent("../assets/textures/snake_tile.bmp", renderer));
    snake->add_input(new SnakeInputComponent());
    snake->add_physics(new PhysicsComponent());

    //Connect Input consumers to the input handler
    input_handler->add(snake->get_input());
    input_handler->add(exit_button->get_input());

    //Build the game tree:
    /*
     * root
     *   |-----------|
     *   |           |
     * world     scoreboard
     *   |           |------------------|------------------|
     *   |           |                  |                  |
     * snake     score_text        score_count        exit_button
     *                                                     |
     *                                                     |
     *                                                 exit_text
     */

    world->add(snake);

    exit_button->add(exit_text);

    scoreboard -> add(score_text);
    scoreboard -> add(score_count);
    scoreboard -> add(exit_button);

    this->add(world);
    this->add(scoreboard);
}

void SnakeRoot::update(std::chrono::duration<double> delta) {
    ContainerObject::update(delta);
}

#include <iostream>
#include "chrono"

#include "SDL.h"
#include "SDL_image.h"

#include "InputHandler.h"
#include "GameObject.h"
#include "GraphicsComponent.h"
#include "SimpleObject.h"
#include "ContainerObject.h"
#include "SDL_gamecontroller.h"

#include "../include/GameInputComponent.h"
#include "../include/snake/SnakeHead.h"
#include "../include/snake/SnakeInputComponent.h"
#include "../include/snake/SnakeWorld.h"
#include "../include/snake/SnakeRoot.h"
#include "../include/snake/ExitButtonInputComponent.h"
#include "TextObject.h"
#include "CounterTextObject.h"

int main(int argc, char *argv[]) {
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Event event;
    int quit = 0;
    int window_width = 400, window_height = 600;
    InputHandler input_handler;
    GameInputComponent game_input(nullptr, window, renderer, &quit);

    input_handler.add(&game_input);

    auto time_prev = std::chrono::steady_clock::now();
    auto time_now = std::chrono::steady_clock::now();
    std::chrono::duration<double> delta{};

    //////////////////////////////////////////
    //          SDL INITIALIZATION          //
    //////////////////////////////////////////

    // Initialize SDL and its File I/O, Threading (Both by default), Video and
    // Event Handling (Initialized implicitly by the video subsystem) subsystems
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);
    TTF_Init();

    if(SDL_NumJoysticks()>0)
    {
        SDL_GameController *controller = SDL_GameControllerOpen(0);
        std::cout << SDL_GameControllerName(controller) << std::endl;
        SDL_GameControllerEventState(SDL_ENABLE);
    }

    window = SDL_CreateWindow("InputHandling",
                              window_width, window_height,
                              window_width, window_height,
                              SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //Init game objects
    int scoreboard_width = window_width;
    int snake_world_size = window_width;
    int scoreboard_height = window_height-snake_world_size;
    int snake_world_tiles = 20;

    //Scoreboard
    ContainerObject *scoreboard = new ContainerObject(0, 0, scoreboard_width, scoreboard_height);
    scoreboard ->add_graphics(new GraphicsComponent("../assets/textures/snake_scoreboard.bmp", renderer, scoreboard));

    //Scoreboard text
    TTF_Font *font = TTF_OpenFont("../assets/fonts/arial.ttf", 24);
    TextObject *score_text = new TextObject(20, 20, 0, 0, "Score:", font, new SDL_Color{255, 255, 255}, renderer,
                                            true);

    //Scoreboard count
    CounterTextObject<int> *score_count = new CounterTextObject<int>(score_text->get_width() + score_text->get_x() + 5, 20, 0, 0, 0, font,
                                                                     new SDL_Color{255, 255, 255}, renderer, true);

    //Exit button
    TextObject *exit_text = new TextObject(0, 0, 0, 0, "Exit", font, new SDL_Color{255, 255, 255}, renderer, true);
    ContainerObject *exit_button = new ContainerObject(scoreboard_width-exit_text->get_width()-20, 10, exit_text->get_width(), exit_text->get_height());
    exit_button->add_input(new ExitButtonInputComponent(exit_button));

    //World
    //The Game world gets a reference to the scoreboard and score counter, in order to update the score whenever the snake
    // eats a fruit and to activate the reset button on game over
    SnakeWorld *world = new SnakeWorld(0, scoreboard_height, snake_world_size, snake_world_size, snake_world_tiles,
                                       scoreboard, score_count);
    world->add_graphics(new GraphicsComponent("../assets/textures/snake_world.bmp", renderer, world));

    //Snake
    SnakeHead *snake = new SnakeHead(snake_world_size/2,
                                     snake_world_size/2,
                                     snake_world_size/snake_world_tiles,
                                     snake_world_size/snake_world_tiles,
                                     4,
                                     10,
                                     world);
    snake->add_graphics(new GraphicsComponent("../assets/textures/snake_tile.bmp", renderer, snake));
    snake->add_input(new SnakeInputComponent(snake));
    snake->add_physics(new PhysicsComponent(snake));

    //Game Root
    SnakeRoot *snake_root = new SnakeRoot(0, 0, window_width, window_height);

    //Connect Input consumers to the input handler
    input_handler.add(snake->get_input());
    input_handler.add(exit_button->get_input());

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

    snake_root->add(world);
    snake_root->add(scoreboard);

    //Main game loop
    while(!quit)
    {
        time_prev = time_now;
        time_now = std::chrono::steady_clock::now();
        //Time in seconds, with double precission
        delta = time_now - time_prev;

        //////////////////////////////////////////
        //                INPUT                 //
        //////////////////////////////////////////
        input_handler.process_input();

        //////////////////////////////////////////
        //               UPDATE                 //
        //////////////////////////////////////////
        snake_root->update(delta);

        //////////////////////////////////////////
        //               RENDER                 //
        //////////////////////////////////////////
        snake_root->render();

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}

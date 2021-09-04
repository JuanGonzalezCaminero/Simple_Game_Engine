#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "../../include/InputHandler.h"
#include "../include/GameInputComponent.h"
#include "../../include/GameObject.h"
#include "../../include/GraphicsComponent.h"
#include "../../include/SimpleObject.h"
#include "../../include/ContainerObject.h"
#include "../include/snake/SnakeHead.h"
#include "../include/snake/SnakeInputComponent.h"
#include "chrono"
#include "SDL_gamecontroller.h"
#include "../include/snake/SnakeWorld.h"
#include "../include/snake/SnakeRoot.h"

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

    //World
    SnakeWorld *world = new SnakeWorld(0, scoreboard_height, snake_world_size, snake_world_size, snake_world_tiles);
    world->add_graphics(new GraphicsComponent("../assets/textures/snake_world.bmp", renderer, world));

    //Snake
    SnakeHead *snake = new SnakeHead(world->pos_x + snake_world_size/2,
                                     world->pos_y + snake_world_size/2,
                                     snake_world_size/snake_world_tiles,
                                     snake_world_size/snake_world_tiles,
                                     4,
                                     10,
                                     world);
    snake->add_graphics(new GraphicsComponent("../assets/textures/snake_tile.bmp", renderer, snake));
    snake->add_input(new SnakeInputComponent(snake));
    snake->add_physics(new PhysicsComponent(snake));

    input_handler.add(snake->get_input());

    //Scoreboard
    ContainerObject *scoreboard = new ContainerObject(0, 0, scoreboard_width, scoreboard_height);
    scoreboard ->add_graphics(new GraphicsComponent("../assets/textures/snake_scoreboard.bmp", renderer, scoreboard));

    //Game Root
    SnakeRoot *snake_root = new SnakeRoot(0, 0, window_width, window_height);

    world->add(snake);

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

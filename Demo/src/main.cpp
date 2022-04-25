#include <iostream>
#include "chrono"

#include "SDL.h"

#include "InputHandler.h"
#include "GameObject.h"
#include "GraphicsComponent.h"
#include "SDL_gamecontroller.h"

#include "GameInputComponent.h"
#include "SnakeRoot.h"
#include "TextObject.h"

int main(int argc, char *argv[]) {
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    int quit = 0;
    int window_width = 400, window_height = 600;
    InputHandler *input_handler = new InputHandler();
    GameInputComponent game_input(nullptr, &quit);

    input_handler->add(&game_input);

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

    //Game Root
    SnakeRoot *snake_root = new SnakeRoot(0, 0, window_width, window_height, input_handler, window_width, window_height, renderer);

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
        input_handler->process_input();

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

#include "stdio.h"
#include <cassert>

// glad must be included before SDL
#include <glad/glad.h>
#include <SDL.h>

constexpr int SCREEN_WIDTH{640};
constexpr int SCREEN_HEIGHT{320};

// argc and args[] are required for SDL2 to function, but not used by this program.
int main([[maybe_unused]] int argc, [[maybe_unused]] char *args[])
{
    SDL_Window *window{nullptr};

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    // Create window
    window = SDL_CreateWindow("SDL Tutorial",
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    // Setup the graphics context
    SDL_GLContext context = SDL_GL_CreateContext(window);

    // Setup function pointers
    gladLoadGLLoader(SDL_GL_GetProcAddress);

    bool shouldBeRunning{true};
    while (shouldBeRunning)
    {
        glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

        SDL_Event event;
        // Start event loop
        while (SDL_PollEvent(&event))
        {
            // Handle events
            if (event.type == SDL_QUIT)
            {
                shouldBeRunning = false;
            }
        }

        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
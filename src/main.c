#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>

//#include "Entity.h"
#include "Utils.h"

const int WIDTH = 600;
const int HEIGHT = 400;
const char* title = "Chrome Dino";

SDL_Window* win;
SDL_Renderer* rend;

int running = 1;

int GetRefreshRate();

int main()
{

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Couldn't inialise SDL. Error %s", SDL_GetError());
    }

    if(IMG_Init(IMG_INIT_PNG) == 0)
    {

    }

    win = SDL_CreateWindow(title, 20, 20, WIDTH, HEIGHT, 0);
    rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_Texture* sample = IMG_LoadTexture(rend, "src/res/sadlinus.png");
    if(!sample)
    {
        IMG_GetError();
    }

    const float timestep = 0.017f; // determines how many times the game is updated per second. 0.017 = (1/60)
    float accumulator = 0.0f; // counts how long it has been since last update
    float currentTime = SDL_GetTicks() * 0.001f; // SDL_GetTicks returns in milliseconds
                                                 // and it is then converted to seconds

    SDL_Event e;

    while(running)
    {
        int startTicks = SDL_GetTicks();

        float newTime = SDL_GetTicks() * 0.001f;
        float frameTime = newTime - currentTime;

        currentTime = newTime;

        accumulator += frameTime;

        while(accumulator >= timestep)
        {
            while(SDL_PollEvent(&e))
            {
                switch(e.type)
                {
                    case SDL_QUIT:
                        running = 0;
                        break;
                }
            }

            accumulator -= timestep;
        }

        const float alpha = accumulator / timestep;

        printf("%d\n", GetRefreshRate());

        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, sample, NULL, NULL);
        SDL_RenderPresent(rend);

        int frameTicks = SDL_GetTicks() - startTicks;

        if(frameTicks < 1000/GetRefreshRate())
        {
            SDL_Delay((1000/GetRefreshRate()) - frameTicks);
        }
    }

    printf("Hello, world!");
    return 0;
}

//void render(Entity e)
//{
    
//}

int GetRefreshRate()
{
    SDL_DisplayMode mode;
    int displayIndex = SDL_GetWindowDisplayIndex(win);
    int defaultRefreshRate = 60;

    if(SDL_GetDesktopDisplayMode(displayIndex, &mode) != 0)
    {
        return defaultRefreshRate;
    }

    if(mode.refresh_rate == 0)
    {
        return defaultRefreshRate;
    }

    return mode.refresh_rate;
}

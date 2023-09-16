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
    rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    SDL_Texture* sample = IMG_LoadTexture(rend, "src/res/sadlinus.png");
    if(!sample)
    {
        IMG_GetError();
    }

    while(running)
    {
        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
                case SDL_QUIT:
                    running = 0;
                    break;
            }
        }
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, sample, NULL, NULL);
        SDL_RenderPresent(rend);
    }

    printf("Hello, world!");
    return 0;
}

//void render(Entity e)
//{
    
//}

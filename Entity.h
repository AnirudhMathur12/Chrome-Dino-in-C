#pragma once

#include <SDL2/SDL_image.h>

struct Entity
{
    int x, y;

    SDL_Texure* tex;
    
};

struct Entity* CreateEntity(int x, int y, const char* path);

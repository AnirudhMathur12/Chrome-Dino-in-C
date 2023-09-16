#pragma once

#include <SDL2/SDL.h>

inline float hireTimeInSeconds()
{
    float t = SDL_GetTick(); //returns in milliseconds
    t *= 0.001f; //convert to seconds
    
    return t;
}

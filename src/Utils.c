#include "Utils.h"

float hireTimeInSeconds()
{
    float t = SDL_GetTicks(); // return in milliseconds
    t *= 0.001f; // convert to seconds
    
    return t;
}

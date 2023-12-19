#pragma once
#include "raylib.h"

// Interface for any drawable entity in the gameworld

class Entity
{
public:
    virtual void Draw(Texture2D *sprite_atlas, float x, float y) = 0;
};
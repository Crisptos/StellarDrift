#pragma once
#include <string>
#include "raylib.h"
#include "gameplay/entity.h"

class Player : public Entity
{
public:
    Player(const char* player_name, Vector2 position, int health);
    void Draw(Texture2D *sprite_atlas, float x, float y);

    const char* player_name;
    Vector2 position;
    int health;
};
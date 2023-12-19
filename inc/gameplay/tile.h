#pragma once
#include "gameplay/entity.h"

const Rectangle BASE_TILE = Rectangle{0, 0, 32.0f, 32.0f};
const Rectangle PLAYER_SPRITE = Rectangle{96, 320, 32.0f, 32.0f};

enum TileType{
    PLANET = 1,
    PLANETMOON = 2,
    SUN = 3,
    STARS = 7,
};

class Tile : public Entity
{
public:
    Tile();
    ~Tile();
    void Draw(Texture2D *sprite_atlas, float x, float y);

    TileType type;

    Rectangle layer1;
    Rectangle layer2;
};
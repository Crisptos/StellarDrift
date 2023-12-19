#include "gameplay/tile.h"

Tile::Tile()
{
}

Tile::~Tile()
{
}

void Tile::Draw(Texture2D *sprite_atlas, float x, float y)
{
    DrawTextureRec(*sprite_atlas, BASE_TILE, Vector2{x * 32.0f, y * 32.0f}, WHITE);
    DrawTextureRec(*sprite_atlas, layer1, Vector2{x * 32.0f, y * 32.0f}, WHITE);
    if(type == PLANETMOON)
       DrawTextureRec(*sprite_atlas, layer2, Vector2{x * 32.0f, y * 32.0f}, WHITE); 
}

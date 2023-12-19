#include "gameplay/world_gen.h"

/**
 * Procedurally generate a game world. Tile Structs contain Rects that map to the sprite atlas. Not all rects will have a value as no tile should have all 4 at once
 */
std::vector<Tile> GenWorld(int w, int h)
{
    std::vector<Tile> map;
    for (int x = 0; x < w; x++)
    {
        for (int y = 0; y < h; y++)
        {
            Tile temp_tile;
            int tile_variant = GetRandomValue(0, 9);
            // Roll to see what type of tile
            switch (GetRandomValue(1, 3))
            {
            case 1: // Stars
                temp_tile.layer1 = Rectangle{32.0f * tile_variant, 32.0f * 7, 32.0f, 32.0f};
                temp_tile.type = STARS;
                break;
            case 2: // Planet + Moon?
                temp_tile.layer1 = Rectangle{32.0f * tile_variant, 32.0f * 1, 32.0f, 32.0f};
                temp_tile.type = PLANET;
                if (GetRandomValue(0, 1) == 1)
                    temp_tile.layer2 = Rectangle{32.0f * tile_variant, 32.0f * 2, 32.0f, 32.0f};
                    temp_tile.type = PLANETMOON;
                break;
            case 3: // Sun
                temp_tile.layer1 = Rectangle{32.0f * tile_variant, 32.0f * 3, 32.0f, 32.0f};
                temp_tile.type = SUN;
                break;
            }

            map.push_back(temp_tile);
        }
    }

    return map;
}
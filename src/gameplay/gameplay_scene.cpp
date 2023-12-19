#include "gameplay/gameplay_scene.h"

GameplayScene::GameplayScene()
{
}

GameplayScene::~GameplayScene()
{
}

void GameplayScene::StartScene()
{
    status = UNDEFINED;

    // Camera
    camera.target = player->position;
    camera.offset = (Vector2){SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    camera.rotation = 0.0f;
    camera.zoom = 2.0f;

    // UI Conditions
    show_intro = true;

    // Texture Atlas
    sprite_atlas = LoadTexture("assets/sprites/tile_atlas.png");

    // Generate Gameworld
    map = GenWorld(60, 60);
}

void GameplayScene::UpdateScene()
{
    UpdateScene2D();
    UpdateSceneUI();
}

void GameplayScene::DrawScene()
{
    // Draw Game
    DrawScene2D();
    DrawSceneUI();
}

void GameplayScene::EndScene()
{
    status = UNDEFINED;
    UnloadTexture(sprite_atlas);
}

GameScene GameplayScene::IsFinishedScene()
{
    return status;
}

void GameplayScene::SetPlayerInfo(Player player)
{
    this->player = new Player(player.player_name, player.position, player.health);
}

void GameplayScene::UpdateScene2D()
{
    // Player Controls
    if (IsKeyPressed(KEY_LEFT))
        player->position.x -= 32.0f;
    if (IsKeyPressed(KEY_UP))
        player->position.y -= 32.0f;
    if (IsKeyPressed(KEY_DOWN))
        player->position.y += 32.0f;
    if (IsKeyPressed(KEY_RIGHT))
        player->position.x += 32.0f;

    camera.target = player->position;
}
void GameplayScene::UpdateSceneUI()
{
}

void GameplayScene::DrawScene2D()
{
    BeginMode2D(camera);
    for (float x = 0; x < 60; x++)
    {
        for (float y = 0; y < 60; y++)
        {
            map[x + 60 * y].Draw(&sprite_atlas, x, y);
        }
    }
    DrawTextureRec(sprite_atlas, PLAYER_SPRITE, player->position, WHITE);

    EndMode2D();
}

void GameplayScene::DrawSceneUI()
{
}
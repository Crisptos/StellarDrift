#include "gameplay_scene.h"

GameplayScene::GameplayScene()
{
}

GameplayScene::~GameplayScene()
{
}

void GameplayScene::StartScene()
{
    status = UNDEFINED;
    show_intro = true;
}

void GameplayScene::UpdateScene()
{
    UpdateScene2D();
    UpdateSceneUI();
}

void GameplayScene::DrawScene()
{
    // Draw Game
    ClearBackground(BLACK);
    DrawScene2D();
    DrawSceneUI();
}

void GameplayScene::EndScene()
{
    status = UNDEFINED;
}

GameScene GameplayScene::IsFinishedScene()
{
    return status;
}

void GameplayScene::SetPlayerInfo(Player player)
{
    this->player = player;
}

void GameplayScene::UpdateScene2D()
{
}
void GameplayScene::UpdateSceneUI()
{
}

void GameplayScene::DrawScene2D()
{
    DrawText(player.player_name.c_str(), 10, 10, 20, WHITE);
    if (show_intro)
    {
        DrawRectangleRec(intro_panel, UI_BASE);
    }
}

void GameplayScene::DrawSceneUI()
{
}
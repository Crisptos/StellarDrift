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
}

void GameplayScene::UpdateScene()
{
}

void GameplayScene::DrawScene()
{
    ClearBackground(BLACK);
    DrawText(player.player_name.c_str(), 10, 10, 20, WHITE);
}

void GameplayScene::EndScene()
{
    status = UNDEFINED;
    player = {0};
}

GameScene GameplayScene::IsFinishedScene()
{
    return status;
}

void GameplayScene::SetPlayerInfo(Player player)
{
    this->player = player;
}
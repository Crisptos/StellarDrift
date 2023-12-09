#include "character_scene.h"

CharacterScene::CharacterScene()
{
}

CharacterScene::~CharacterScene()
{
}

void CharacterScene::StartScene()
{
    status = UNDEFINED;
    menu_bg = LoadTexture("assets/sprites/bg.png");
}

void CharacterScene::UpdateScene()
{
}

void CharacterScene::DrawScene()
{
    // Background and UI Elements
    DrawTexture(menu_bg, 0, 0, WHITE);
}

void CharacterScene::EndScene()
{
}

GameScene CharacterScene::IsFinishedScene()
{
    return status;
}
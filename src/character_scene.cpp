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
    c_menu_bg = LoadTexture("assets/sprites/c_bg.png");
    button_font = LoadFontEx("assets/fonts/VT323.ttf", 20, 0, 0);
}

void CharacterScene::UpdateScene()
{
    back_dimensions = MeasureTextEx(button_font, "Back", 20, 1);
    start_dimensions = MeasureTextEx(button_font, "Start", 20, 1);
    // Check UI elements
    // Back button
    if (CheckCollisionPointRec(GetMousePosition(), back_container))
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            back_color = PRESSED;
            status = MENU;
        }
        else
            back_color = FOCUSED;
    }
    else
        back_color = NORMAL;
    // Start button
    if (CheckCollisionPointRec(GetMousePosition(), start_container))
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            start_color = PRESSED;
            status = GAMESCREEN;
        }
        else
            start_color = FOCUSED;
    }
    else
        start_color = NORMAL;
}

void CharacterScene::DrawScene()
{
    // Background and UI Elements
    DrawTexture(c_menu_bg, 0, 0, WHITE);

    // Back Button
    DrawRectangleLinesEx(back_container, 1.0, back_color);
    DrawTextEx(button_font, "Back", Vector2{(SCREEN_WIDTH / 8) - (back_dimensions.x / 2), (SCREEN_HEIGHT / 1.25f)}, 20, 1, back_color);
    // Start Button
    DrawRectangleLinesEx(start_container, 1.0, start_color);
    DrawTextEx(button_font, "Start", Vector2{(SCREEN_WIDTH / 1.25f) - (start_dimensions.x / 2), (SCREEN_HEIGHT / 1.25f)}, 20, 1, start_color);
}

void CharacterScene::EndScene()
{
    status = UNDEFINED;
    UnloadTexture(c_menu_bg);
    UnloadFont(button_font);
}

GameScene CharacterScene::IsFinishedScene()
{
    return status;
}
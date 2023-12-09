#include "option_scene.h"

OptionScene::OptionScene()
{
}

OptionScene::~OptionScene()
{
}

void OptionScene::StartScene()
{
    status = UNDEFINED;
    o_menu_bg = LoadTexture("assets/sprites/o_bg.png");
    button_font = LoadFontEx("assets/fonts/VT323.ttf", 20, 0, 0);
}

void OptionScene::UpdateScene()
{
    back_dimensions = MeasureTextEx(button_font, "Back", 20, 1);
    apply_dimensions = MeasureTextEx(button_font, "Apply", 20, 1);
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
    // Apply button
    if (CheckCollisionPointRec(GetMousePosition(), apply_container))
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            apply_color = PRESSED;
        }
        else
            apply_color = FOCUSED;
    }
    else
        apply_color = NORMAL;
}

void OptionScene::DrawScene()
{
    // Background and UI Elements
    DrawTexture(o_menu_bg, 0, 0, WHITE);

    // Back Button
    DrawRectangleLinesEx(back_container, 1.0, back_color);
    DrawTextEx(button_font, "Back", Vector2{(SCREEN_WIDTH / 8) - (back_dimensions.x / 2), (SCREEN_HEIGHT / 1.25f)}, 20, 1, back_color);
    // Apply Button
    DrawRectangleLinesEx(apply_container, 1.0, apply_color);
    DrawTextEx(button_font, "Apply", Vector2{(SCREEN_WIDTH / 1.25f) - (apply_dimensions.x / 2), (SCREEN_HEIGHT / 1.25f)}, 20, 1, apply_color);
}

void OptionScene::EndScene()
{
    status = UNDEFINED;
    UnloadTexture(o_menu_bg);
    UnloadFont(button_font);
}

GameScene OptionScene::IsFinishedScene()
{
    return status;
}
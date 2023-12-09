#include "menu_scene.h"

MenuScene::MenuScene()
{
}

MenuScene::~MenuScene()
{
}

void MenuScene::StartScene()
{
    status = UNDEFINED;
    menu_bg = LoadTexture("assets/sprites/bg.png");
    menu_font = LoadFontEx("assets/fonts/VT323.ttf", 20, 0, 0);
    SetTextureFilter(menu_font.texture, TEXTURE_FILTER_POINT);
}

void MenuScene::UpdateScene()
{
    title_dimensions = MeasureTextEx(menu_font, "Stellar Drift", 30, 2);
    new_game_dimensions = MeasureTextEx(menu_font, "New Game", 20, 1);
    continue_game_dimensions = MeasureTextEx(menu_font, "Continue", 20, 1);
    options_dimensions = MeasureTextEx(menu_font, "Options", 20, 1);
    quit_dimensions = MeasureTextEx(menu_font, "Quit", 20, 1);
    // Check UI elements
    // New Game button
    if (CheckCollisionPointRec(GetMousePosition(), new_game_container))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            new_game_color = PRESSED;
            status = CHARACTERCREATOR;
        }
        else
            new_game_color = FOCUSED;
    }
    else
        new_game_color = NORMAL;
    // Continue Game button
    if (CheckCollisionPointRec(GetMousePosition(), continue_game_container))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            continue_game_color = PRESSED;
            status = UNDEFINED;
        }
        else
            continue_game_color = FOCUSED;
    }
    else
        continue_game_color = NORMAL;
    // Options button
    if (CheckCollisionPointRec(GetMousePosition(), options_container))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            options_color = PRESSED;
            status = OPTIONS;
        }
        else
            options_color = FOCUSED;
    }
    else
        options_color = NORMAL;
    // Quit button
    if (CheckCollisionPointRec(GetMousePosition(), quit_container))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            quit_color = PRESSED;
            status = QUIT;
        }
        else
            quit_color = FOCUSED;
    }
    else
        quit_color = NORMAL;
}

void MenuScene::DrawScene()
{
    // Background and UI Elements
    DrawTexture(menu_bg, 0, 0, WHITE);
    // Title
    DrawTextEx(menu_font, "Stellar Drift", Vector2{(SCREEN_WIDTH / 2) - (title_dimensions.x / 2), (SCREEN_HEIGHT/8)}, 30, 1, WHITE);
    // New Game Button
    DrawRectangleLinesEx(new_game_container, 1.0, new_game_color);
    DrawTextEx(menu_font, "New Game", Vector2{(SCREEN_WIDTH / 2) - (new_game_dimensions.x / 2), (SCREEN_HEIGHT / 2)}, 20, 1, new_game_color);
    // Continue Button
    DrawRectangleLinesEx(continue_game_container, 1.0, continue_game_color);
    DrawTextEx(menu_font, "Continue", Vector2{(SCREEN_WIDTH / 2) - (continue_game_dimensions.x / 2), (SCREEN_HEIGHT / 2) + 30}, 20, 1, continue_game_color);
    // Options Button
    DrawRectangleLinesEx(options_container, 1.0, options_color);
    DrawTextEx(menu_font, "Options", Vector2{(SCREEN_WIDTH / 2) - (options_dimensions.x / 2), (SCREEN_HEIGHT / 2) + 60}, 20, 1, options_color);
    // Quit Button
    DrawRectangleLinesEx(quit_container, 1.0, quit_color);
    DrawTextEx(menu_font, "Quit", Vector2{(SCREEN_WIDTH / 2) - (quit_dimensions.x / 2), (SCREEN_HEIGHT / 2) + 90}, 20, 1, quit_color);
}

void MenuScene::EndScene()
{
    UnloadTexture(menu_bg);
    UnloadFont(menu_font);
}

GameScene MenuScene::IsFinishedScene()
{
    return status;
}
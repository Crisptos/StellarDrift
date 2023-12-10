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
    has_name = false;
    name_warning = false;
    c_menu_bg = LoadTexture("assets/sprites/c_bg.png");
    button_font = LoadFontEx("assets/fonts/VT323.ttf", 20, 0, 0);
    label_font = LoadFontEx("assets/fonts/VT323.ttf", 24, 0, 0);
    SetTextureFilter(button_font.texture, TEXTURE_FILTER_POINT);
    SetTextureFilter(label_font.texture, TEXTURE_FILTER_POINT);
}

void CharacterScene::UpdateScene()
{
    back_dimensions = MeasureTextEx(button_font, "Back", 20, 1);
    start_dimensions = MeasureTextEx(button_font, "Start", 20, 1);
    name_label_dimensions = MeasureTextEx(button_font, "Enter Your Name", 24, 1);
    name_input_dimensions = MeasureTextEx(button_font, player_name.c_str(), 20, 1);
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
            if (has_name)
                status = GAMESCREEN;
            else
                name_warning = true;
        }
        else
            start_color = FOCUSED;
    }
    else
        start_color = NORMAL;

    // Name Input Field
    if (CheckCollisionPointRec(GetMousePosition(), name_input_container))
    {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
        name_input_color = FOCUSED;
        int key = GetCharPressed(); // Get typed key in queue
        while (key > 0)
        {
            // Stay in range of 32 - 125
            if ((key >= 32) && (key <= 125) && player_name.size() < NAME_LIMIT)
            {
                player_name.push_back((char)key);
            }
            key = GetCharPressed();
        }
        // Erase string one char at a time if backspace
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            if (player_name.size() > 0)
            {
                player_name.pop_back();
            }
        }
    }
    else
    {
        name_input_color = NORMAL;
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }

    // Update warning label and timer
    if (player_name.size() > 0)
        has_name = true;
    else
        has_name = false;

    UpdateTimer(&label_timer); // Not working right now
    if (TimerDone(label_timer))
        name_warning = false;
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
    DrawTextEx(button_font, "Start", Vector2{(SCREEN_WIDTH / 1.15f) - (start_dimensions.x / 2), (SCREEN_HEIGHT / 1.25f)}, 20, 1, start_color);
    // Name Input Label
    DrawTextEx(label_font, "Enter Your Name", Vector2{(SCREEN_WIDTH / 2) - (name_label_dimensions.x / 2), SCREEN_HEIGHT / 3.5f}, 24, 1, WHITE);
    // Draw the warning that the player needs a name if conditions are true
    if (name_warning)
    {
        // StartTimer(&label_timer, 5.0);
        DrawTextEx(label_font, "Please enter a name...", Vector2{SCREEN_WIDTH / 2.2, SCREEN_HEIGHT / 3}, 24, 1, WHITE);
    }
    // Name Input Field
    DrawRectangleLinesEx(name_input_container, 1.0, name_input_color);
    DrawTextEx(button_font, player_name.c_str(), Vector2{(SCREEN_WIDTH / 2) - (name_input_dimensions.x / 2), SCREEN_HEIGHT / 3}, 20, 1, name_input_color);
}

void CharacterScene::EndScene()
{
    status = UNDEFINED;
    player_name.clear();
    UnloadTexture(c_menu_bg);
    UnloadFont(button_font);
    UnloadFont(label_font);
}

GameScene CharacterScene::IsFinishedScene()
{
    return status;
}

Player CharacterScene::GetPlayerInfo()
{
    return Player{
        player_name,
        0};
}
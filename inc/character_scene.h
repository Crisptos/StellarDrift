#pragma once
#include <string>
#include "scene.h"
#include "character_info.h"

#define NAME_LIMIT 18

class CharacterScene : public Scene
{
public:
    // Constructor/Deconstructor
    CharacterScene();
    ~CharacterScene();

    // Scene Management Functions
    void StartScene();
    void UpdateScene();
    void DrawScene();
    void EndScene();
    GameScene IsFinishedScene();

    GameScene status;

    // Not inherited from interface
    Player GetPlayerInfo();

private:

    // Asset fields
    Texture2D c_menu_bg;

    // UI
    Font button_font;
    Font label_font;
    // Back Button
    Rectangle back_container = Rectangle{SCREEN_WIDTH / 8 - 50, SCREEN_HEIGHT / 1.25f, BTN_WIDTH, BTN_HEIGHT};
    Vector2 back_dimensions;
    Color back_color;
    // Start Button
    Rectangle start_container = Rectangle{SCREEN_WIDTH / 1.15f - 50, SCREEN_HEIGHT / 1.25f, BTN_WIDTH, BTN_HEIGHT};
    Vector2 start_dimensions;
    Color start_color;
    // Name Input Field
    Rectangle name_input_container = Rectangle{SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/3, TEXT_FIELD_WIDTH, TEXT_FIELD_HEIGHT};
    Vector2 name_input_dimensions;
    Color name_input_color;
    Vector2 name_label_dimensions;
    // Name Warning
    Timer label_timer;

    // Character Creation Data State Management
    bool has_name;
    bool name_warning;

    // Character Creation Data
    std::string player_name;
};

// Globally accessible to main
extern CharacterScene character_creator;
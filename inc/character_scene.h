#pragma once
#include <string>
#include "scene.h"

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

private:
    // Asset fields
    Texture2D c_menu_bg;

    // UI
    Font button_font;
    // Back Button
    Rectangle back_container = Rectangle{SCREEN_WIDTH / 8 - 50, SCREEN_HEIGHT / 1.25f, BTN_WIDTH, BTN_HEIGHT};
    Vector2 back_dimensions;
    Color back_color;
    // Start Button
    Rectangle start_container = Rectangle{SCREEN_WIDTH / 1.25f - 50, SCREEN_HEIGHT / 1.25f, BTN_WIDTH, BTN_HEIGHT};
    Vector2 start_dimensions;
    Color start_color;

    // Character Creation Data
    std::string player_name;
};

// Globally accessible to main
extern CharacterScene character_creator;
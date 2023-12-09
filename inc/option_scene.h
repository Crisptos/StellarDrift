#pragma once
#include "scene.h"

class OptionScene : public Scene
{
public:
    // Constructor/Deconstructor
    OptionScene();
    ~OptionScene();

    // Scene Management Functions
    void StartScene();
    void UpdateScene();
    void DrawScene();
    void EndScene();
    GameScene IsFinishedScene();

    GameScene status;

private:
    // Asset fields
    Texture2D o_menu_bg;

    // UI
    Font button_font;

    // Back Button
    Rectangle back_container = Rectangle{SCREEN_WIDTH / 8 - 50, SCREEN_HEIGHT / 1.25f, BTN_WIDTH, BTN_HEIGHT};
    Vector2 back_dimensions;
    Color back_color;
    // Apply Button
    Rectangle apply_container = Rectangle{SCREEN_WIDTH / 1.25f - 50, SCREEN_HEIGHT / 1.25f, BTN_WIDTH, BTN_HEIGHT};
    Vector2 apply_dimensions;
    Color apply_color;
};

// Globally accessible to main
extern OptionScene option_menu;
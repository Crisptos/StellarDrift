#pragma once
#include "scene.h"

class MenuScene : public Scene
{
public:
    // Constructor/Deconstructor
    MenuScene();
    ~MenuScene();

    // Scene Management Functions
    void StartScene();
    void UpdateScene();
    void DrawScene();
    void EndScene();
    GameScene IsFinishedScene();

    GameScene status;

private:

    // Asset fields
    Texture2D menu_bg;
    Texture2D base_btn;
    Sound btn_fx;
    Sound bg_music;

    // UI
    Font button_font;
    Font title_font;
    // Title
    Vector2 title_dimensions;
    // New Game
    Rectangle new_game_container = Rectangle{SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2, BTN_WIDTH, BTN_HEIGHT};
    Vector2 new_game_dimensions;
    Color new_game_color;
    // Continue Game
    Rectangle continue_game_container = Rectangle{SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 + 30, BTN_WIDTH, BTN_HEIGHT};
    Vector2 continue_game_dimensions;
    Color continue_game_color;
    // Options
    Rectangle options_container = Rectangle{SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 + 60, BTN_WIDTH, BTN_HEIGHT};
    Vector2 options_dimensions;
    Color options_color;
    // Quit
    Rectangle quit_container = Rectangle{SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 + 90, BTN_WIDTH, BTN_HEIGHT};
    Vector2 quit_dimensions;
    Color quit_color;
};

// Globally accessible to main
extern MenuScene main_menu;
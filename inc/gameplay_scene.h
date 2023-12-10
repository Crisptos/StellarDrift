#pragma once
#include "character_info.h"
#include "scene.h"

class GameplayScene : public Scene
{
public:
    // Constructor/Deconstructor
    GameplayScene();
    ~GameplayScene();

    // Scene Management Functions
    void StartScene();
    void UpdateScene();
    void DrawScene();
    void EndScene();
    GameScene IsFinishedScene();

    GameScene status;

    // Not inherited from interface
    void SetPlayerInfo(Player player);

private:

    // Drawing/Updating functions specific to certain components of the scene
    void UpdateScene2D();
    void UpdateSceneUI();
    void DrawScene2D();
    void DrawSceneUI();

    // Player Data
    Player player;

    // UI
    Font button_font;
    Font label_font;
    Font panel_font;

    // Intro Panel
    bool show_intro;
    Rectangle intro_panel = Rectangle{SCREEN_WIDTH/32, SCREEN_HEIGHT/32, SCREEN_WIDTH-64, SCREEN_HEIGHT-48};


};

// Globally accessible to main
extern GameplayScene game;
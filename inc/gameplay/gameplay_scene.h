#pragma once
#include "scene.h"
#include "gameplay/world_gen.h"
#include "gameplay/player.h"

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

    // Gameworld Related
    // _________________________
    // Sprite Atlas
    Texture2D sprite_atlas;
    // Tiled world
    std::vector<Tile> map;
    // Player Data
    Player* player;

    // 2D Camera
    Camera2D camera = Camera2D{0};
    // _________________________

    // UI Related
    // _________________________
    // UI
    Font button_font;
    Font label_font;
    Font panel_font;

    // Intro Panel
    bool show_intro;
    Rectangle intro_panel = Rectangle{SCREEN_WIDTH / 32, SCREEN_HEIGHT / 32, SCREEN_WIDTH - 64, SCREEN_HEIGHT - 48};
    // _________________________
};

// Globally accessible to main
extern GameplayScene game;
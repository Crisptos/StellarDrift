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
    Player player;


};

// Globally accessible to main
extern GameplayScene game;
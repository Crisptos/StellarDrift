#pragma once
#include <raylib.h>
#include "config.h"

// UI color
const Color NORMAL = Color{255, 255, 255, 255};
const Color PRESSED = Color{112, 50, 128, 255};
const Color FOCUSED = Color{219, 128, 242, 255};

enum GameScene
{
    UNDEFINED = -1,
    QUIT,
    MENU,
    CHARACTERCREATOR,
    OPTIONS,
    GAMESCREEN,
};

class Scene
{
public:
    virtual void StartScene() = 0;
    virtual void UpdateScene() = 0;
    virtual void DrawScene() = 0;
    virtual void EndScene() = 0;
    virtual GameScene IsFinishedScene() = 0;

    GameScene status;
};
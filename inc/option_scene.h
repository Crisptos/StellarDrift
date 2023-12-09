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

    // UI
    Font menu_font;
};

// Globally accessible to main
extern OptionScene option_menu;
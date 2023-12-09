#pragma once
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
    Texture2D menu_bg;
    
    // UI
    Font menu_font;
};

// Globally accessible to main
extern CharacterScene character_creator;
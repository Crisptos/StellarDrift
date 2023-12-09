#include <vector>

#include "menu_scene.h"
#include "character_scene.h"
#include "option_scene.h"

// Global Extern Fields
MenuScene main_menu;
CharacterScene character_creator;
OptionScene option_menu;

// Local Fields
// Scene state management
static bool exit_window = false;

static GameScene current_scene;
static GameScene target_scene;
static GameScene change_from_scene;

// Transition management
static bool is_transitioning;
static float transition_alpha;

// Function Prototypes
void NoTransitionToScreen(GameScene scene); // Change to scene without transition effect
void UpdateTransition();                    // Update transition effect
void DrawTransition();                      // Draw transition effect
void TransitionToScreen(GameScene scene);   // Change to scene and start transition effect

void UpdateDrawFrame(); // Update the current frame and draw it
// ___________________

void NoTransitionToScreen(GameScene scene)
{
    // Unload current scene
    switch (current_scene)
    {
    case MENU:
        main_menu.EndScene();
        break;
    }

    switch (scene)
    {
    case CHARACTERCREATOR:
        character_creator.StartScene();
        break;
    case OPTIONS:
        option_menu.StartScene();
        break;
    }

    current_scene = scene;
}

void UpdateTransition()
{
}

void DrawTransition()
{
}

void TransitionToScreen(GameScene scene)
{
}

void UpdateDrawFrame()
{
    // First check for which is the current scene and update its variables
    if (!is_transitioning)
    {
        // Main Loop
        switch (current_scene)
        {
        case MENU:
            main_menu.UpdateScene();
            // Sub Loop: check if the current scene has indicated to change to another scene
            switch (main_menu.IsFinishedScene())
            {
            case CHARACTERCREATOR:
                NoTransitionToScreen(CHARACTERCREATOR);
                break;

            case OPTIONS:
                NoTransitionToScreen(OPTIONS);
                break;
            case QUIT:
                exit_window = true;
                break;
            }
            break;

        case CHARACTERCREATOR:
            character_creator.UpdateScene();
        case OPTIONS:
            option_menu.UpdateScene();
        }
    }
    else
        UpdateTransition(); // Fade in fade out

    // Draw current scene
    BeginDrawing();
    ClearBackground(BLACK);

    switch (current_scene)
    {
    case MENU:
        main_menu.DrawScene();
        break;

    case CHARACTERCREATOR:
        character_creator.DrawScene();
        break;

    case OPTIONS:
        option_menu.DrawScene();
        break;

    default:
        break;
    }

    if (is_transitioning)
        DrawTransition();

    EndDrawing();

    // Update current scene
}

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Stellar Drift");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    // Initialize scene variables to start at the main menu
    current_scene = MENU;
    is_transitioning = false;
    main_menu.StartScene();

    while (!WindowShouldClose() && !exit_window) // Detect window close button or ESC key
    {
        UpdateDrawFrame();
    }

    // Unload current scene
    switch (current_scene)
    {
    case MENU:
        main_menu.EndScene();
        break;
    case CHARACTERCREATOR:
        character_creator.EndScene();
        break;
    }

    CloseWindow();
    return 0;
}
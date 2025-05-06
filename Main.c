#include "raylib.h"
#include "MainMenu.h"
#include <stdio.h>
#include "Player.h"

typedef enum GameState {
    STATE_NAME_INPUT,  
    STATE_MAIN_MENU,
    STATE_GAME,
    STATE_EXIT

} GameState;

int main(void)
{
    const int screenWidth = GetMonitorWidth(0);
    const int screenHeight = GetMonitorHeight(0);

    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "My Game");
    SetTargetFPS(60);

    GameState currentState = STATE_NAME_INPUT;  
    MainMenu menu;
    MainMenu_Load(&menu);

    menu.showNameInput = true;

    Player player;

    while (!WindowShouldClose() && currentState != STATE_EXIT)
    {
        BeginDrawing();
        ClearBackground(BLACK);

        switch (currentState)
        {
        case STATE_NAME_INPUT:
            MainMenu_ShowNameInput(&menu);

            if (menu.nameLength > 0 && menu.start_Game)
            {
                currentState = STATE_MAIN_MENU;
                menu.start_Game = false;
                menu.showNameInput = false;
            }
            else if (IsKeyPressed(KEY_B))
            {
                menu.showNameInput = false;
                currentState = STATE_MAIN_MENU;
            }
            break;

        case STATE_MAIN_MENU:
            MainMenu_LandingPage(&menu);

            if (CheckCollisionPointRec(GetMousePosition(), menu.startButton_position) &&
                IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                if (menu.nameLength > 0)
                {
                    Player_Init(&player, menu.playerName);
                    currentState = STATE_GAME;
                }
                else
                {
                    menu.showNameInput = true;
                    currentState = STATE_NAME_INPUT;
                }
            }

            if (menu.showKeyBindings)
            {
                MainMenu_ShowKeyBindings(&menu);
            }

            if (menu.exit_Game)
            {
                currentState = STATE_EXIT;
            }
            break;

        case STATE_GAME:
            DrawRectangle(0, 0, screenWidth, screenHeight, DARKGRAY);
            DrawText("Game Screen", screenWidth / 2 - MeasureText("Game Screen", 40) / 2, screenHeight / 2 - 40, 40, WHITE);
            DrawText(TextFormat("Player: %s", menu.playerName), screenWidth / 2 - MeasureText(TextFormat("Player: %s", menu.playerName), 30) / 2, screenHeight / 2 - 80, 30, WHITE);
            DrawText("Press ESC to return to menu", screenWidth / 2 - MeasureText("Press ESC to return to menu", 20) / 2, screenHeight / 2 + 20, 20, WHITE);

            if (IsKeyPressed(KEY_ESCAPE))
            {
                currentState = STATE_MAIN_MENU;
            }
            break;

        default:
            break;
        }

        EndDrawing();
    }

    MainMenu_Unload(&menu);
    CloseWindow();
    return 0;
}
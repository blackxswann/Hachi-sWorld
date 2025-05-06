#include "raylib.h"
#include "MainMenu.h"
#include <string.h>
#include "Player.h"

void MainMenu_Load(MainMenu* menu)
{
    menu->background_texture = LoadTexture("Resources/mainBackground1.png");
    menu->startButton_texture = LoadTexture("Resources/StartGameButton.png");
    menu->exitButton_texture = LoadTexture("Resources/ExitGameButton.png");
    menu->keyBindings_texture = LoadTexture("Resources/KeyBindingsButton.png");
    menu->keyBindingsGuide_texture = LoadTexture("Resources/keybindings_BG.png");
    menu->enterName_texture = LoadTexture("Resources/EnterNameBG.png");

    menu->startButton_rectangle = (Rectangle){ 0, 0, 427, 66 };
    menu->keyBindings_rectangle = (Rectangle){ 0, 0, 427, 66 };
    menu->exitButton_rectangle = (Rectangle){ 0, 0, 427, 66 };

    menu->startButton_position = (Rectangle){ GetScreenWidth() / 2 - 213, GetScreenHeight() / 2 - 100, 427, 66 };
    menu->keyBindings_position = (Rectangle){ GetScreenWidth() / 2 - 213, GetScreenHeight() / 2, 427, 66 };
    menu->exitButton_position = (Rectangle){ GetScreenWidth() / 2 - 213, GetScreenHeight() / 2 + 100, 427, 66 };

    menu->nameInputBox = (Rectangle){ GetScreenWidth() / 2 - 200, 520, 400, 50 };

    strcpy_s(menu->playerName, MAX_NAME_LENGTH, "");
    menu->nameLength = 0;
    menu->nameInputActive = false;

    menu->start_Game = false;
    menu->exit_Game = false;
    menu->showKeyBindings = false;
    menu->showNameInput = false;  
    menu->pause_Game = false;
}

void MainMenu_Unload(MainMenu* menu)
{
    UnloadTexture(menu->background_texture);
    UnloadTexture(menu->startButton_texture);
    UnloadTexture(menu->exitButton_texture);
    UnloadTexture(menu->keyBindings_texture);
    UnloadTexture(menu->keyBindingsGuide_texture);
    UnloadTexture(menu->enterName_texture);
}

void MainMenu_UpdateStartButton(MainMenu* menu)
{
    if (CheckCollisionPointRec(GetMousePosition(), menu->startButton_position))
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            menu->showNameInput = true;
        }

        DrawTexturePro(
            menu->startButton_texture,
            menu->startButton_rectangle,
            menu->startButton_position,
            (Vector2) {
            0, 0
        },
            0.0f,
            YELLOW
        );
    }
    else
    {
        DrawTexturePro(
            menu->startButton_texture,
            menu->startButton_rectangle,
            menu->startButton_position,
            (Vector2) {
            0, 0
        },
            0.0f,
            WHITE
        );
    }
}

void MainMenu_UpdateKeyBindingsButton(MainMenu* menu)
{
    if (CheckCollisionPointRec(GetMousePosition(), menu->keyBindings_position))
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            menu->showKeyBindings = true;
        }

        // Draw key bindings button with highlight
        DrawTexturePro(
            menu->keyBindings_texture,
            menu->keyBindings_rectangle,
            menu->keyBindings_position,
            (Vector2) {
            0, 0
        },
            0.0f,
            YELLOW  // Highlighted color
        );
    }
    else
    {
        // Draw key bindings button normal
        DrawTexturePro(
            menu->keyBindings_texture,
            menu->keyBindings_rectangle,
            menu->keyBindings_position,
            (Vector2) {
            0, 0
        },
            0.0f,
            WHITE  // Normal color
        );
    }
}

void MainMenu_UpdateExitButton(MainMenu* menu)
{
    // Check if mouse is over exit button
    if (CheckCollisionPointRec(GetMousePosition(), menu->exitButton_position))
    {
        // Check for mouse click
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            menu->exit_Game = true;
        }

        // Draw exit button with highlight
        DrawTexturePro(
            menu->exitButton_texture,
            menu->exitButton_rectangle,
            menu->exitButton_position,
            (Vector2) {
            0, 0
        },
            0.0f,
            YELLOW  // Highlighted color
        );
    }
    else
    {
        // Draw exit button normal
        DrawTexturePro(
            menu->exitButton_texture,
            menu->exitButton_rectangle,
            menu->exitButton_position,
            (Vector2) {
            0, 0
        },
            0.0f,
            WHITE  // Normal color
        );
    }

}


void MainMenu_ShowNameInput(MainMenu* menu)
{
    DrawTexturePro(
        menu->enterName_texture,
        (Rectangle) {
        0, 0, menu->enterName_texture.width, menu->enterName_texture.height
    },
        (Rectangle) {
        0, 0, GetScreenWidth(), GetScreenHeight()
    },
        (Vector2) {
        0, 0
    },
        0.0f,
        WHITE
    );

    DrawText("Enter Your Display Name",
        700,
        450,
        40,
        WHITE);

    Color boxColor = menu->nameInputActive ? SKYBLUE : LIGHTGRAY;
    DrawRectangleRec(menu->nameInputBox, boxColor);
    DrawRectangleLinesEx(menu->nameInputBox, 2, menu->nameInputActive ? BLUE : GRAY);

    DrawText("Play as:",
        menu->nameInputBox.x - MeasureText("Play as:", 30) - 20,
        530,
        30,
        WHITE);

    DrawText(menu->playerName,
        menu->nameInputBox.x + 10,
        535,
        20,
        BLACK);

    if (menu->nameInputActive) {
        DrawText("_",
            menu->nameInputBox.x + 10 + MeasureText(menu->playerName, 20),
            540,
            20,
            BLACK);
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        menu->nameInputActive = CheckCollisionPointRec(GetMousePosition(), menu->nameInputBox);
    }

    if (menu->nameInputActive) {
        int key = GetCharPressed();

        if (IsKeyPressed(KEY_BACKSPACE) && menu->nameLength > 0) {
            menu->nameLength--;
            menu->playerName[menu->nameLength] = '\0';
        }

        if (key > 0 && menu->nameLength < MAX_NAME_LENGTH) {
            if ((key >= 32 && key <= 125) || key == 95) {  
                menu->playerName[menu->nameLength] = (char)key;
                menu->nameLength++;
                menu->playerName[menu->nameLength] = '\0';
            }
        }
    }

    Rectangle continueButton = { GetScreenWidth() / 2 - 100, menu->nameInputBox.y + 70, 200, 30 };
    bool overContinue = CheckCollisionPointRec(GetMousePosition(), continueButton);

    DrawRectangleRec(continueButton, overContinue ? SKYBLUE : BLUE);
    DrawText("Continue",
        continueButton.x + continueButton.width / 2 - MeasureText("Continue", 20) / 2,
        continueButton.y + continueButton.height / 2 - 10,
        20,
        WHITE);

    if (overContinue && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (menu->nameLength > 0) {  
            menu->start_Game = true;
            menu->showNameInput = false;
        }
    }
}
void MainMenu_LandingPage(MainMenu* menu)
{
    DrawTexturePro(
        menu->background_texture,
        (Rectangle) {
        0, 0, menu->background_texture.width, menu->background_texture.height
    },
        (Rectangle) {
        0, 0, GetScreenWidth(), GetScreenHeight()
    },
        (Vector2) {
        0, 0
    },
        0.0f,
        WHITE
    );

    MainMenu_UpdateStartButton(menu);
    MainMenu_UpdateKeyBindingsButton(menu);
    MainMenu_UpdateExitButton(menu);
}

void MainMenu_ShowKeyBindings(MainMenu* menu)
{
    DrawTexturePro(
        menu->keyBindingsGuide_texture,
        (Rectangle) {
        0, 0,
            menu->keyBindingsGuide_texture.width,
            menu->keyBindingsGuide_texture.height
    },
        (Rectangle) {
        0, 0,
            GetScreenWidth(),
            GetScreenHeight()
    },
        (Vector2) {
        0, 0
    },
        0.0f,
        WHITE
    );

    DrawText("Press B to go back", 830, GetScreenHeight() - 100, 25, WHITE);

    if (IsKeyPressed(KEY_B))
    {
        menu->showKeyBindings = false;
    }
}

void MainMenu_Update(MainMenu* menu)
{
    if (menu->showKeyBindings)
    {
        MainMenu_ShowKeyBindings(menu);
    }
    else if (menu->showNameInput)
    {
        MainMenu_ShowNameInput(menu);
    }
    else
    {
        MainMenu_LandingPage(menu);
    }

    if (IsKeyPressed(KEY_ESCAPE) && menu->start_Game)
    {
        menu->pause_Game = !menu->pause_Game;
    }
}
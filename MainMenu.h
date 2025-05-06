#ifndef MAINMENU_H
#define MAINMENU_H

#include "raylib.h"

#define MAX_NAME_LENGTH 20

typedef struct MainMenu
{
    Texture2D background_texture;
    Texture2D startButton_texture;
    Texture2D exitButton_texture;
    Texture2D keyBindings_texture;
    Texture2D keyBindingsGuide_texture;
    Texture2D enterName_texture;

    Rectangle startButton_rectangle;
    Rectangle keyBindings_rectangle;
    Rectangle exitButton_rectangle;

    Rectangle startButton_position;
    Rectangle keyBindings_position;
    Rectangle exitButton_position;

    Rectangle nameInputBox;
    char playerName[MAX_NAME_LENGTH + 1];
    int nameLength;
    bool nameInputActive;

    bool start_Game;
    bool exit_Game;
    bool showKeyBindings;
    bool showNameInput;
    bool pause_Game;
} MainMenu;

void MainMenu_Load(MainMenu* menu);
void MainMenu_Unload(MainMenu* menu);
void MainMenu_Update(MainMenu* menu);
void MainMenu_LandingPage(MainMenu* menu);
void MainMenu_ShowKeyBindings(MainMenu* menu);
void MainMenu_ShowNameInput(MainMenu* menu);
void MainMenu_UpdateStartButton(MainMenu* menu);
void MainMenu_UpdateKeyBindingsButton(MainMenu* menu);
void MainMenu_UpdateExitButton(MainMenu* menu);

#endif // MAINMENU_H
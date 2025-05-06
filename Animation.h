#pragma once
#include "raylib.h"

typedef struct Animation {
    Texture2D player_texture_idle;
    Texture2D player_texture_walk;
    Texture2D player_texture_run;
    Texture2D player_texture_jump;

    Rectangle player_frame_idle;
    Rectangle player_frame_walk;
    Rectangle player_frame_run;
    Rectangle player_frame_jump;

    Rectangle player_position;

    int timer_playerIdle;
    int timer_playerWalk;
    int timer_playerRun;
    int timer_playerJump;
} Animation;

void Animation_Load(Animation* anim);
void Animation_Unload(Animation* anim);

void AnimationPlayer_runLeft(Animation* anim);
void AnimationPlayer_runRight(Animation* anim);
void AnimationPlayer_idleLeft(Animation* anim);
void AnimationPlayer_idleRight(Animation* anim);
void AnimationPlayer_walkLeft(Animation* anim);
void AnimationPlayer_walkRight(Animation* anim);

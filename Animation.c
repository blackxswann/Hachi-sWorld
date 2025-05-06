#include "raylib.h"
#include "Animation.h"

void Animation_Load(Animation* animation)
{
    animation->player_texture_idle = LoadTexture("Resources/graphics/characters/player_idle.png");
    animation->player_texture_walk = LoadTexture("Resources/Hachi.png");
    animation->player_frame_idle = (Rectangle){ 0, 0, 48, 48 };
    animation->player_frame_walk = (Rectangle){ 0, 0, 64, 64 };
    animation->timer_playerIdle = 0;
    animation->timer_playerWalk = 0;
    animation->timer_playerRun = 0;
    animation->timer_playerJump = 0;
}

void Animation_Unload(Animation* animation) 
{
    UnloadTexture(animation->player_texture_idle);
    UnloadTexture(animation->player_texture_walk);
}

void AnimationPlayer_walkRight(Animation* animation) {
    if (animation->timer_playerWalk % 6 == 0) {
        animation->player_frame_walk.x += animation->player_frame_walk.width; 
        if (animation->player_frame_walk.x >= animation->player_texture_walk.width)
            animation->player_frame_walk.x = 0;
    }
    animation->timer_playerWalk = (animation->timer_playerWalk + 1) % 30;

    Rectangle dest = {
        animation->player_position.x,
        animation->player_position.y,
        animation->player_position.width,
        animation->player_position.height
    };

    Vector2 origin = { 0, 0 }; 

    DrawTexturePro(
        animation->player_texture_walk,
        animation->player_frame_walk,
        dest,
        origin,
        0.0f,
        WHITE
    );
}
void AnimationPlayer_walkLeft(Animation* animation) {
    if (animation->timer_playerWalk % 6 == 0) {
        animation->player_frame_walk.x += animation->player_frame_walk.width;
        if (animation->player_frame_walk.x >= animation->player_texture_walk.width)
            animation->player_frame_walk.x = 0;
    }
    animation->timer_playerWalk = (animation->timer_playerWalk + 1) % 30;

    Rectangle dest = {
        animation->player_position.x,
        animation->player_position.y,
        animation->player_position.width,
        animation->player_position.height
    };


    dest.width = -dest.width;
    dest.x += dest.width; 

    Vector2 origin = { 0, 0 }; 

    DrawTexturePro(
        animation->player_texture_walk,
        animation->player_frame_walk,
        dest,
        origin,
        0.0f,
        WHITE
    );
}

void AnimationPlayer_idleRight(Animation* animation) {
    if (animation->timer_playerIdle % 10 == 0) {
        animation->player_frame_idle.x += animation->player_frame_idle.width;
        if (animation->player_frame_idle.x >= animation->player_texture_idle.width)
            animation->player_frame_idle.x = 0;
    }
    animation->timer_playerIdle = (animation->timer_playerIdle + 1) % 60;

    Rectangle dest = {
        animation->player_position.x,
        animation->player_position.y,
        animation->player_position.width,
        animation->player_position.height
    };

    Vector2 origin = { 0, 0 };

    DrawTexturePro(
        animation->player_texture_idle,
        animation->player_frame_idle,
        dest,
        origin,
        0.0f,
        WHITE
    );
}

void AnimationPlayer_idleLeft(Animation* animation) {
    if (animation->timer_playerIdle % 10 == 0) {
        animation->player_frame_idle.x += animation->player_frame_idle.width;
        if (animation->player_frame_idle.x >= animation->player_texture_idle.width)
            animation->player_frame_idle.x = 0;
    }
    animation->timer_playerIdle = (animation->timer_playerIdle + 1) % 60;

    Rectangle dest = {
        animation->player_position.x,
        animation->player_position.y,
        animation->player_position.width,
        animation->player_position.height
    };

    dest.width = -dest.width;
    dest.x += dest.width;

    Vector2 origin = { 0, 0 };

    DrawTexturePro(
        animation->player_texture_idle,
        animation->player_frame_idle,
        dest,
        origin,
        0.0f,
        WHITE
    );
}

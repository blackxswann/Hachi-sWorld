#include "Player.h"
#include "Animation.h"

void Player_Init(Player* player, const char* playerName)
{

    strncpy(player->name, playerName, sizeof(player->name) - 1);
    player->name[sizeof(player->name) - 1] = '\0'; 

    player->score = 0;
    player->level = 1;

    player->isWalking_right = false;
    player->isWalking_left = false;
    player->isRunning = false;
    player->hasJumped = false;
    player->hasTurned_right = false;
    player->hasTurned_left = false;
    player->isGoing_up = false;
    player->onFloor = true;
    player->collision = false;
}
void Player_Update(Player* player) {

    if (IsKeyDown(KEY_RIGHT)) {
        player->animation.player_position.x += 5;
        player->isWalking_right = true;
        player->hasTurned_right = true;
        player->hasTurned_left = false;
    }
    else {
        player->isWalking_right = false;
    }

    if (IsKeyDown(KEY_LEFT)) {
        player->animation.player_position.x -= 5;
        player->isWalking_left = true;
        player->hasTurned_left = true;
        player->hasTurned_right = false;
    }
    else {
        
    }

}

void Player_Draw(Player* player) {
    if (player->isWalking_right) {
        AnimationPlayer_walkRight(&player->animation);
    }
    else if (player->isWalking_left) {
        AnimationPlayer_walkLeft(&player->animation);
    }
    else if (player->hasTurned_right) {
        AnimationPlayer_idleRight(&player->animation);
    }
    else if (player->hasTurned_left) {
        AnimationPlayer_idleLeft(&player->animation);
    }
    else
        AnimationPlayer_walkRight(&player->animation);

}
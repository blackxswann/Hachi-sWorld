#pragma once
#include "raylib.h"
#include "Animation.h"	

typedef struct Player
{
	Animation animation;

	Sound deathSound;
	Sound hitSound;
	Sound jumpSound;

	Texture2D heart;

	Rectangle lives_src;
	Rectangle heart_src;
	Rectangle lives_disp;
	Rectangle heart1_disp;
	Rectangle heart2_disp;
	Rectangle heart3_disp;
	Rectangle coll;
	Rectangle foot_coll;

	Color transparent;

	Vector2 score_pos;
	Vector2 lives_pos;
	Vector2 heart1_pos;
	Vector2 heart2_pos;
	Vector2 heart3_pos;
	Vector2 speed;
	Vector2 origin;

	Camera2D camera;

	float gravity;

	bool isWalking_right; 
	bool isWalking_left; 
	bool isRunning;
	bool hasJumped;
	bool hasTurned_right; 
	bool hasTurned_left; 
	bool isGoing_up;
	bool jumpBreak;
	bool moveCamera;

	bool idleRightAnim;
	bool idleLeftAnim;
	bool runRightAnim;
	bool runLeftAnim;
	bool jumpRightAnim;
	bool jumpLeftAnim;

	int hp;
	float lives;
	int score;
	int increment;
	bool death;
	int hitTimer;
	int hitDuration;

	float jumpVolume;
	float deathVolume;
	float hitVolume;
	bool playJumpSound;
} Player;

void Player_Init(Player* player);
void Player_SetAudioVolume(Player* player);
void Player_DrawUI(Player* player);
void Player_CheckInput(Player* player);
void Player_ManageInput(Player* player);
void Player_SetPos1(Player* player);
void Player_SetPos2(Player* player);
void Player_SetPos3(Player* player);
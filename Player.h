#pragma once
#include "raylib.h"
#include "Animation.h"	

typedef struct Player
{
	Animation animation;

	char name[100];

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

	float lives;



	bool onFloor; 
	bool collision; 
	
} Player;
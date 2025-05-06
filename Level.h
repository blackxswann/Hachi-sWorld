#pragma once
#include "Player.h"
//#include "Enemy.h"

//no collectibles included
typedef struct Level {
	Sound dead_sound;
	Sound explosion_sound;
	Sound gameover_sound;
	Sound hit_sound;
	Sound jump_sound;
	Sound levelcompleted_sound;
	Sound loot_sound;
	Sound unlock_sound;

	Music levelOne_music;
	Music levelTwo_music;
	Music levelThree_music;
	Music levelFour_music;

	//Level one
	Texture2D levelOneBackground;

	Texture2D levelOneBridge;

	Texture2D levelOnePlatform_right;
	Texture2D levelOnePlatform_left;
	Texture2D levelOnePlatform_mid;

	Texture2D levelOneGround_topleft;
	Texture2D levelOneGround_topmid;
	Texture2D levelOneGround_topright;
	Texture2D levelOneGround_midleft;
	Texture2D levelOneGround_center;
	Texture2D levelOneGround_midright;

	//Level two
	Texture2D levelTwoBackground;

	Texture2D levelTwoBridge;

	Texture2D levelTwoPlatform_right;
	Texture2D levelTwoPlatform_left;
	Texture2D levelTwoPlatform_mid;

	Texture2D levelTwoGround_topleft;
	Texture2D levelTwoGround_topmid;
	Texture2D levelTwoGround_topright;
	Texture2D levelTwoGround_midleft;
	Texture2D levelTwoGround_center;
	Texture2D levelTwoGround_midright;

	//Level three
	Texture2D levelThreeBackground;
	Texture2D levelThreeBridge;

	Texture2D levelThreePlatform_right;
	Texture2D levelThreePlatform_left;
	Texture2D levelThreePlatform_mid;

	Texture2D levelThreeGround_topleft;
	Texture2D levelThreeGround_topmid;
	Texture2D levelThreeGround_topright;
	Texture2D levelThreeGround_midleft;
	Texture2D levelThreeGround_center;
	Texture2D levelThreeGround_midright;

	//Level four
	Texture2D levelFourBackground;
	Texture2D levelFourBridge;

	Texture2D levelFourPlatform_right;
	Texture2D levelFourPlatform_left;
	Texture2D levelFourPlatform_mid;

	Texture2D levelFourGround_topleft;
	Texture2D levelFourGround_topmid;
	Texture2D levelFourGround_topright;
	Texture2D levelFourGround_midleft;
	Texture2D levelFourGround_center;
	Texture2D levelFourGround_midright;

	Rectangle background_src;
	Rectangle background_disp_1;
	Rectangle background_disp_2;
	Rectangle background_disp_3;
	Rectangle background_disp_4;
	Rectangle background_disp_5;

	Rectangle tile_src;
	Rectangle tile_disp;

	Vector2 gameOver_pos;
	Vector2 levelInit_pos;
	Vector2 origin;

	int levelID;
	bool startLevel;
	bool startPlay;
	bool swap;
	bool levelCompleted;
	bool levelRestart;

	float levelOne_volume;
	float levelTwo_volume;
	float levelThree_volume;
	float levelFour_volume;

	bool got_hit;
	bool damage_timer;
	bool game_over;

	char map[27][240];
	char map_background[27][240];
};

void Level(int id);
void Level_SetAudioVolume();
void Level_Init();
void Level_DrawTiles();
void Level_Draw(Player* player);
void Level_ManageTiles(int i, int j);
void Level_CheckCollisions(Player* player, Animation* animation /*, Enemy* enemy*/);
void Level_ManageCollisions(Player* player, Animation* animation /*, Enemy* enemy*/, int i, int j);
void Level_GameOverScreen(Player* player);
void Level_ManageDeath(Player* player/*, Enemy* enemy*/);
void Level_ResetMusic();

bool CheckCollisionRecsOr(Rectangle rec1, Rectangle rec2, Vector2 origin);

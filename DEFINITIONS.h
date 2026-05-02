#pragma once
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024
#define SPLASH_STATE_SHOW_TIME 3.0
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/bg.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/sk2.png"
#define GAME_BACKGROUND_FILEPATH "Resources/res/sk3.png"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/sk2.png"
#define GAME_TITLE_FILEPATH "Resources/res/tl2.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/bt.png"
#define LAND_FILEPATH "Resources/res/land2.png"
#define PIPE_UP_FILEPATH "Resources/res/down4.png"
#define PIPE_DOWN_FILEPATH "Resources/res/up3.png"
#define SCORING_PIPE_FILEPATH "Resources/res/InvisibleScoringPipe.png"
#define BIRD_FRAM_1_FILEPATH "Resources/res/fram1.png"
#define BIRD_FRAM_2_FILEPATH "Resources/res/fram3.png"
#define BIRD_FRAM_3_FILEPATH "Resources/res/fram2.png"
#define BIRD_FRAM_4_FILEPATH "Resources/res/fram3.png"
#define FLAPPY_FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"
#define GAME_OVER_TITLE_FILEPATH "Resources/res/go.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/ovb.png"
#define BRONZE_MEDAL_FILEPATH "Resources/res/bronze.png"
#define SILVER_MEDAL_FILEPATH "Resources/res/silver.png"
#define GOLD_MEDAL_FILEPATH "Resources/res/gold.png"
#define PLATINUM_MEDAL_FILEPATH "Resources/res/plat.png"
#define HIGH_SCORE_TXT_FILEPATH "Resources/Highscore.txt"
#define HIT_SOUND_FILEPATH "Resources/audio/2.mp3"
#define POINT_SOUND_FILEPATH "Resources/audio/3.mp3"
#define WING_SOUND_FILEPATH "Resources/audio/1.mp3"
#define BACK_GROUND_MUSIC_FILEPATH "Resources/audio/bgmusic.mp3"
#define START_MUSIC_FILEPATH "Resources/audio/startmusic.mp3"
#define BUTTON_SOUND_FILEPATH "Resources/audio/button.mp3"
#define ICON_FILEPATH "Resources/icon.png"
#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 1.5f
#define BIRD_ANIMATION_DURATION 0.8f
#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3
#define GRAVITY 350.0f
#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.25f
#define ROTATION_SPEED 350.0f
#define FLASH_SPEED 1500.0f
#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f
#define BRONZE_MEDAL_SCORE 10
#define SILVER_MEDAL_SCORE 25
#define GOLD_MEDAL_SCORE 50
#define PLATINUM_MEDAL_SCORE 100

enum GameStates {
	eReady,
	ePlaying,
	eGameOver
};
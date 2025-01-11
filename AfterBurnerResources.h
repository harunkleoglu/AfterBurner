#pragma once
#define KEY_HANDLER				keycodes
#define LEFT_KEYCODE			37
#define UP_KEYCODE				38
#define RIGHT_KEYCODE			39
#define DOWN_KEYCODE			40
#define LAST_PRESSED_KEYCODE	ICG_LastKeyPressed()

int keycodes[256];						// Keyboard input ascii values, if true button pressed else not pressed..
int console;							// Console widget handle.

int BG_POS_X = 6;						// Horizontal position of the background.
int BG_POS_Y = 0;						// Vertical position of the background.
int NAVBALL_X = 1157;					// Horizontal position of the navball.
int NAVBALL_Y = 0;						// Vertical position of the navball.

int CENTER_X = 640;						// Center point of the frame
int CENTER_Y = 360;						//



// Plane's animation states.
int TILT_X = 2;							// 0 1 2 3 4	VALUES
int TILT_Y = 1;							// 0 1 2		VALUES

int FIGHTER_X = CENTER_X - 39 * 3;					// Fighter's (Player) horizontal position.
int FIGHTER_Y = CENTER_Y - 16 * 3;					// Fighter's (Player) vertical position.

ICBYTES RENDER;							// Base renderer image that will display on screen each frame.
ICBYTES BG_VECTOR[13][5];				// Background images list.
ICBYTES FIGHTER_VECTOR[3][5];
ICBYTES ENEMY_VECTOR[13];
ICBYTES BG_BASE_ANIM[5];
ICBYTES NAVIGATION_VECTOR[13];			// Navigation base images.
ICBYTES NAVBALL;						// Navball base image.

// Enemy attributes.
ICBYTES ENEMY;




// Tilt image state enumerator. IF IT IS USELESS DELETE!
enum TILT_STATE {
	TILT_UPPER_LEFT_ALL = 1,
	TILT_UPPER_LEFT = 2,
	TILT_UPPER = 3,
	TILT_UPPER_RIGHT = 4,
	TILT_UPPER_RIGHT_ALL = 5,
	TILT_LEFT_ALL = 6,
	TILT_LEFT = 7,
	TILT_BASE = 8,
	TILT_RIGHT = 9,
	TILT_RIGHT_ALL = 10,
	TILT_DOWN_LEFT_ALL = 11,
	TILT_DOWN_LEFT = 12,
	TILT_DOWN = 13,
	TILT_DOWN_RIGHT = 14,
	TILT_DOWN_RIGHT_ALL = 15
};

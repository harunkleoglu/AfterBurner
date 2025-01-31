#include "icb_gui.h"
#include "AfterBurnerResources.h"
#include "AfterBurnerUtilities.cpp"
#include <ctime>
#include <cmath>

int GAME_FRAME;
int FRAMERATE = 0;

int MW_Width = GetSystemMetrics(SM_CXSCREEN);
int MW_Height = GetSystemMetrics(SM_CYSCREEN);

void ICGUI_Create() {
	ICG_MWTitle("After Burner");
	ICG_MWSize(1300, 760);
}


void Up() {
	if (BG_POS_Y >= 10) BG_POS_Y -= 10;
	if (TILT_Y > 0)	TILT_Y--;
	if (FIGHTER_Y >= 200) FIGHTER_Y-=20;
}

void Down() {
	if (BG_POS_Y <= 250) BG_POS_Y += 20;
	if (TILT_Y < 2) TILT_Y++;
	if (FIGHTER_Y < 400) FIGHTER_Y+=20;
}

void Left() {
	if (BG_POS_X > 0) BG_POS_X--;
	if (TILT_X > 0 && FRAMERATE % 2 == 0) TILT_X--;
	if (FIGHTER_X >= 325) FIGHTER_X-=40;
}

void Right() {
	if (BG_POS_X < 12) BG_POS_X++;
	if (TILT_X < 4 && FRAMERATE % 2 == 0) TILT_X++;
	if (FIGHTER_X <= 725) FIGHTER_X += 40;
}


void Update() {
	
	while (true) {

		if (KEY_HANDLER[UP_KEYCODE]) Up();
		if (KEY_HANDLER[LEFT_KEYCODE]) Left();
		if (KEY_HANDLER[RIGHT_KEYCODE]) Right();
		if (KEY_HANDLER[DOWN_KEYCODE]) Down();

		Copy(BG_VECTOR[BG_POS_X][FRAMERATE%3], 1, BG_POS_Y + 1, 1280, 720, RENDER);

		PasteNon0(FIGHTER_VECTOR[TILT_Y][TILT_X], FIGHTER_X, FIGHTER_Y, RENDER);
		PasteNon0(NAVIGATION_VECTOR[BG_POS_X], 1050, 20, RENDER);
		PasteNon0(NAVBALL, NAVBALL_X, NAVBALL_Y, RENDER);
		PasteNon0(ENEMY_VECTOR[BG_POS_X], ENEMY_X, ENEMY_Y, RENDER);
		DisplayImage(GAME_FRAME, RENDER);
		Sleep(16); // 16ms for 60 FPS - 33ms for 30 FPS
		FRAMERATE = (FRAMERATE + 1) % 60;
		UpdateNavball();
	}
}

void TitleMusic() {
	PlaySound("Assets/SoundEffects/After_Burner_Title_Music.wav", NULL, SND_ASYNC);
}

void EnemyPlane() {

	int speed = 2;
	

	while (true) {
		if (FRAMERATE % 2 == 0) {
			int Cx = FIGHTER_X + 39;
			int Cy = FIGHTER_Y - 115;

			int xDistance = Cx - ENEMY_X;
			int yDistance = Cy - ENEMY_Y;

			/*if (xDistance >= 0 && xDistance <= 5) {
				if (yDistance >= 0 && yDistance <= 5) {
					break;
				}
			}*/

			double distance = sqrt(xDistance * xDistance + yDistance * yDistance);
			if (distance <= 0) {
				distance = 1;
			}
			double xSpeed = (xDistance / distance) * speed;
			double ySpeed = (yDistance / distance) * speed;


			ENEMY_X += static_cast<int>(xSpeed);
			ENEMY_Y += static_cast<int>(ySpeed);
		}


		ICG_printf(console, "X:%d\n", ENEMY_X);
		ICG_printf(console, "Y:%d\n", ENEMY_Y);

		
	}
}

void ICGUI_main() {
	DWORD dw, dw2, dw3;
	// DEBUG CONSOLE
	console = ICG_MLEditSunken(0, 740, 1280, 200, "Console", SCROLLBAR_V);

	GAME_FRAME = ICG_Frameless(0, 0, 1280, 720);
	Configure();

	CreateImage(RENDER, 1280, 720, ICB_UINT);

	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Update, 0, 0, &dw);

	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)TitleMusic, 0, 0, &dw2);

	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)EnemyPlane, 0, 0, &dw3);
	
	
}



#pragma once
#include <icb_gui.h>
#include "AfterBurnerResources.h"
#include <stdio.h>

void KeyPressed(int keycode){ 
	keycodes[keycode] = true;
}

void KeyUp(int keycode){ 
	keycodes[keycode] = false;
	//TILT_X = 2;
	TILT_Y = 1;
}

void ImportBackgrounds() {

	const char* fileHeaders[] = {
		"Right30","Right25","Right20","Right15","Right10","Right5","Base","Left5","Left10","Left15","Left20","Left25","Left30"
	};

	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 5; j++) {
			char filepath[128];
			snprintf(filepath, sizeof(filepath), "Assets/Background/%s%s/%s-%d.bmp", fileHeaders[i], "Animation", fileHeaders[i], j + 1);
			ReadImage(filepath, BG_VECTOR[i][j]);
		}
	}
	ReadImage("Assets/Navigation/Navball.bmp", NAVBALL);

	//ReadImage("Assets/Navigation/Navigation.jpg", NAVIGATION);
}

void ImportFighter() {
	for (int i = 0; i < 15; i++) {
		char filepath[128];
		ICBYTES temp;
		snprintf(filepath, sizeof(filepath), "Assets/Fighter/%d.bmp", i + 1);
		ReadImage(filepath, temp);
		MagnifyX3(temp, FIGHTER_VECTOR[i / 5][i % 5]);
	}
}

void ImportEnemy() {
	const char* fileHeaders[] = {
	"left30", "left25", "left20", "left15", "left10", "left5", "base","right5",  "right10", "right15", "right20", "right25", "right30"
	};

	for (int i = 0; i < 13; i++) {
		char filepath[128];
		snprintf(filepath, sizeof(filepath), "Assets/Enemy/enemy-%s.bmp", fileHeaders[i]);
		ReadImage(filepath, ENEMY_VECTOR[i]);
	}
}

void ImportNavigation() {
	const char* fileHeaders[] = {
		"right30", "right25", "right20", "right15", "right10", "right5", "base", "left5", "left10", "left15", "left20", "left25", "left30",
	};

	for (int i = 0; i < 13; i++) {
		char filepath[128];
		snprintf(filepath, sizeof(filepath), "Assets/Navigation/navigation_%s.bmp", fileHeaders[i]);
		ReadImage(filepath, NAVIGATION_VECTOR[i]);
	}
}

void Configure() {
	HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(104));
	HWND MW = ICG_GetMainWindow();
	SendMessage(MW, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
	SendMessage(MW, WM_SETICON, ICON_BIG, (LPARAM)hIcon);

	ICG_SetOnKeyPressed(KeyPressed);
	ICG_SetOnKeyUp(KeyUp);
	ImportBackgrounds();
	ImportFighter();
	ImportNavigation();
	ImportEnemy();
}

void UpdateNavball() {
	NAVBALL_X = 1065 + (BG_POS_X * 11.25);
	NAVBALL_Y = 0.28 * BG_POS_Y + 26.5;
}

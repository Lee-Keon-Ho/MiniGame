#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Console.h"

#define MAX 30

int main(void) {
	int x = 14, y = 28; // player 위치
	int bx = 0, by = 0; // bullet 위치
/*
	// 적 한개
	int ex = 0, ey = 0;
	bool enemy = false;
*/

	// 배열 이용
	int ex[MAX] = { 0 }, ey[MAX] = { 0 };
	bool enemy[MAX] = { false };

	bool bullet = false;
	SetConsoleSize(30, 30);
	srand(time(NULL));

	while (1) {
		Clear();

		for (int i = 0; i < MAX; i++) {
			if (!enemy[i]) {
				ex[i] = (rand() % 15) * 2;
				ey[i] = 0;
				enemy[i] = true;
				break;
			}
		}
		
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			x--;
			if (x < 0) {
				x = 0;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			x++;
			if (x > 28) {
				x = 28;
			}
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			if (!bullet) {
				bx = x;
				by = y - 1;
				bullet = true;
			}
			
		}
		if (bullet) {
			GotoXY(bx, by);
			printf("º");
			by--;
			if (by < 0) {
				bullet = false;
			}
		}
		for (int i = 0; i < MAX; i++) {
			if (enemy) {
				GotoXY(ex[i], ey[i]);
				printf("■");
				ey[i]++;
				if (ey[i] > y) {
					enemy[i] = false;
				}
			}
		}
		GotoXY(x, y);
		printf("▲");
		Sleep(50);
	}
	system("pause");
	return 0;
}

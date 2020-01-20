#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Console.h"

#define MAX 30

// 구조체 사용
struct ST_ENEMY {
	int x = 0;
	int y = 0;
	bool bActive = false;
};

int main(void) {
	int x = 14, y = 28; // player 위치
	int bx = 0, by = 0; // bullet 위치
	ST_ENEMY stEnemy[MAX];

	
	bool bullet = false;
	SetConsoleSize(30, 30);
	srand(time(NULL));

	while (1) {
		Clear();

		for (int i = 0; i < MAX; i++) {
			if (!stEnemy[i].bActive) {
				stEnemy[i].x = (rand() % 15) * 2;
				stEnemy[i].y = 0;
				stEnemy[i].bActive = true;
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
			if (stEnemy[i].bActive) {
				GotoXY(stEnemy[i].x, stEnemy[i].y);
				printf("□");
				stEnemy[i].y++;
				if (stEnemy[i].y > y) {
					stEnemy[i].bActive = false;
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

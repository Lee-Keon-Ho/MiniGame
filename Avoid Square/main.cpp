#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> // _kbhit() 사용
#include "Console.h"

#define MAX 30
#define BACKCOLOR 15
// 구조체 사용
struct ST_OBJECT {
	int x = 0;
	int y = 0;
	bool bActive = false;
};
ST_OBJECT g_stEnemy[MAX];
ST_OBJECT g_stPlayer;

void Spawn(void) {
	for (int i = 0; i < MAX; i++) {
		if (!g_stEnemy[i].bActive) {
			g_stEnemy[i].x = (rand() % 15) * 2;
			g_stEnemy[i].y = 0;
			g_stEnemy[i].bActive = true;
			break;
		}
	}
}

int EnemyProcess(void) {
	int count = 0;
	for (int i = 0; i < MAX; i++) {
		if (g_stEnemy[i].bActive) {
			SetColor(BACKCOLOR, i % 15);
			count++;
			GotoXY(g_stEnemy[i].x, g_stEnemy[i].y);
			printf("□");
			g_stEnemy[i].y++;

			if (g_stEnemy[i].y == g_stPlayer.y) {
				if (g_stEnemy[i].x == g_stPlayer.x) { // 충돌
					g_stPlayer.bActive = false;
				}
			}
			if (g_stEnemy[i].y > g_stPlayer.y) {
				g_stEnemy[i].bActive = false;
			}
		}
	}
	return count;
}

void InputProcess(void) {
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		g_stPlayer.x -= 2;
		if (g_stPlayer.x < 0) {
			g_stPlayer.x = 0;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		g_stPlayer.x += 2;
		if (g_stPlayer.x > 28) {
			g_stPlayer.x = 28;
		}
	}
}

void RenderPlayer(void) {
	SetColor(BACKCOLOR, 12);
	if (g_stPlayer.bActive) {
		GotoXY(g_stPlayer.x, g_stPlayer.y);
		printf("▲");
	}
	else {
		GotoXY(g_stPlayer.x, g_stPlayer.y);
		printf("▩");
	}
	
}

void Init(void) {
	g_stPlayer.x = 14; // player x
	g_stPlayer.y = 28; // player y
	g_stPlayer.bActive = true;

	SetConsoleSize(30, 30);
	srand(time(NULL));

	SetTitle("사각형피하기");
	SetColor(BACKCOLOR, 0);
}

int g_iScore = 0;
void Score(void) {
	if (g_stPlayer.bActive) {
		g_iScore++;
	}
	GotoXY(0, 0);
	printf("Score : %d", g_iScore);
}

void StartMeny(void) {
	while (_kbhit()) {
		_getch();
	}
	while (1) {
		Clear();
		GotoXY(10, 10);
		printf("사각형피하기");
		GotoXY(6, 20);
		printf("Prees any key ... ");
		if (_kbhit()) {
			break;
		}
		Sleep(50);
	}
}

void GameMain(void) {
	int state = 0;
	g_stPlayer.x = 14; // player x
	g_stPlayer.y = 28; // player y
	g_stPlayer.bActive = true;
	g_iScore = 0;
	while (1) {
		Clear();

		if (g_stPlayer.bActive) {
			// 적을 생성
			Spawn();

			// input 처리
			InputProcess();
		}

		// 적 처리
		state = EnemyProcess();

		// player 출력
		RenderPlayer();

		// 점수
		Score();

		Sleep(50);
		if (state == 0) {
			break;
		}
	}
}

bool ResultMenu(void) {
	bool bRet = false;
	while (1) {
		Clear();
		GotoXY(10, 9);
		printf("Result Meny");
		GotoXY(10, 15);
		printf("SCORE : %d", g_iScore);

		GotoXY(8, 24);
		printf("continue... Y/N");
		if (GetAsyncKeyState('Y') & 0x8000) {
			bRet = false;
			break;
		}
		if (GetAsyncKeyState('N') & 0x8000) {
			bRet = true;
			break;
		}
		Sleep(50);
	}
	return bRet;
}

int main(void) {
	
	Init();

	while (1) {
		StartMeny();
		GameMain();
		if (ResultMenu()) {
			break;
		}
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Console.h"
#include <conio.h>

int g_result[3][3] = {
	0,-1,1,
	1,0,-1,
	-1,1,0
};
char szResult[3][10] = { "패","무","승" };
char mainT[][120] = {
	"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■                                                                                                                  ■",
	"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■",
};

char vstext[][30] = {
	"  ■      ■      ■■■■  ",
	"  ■      ■    ■          ",
	"  ■      ■      ■■■    ",
	"    ■  ■              ■  ",
	"      ■        ■■■■    "
};

char g_S[][16][30] = {
	{
		"□□□□□□□□□□□□□□",
		"□□□□□□□■□□□□□□",
		"□□■□□□■□■□□□□□",
		"□■□■□□■□■□□□□□",
		"□■□□■□■□■□□□□□",
		"□□■□■□■□■■□□□□",
		"□□■□□■■□■□■□□□",
		"□□□■□■■□■□■■□□",
		"□□□■■□□□■□■□■□",
		"□□■□■■■■□■■□■□",
		"□□■□□□□□■□■□■□",
		"□□■□□■■■□□□■□□",
		"□□□■□□□□□□□■□□",
		"□□□□■□□□□□■□□□",
		"□□□□□■■■■■□□□□",
		"□□□□□□□□□□□□□□"},
		{
		"□□□□□□□□□□□□□□",
		"□□□□□□□□□□□□□□",
		"□□□□□□□□□□□□□□",
		"□□□□□□□□□□□□□□",
		"□□□□■■■■■■□□□□",
		"□□□■□■□■□■■■□□",
		"□□□■□■□■□□■□■□",
		"□□■■□■□■□□■□■□",
		"□■□■□■□■□□■□■□",
		"□■□■■■■□■■□□■□",
		"□■□□□□□■□■□□■□",
		"□■□□■■■□□□□■□□",
		"□□■□□□□□□□□■□□",
		"□□□■□□□□□□■□□□",
		"□□□□■■■■■■□□□□",
		"□□□□□□□□□□□□□□"},
		{
		"□□□□□□□□□□□□□□",
		"□□□□□□□□□□□□□□",
		"□□□□□■■■■■□□□□",
		"□□□□■□■□■□■□□□",
		"□□□□■□■□■□■■□□",
		"□□□■■□■□■□■□■□",
		"□□■□■□■□■□■□■□",
		"□□■□■□■□■□■□■□",
		"□□■□■□■□■□■□■□",
		"□□■□□□□□□□□□■□",
		"□□■□□□□□□□□□■□",
		"□□■□□□□□□□□□■□",
		"□□■■□□□□□□□□■□",
		"□□□■■□□□□□□■□□",
		"□□□□■■■■■■■□□□",
		"□□□□□□□□□□□□□□"},

};

void printXY(int x, int y, const char* text) {
	GotoXY(x, y);
	printf(text);
}

void print2DXY(int x, int y, int sizeX, int sizeY, char* text) {
	char* temp = text;
	for (int _y = 0; _y < sizeY; ++_y) {
		printXY(x, y+_y,temp);
		temp += sizeX;
	}
}

void StartMenu(void) {
	int com = 0, count = 0, player = 0;
	Clear();
	SetColor(0, 15);
	print2DXY(0, 0, sizeof(mainT[0]), sizeof(mainT) / sizeof(mainT[0]), (char*)mainT);


	while (1) {
		if (count == 0) {
			com = rand() % 3;
			player++;
			count = 15;
		}
		--count;

		if (_kbhit()) {
			_getch();
			break;
		}

		SetColor(0, 9);
		print2DXY(15, 7, sizeof(g_S[player % 3][0]), sizeof(g_S[player % 3]) / sizeof(g_S[player % 3][0]), (char*)g_S[player%3]);
		SetColor(0, 12);
		print2DXY(75, 7, sizeof(g_S[com][0]), sizeof(g_S[1]) / sizeof(g_S[com][0]), (char*)g_S[com]);
		SetColor(0, 8);
		if (player % 2 == 0) {
			printXY(45, 24, "시작하려면 아무키나 누르세요...");
		}
		else {
			printXY(45, 24, "                               ");
		}
		
		Sleep(33);
	}
}

void GameMain(void) {
	int com = 0, count = 0, player = 0, result = 0;
	char key = 0;
	Clear();
	SetColor(0, 15);
	print2DXY(0, 0, sizeof(mainT[0]), sizeof(mainT) / sizeof(mainT[0]), (char*)mainT);


	while (1) {
		if (count == 0) {
			com = rand() % 3;
			player++;
			count = 10;
		}
		--count;

		if (_kbhit()) {
			key = _getch();
			if (key >= '0' && key <= '2') {
				player = key - '0';
				com = rand() % 3;
				SetColor(0, 9);
				print2DXY(15, 7, sizeof(g_S[player % 3][0]), sizeof(g_S[player % 3]) / sizeof(g_S[player % 3][0]), (char*)g_S[player % 3]);
				SetColor(0, 12);
				print2DXY(75, 7, sizeof(g_S[com][0]), sizeof(g_S[1]) / sizeof(g_S[com][0]), (char*)g_S[com]);
				SetColor(0, 15);
				result = g_result[player][com];
				printXY(56, 26, szResult[result+1]);
				Sleep(5000);
				break;
			}
			if (key == 27) { //esc
				break;
			}
		}


		SetColor(0, 9);
		print2DXY(15, 7, sizeof(g_S[player % 3][0]), sizeof(g_S[player % 3]) / sizeof(g_S[player % 3][0]), (char*)g_S[player % 3]);
		SetColor(0, 12);
		print2DXY(75, 7, sizeof(g_S[com][0]), sizeof(g_S[1]) / sizeof(g_S[com][0]), (char*)g_S[com]);
		SetColor(0, 15);
		print2DXY(45, 12, sizeof(vstext[0]), sizeof(vstext) / sizeof(vstext[0]), (char*)vstext);
		SetColor(0, 15);
		printXY(40, 24, "가위(0), 바위(1), 보(2) 중 선택하세요...");

		Sleep(50);
	}
}

int main(void) {

	SetConsoleSize(120,30);
	srand(time(NULL));
	while (1) {
		StartMenu();
		GameMain();
	}
	
	system("pause");
	return 0;
}
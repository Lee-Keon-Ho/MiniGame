#pragma once

#include<Windows.h>

void SetConsoleSize(int _col, int _lines); // console â�� ũ�⸦ ���ϴ� �Լ� (����Ʈ 80, 20)
void GotoXY(int _x, int _y); // Ŀ���� ��ġ�� _x, _y�� �����ϴ� �Լ�
void Clear(void); // ȭ���� �����ְ� Ŀ���� ��ġ�� 0, 0���� �̵���Ű�� �Լ�
void SetTitle(const char* _szConsoleName); // ����, ���ڻ��� ������ �ִ� �Լ�
void SetColor(unsigned char _BgColor, unsigned char _TextColor);// ����, ���ڻ��� ������ �ִ� �Լ�
void SetCursor(BOOL _bShow); // cursor�� ���̰� or �Ⱥ��̰� �ϴ� �Լ�
#pragma once

#include<Windows.h>

void SetConsoleSize(int _col, int _lines); // console 창의 크기를 정하는 함수 (디폴트 80, 20)
void GotoXY(int _x, int _y); // 커서의 위치를 _x, _y로 변경하는 함수
void Clear(void); // 화면을 지워주고 커서의 위치를 0, 0으로 이동시키는 함수
void SetTitle(const char* _szConsoleName); // 배경색, 글자색을 변경해 주는 함수
void SetColor(unsigned char _BgColor, unsigned char _TextColor);// 배경색, 글자색을 변경해 주는 함수
void SetCursor(BOOL _bShow); // cursor를 보이게 or 안보이게 하는 함수
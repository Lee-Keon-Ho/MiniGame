#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int com; // 컴퓨터
	int player; // 플레이어
	int count = 0; // 카운터

	srand(time(NULL));
	com = rand() % 100 + 1; // 컴퓨터 랜덤값 1 ~ 100

	while (1) {
		printf("Up and Down ( 1 ~ 100 ) ");
		scanf_s("%d", &player); // 플레이어 값 입력
		count++;

		if (com == player) {
			printf("%d번 만에 맞췄습니다.", count);
			break;
		}
		else {
			if (com > player) {
				printf("Up\n");
			}
			else {
				printf("Down\n");
			}
		}
	}
	return 0;
}

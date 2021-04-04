#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <MMsystem.h>
#include <stdbool.h>

void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int block[7][4][4][4] = {

	{ // ㅗ모양 블럭
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,1,0}, // ㅗ
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0}, // ㅏ
			{0,1,1,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0}, // ㅜ
			{1,1,1,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,0,0}, // ㅓ
			{0,1,0,0}
		}
	},

	{    //    ㅁㅁ 모양
		{// ㅁㅁ
			{0,0,0,0},
			{0,1,1,0},//   ㅁㅁ 
			{1,1,0,0},// ㅁㅁ
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,0,0,0},// ㅁ
			{1,1,0,0},// ㅁㅁ
			{0,1,0,0} //   ㅁ
		},
		{
			{0,0,0,0},
			{0,1,1,0},//   ㅁㅁ
			{1,1,0,0},// ㅁㅁ
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,0,0,0},// ㅁ
			{1,1,0,0},// ㅁㅁ
			{0,1,0,0}//    ㅁ
		}
	},
	{   // ㅣㅣ 블럭 반대
		{
			{0,0,0,0},
			{1,1,0,0},// ㅁㅁ
			{0,1,1,0},//   ㅁㅁ
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},//   ㅁ
			{1,1,0,0},// ㅁㅁ
			{1,0,0,0} // ㅁ
		},
		{
			{0,0,0,0},
			{1,1,0,0},// ㅁㅁ
			{0,1,1,0},//   ㅁㅁ
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},//   ㅁ
			{1,1,0,0},// ㅁㅁ
			{1,0,0,0} // ㅁ 
		}
	},
	{   // 1자 블럭
		{
			{0,1,0,0}, // ㅁ
			{0,1,0,0}, // ㅁ
			{0,1,0,0}, // ㅁ
			{0,1,0,0}  // ㅁ
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1}, // ㅁㅁㅁㅁ
			{0,0,0,0}
		},
		{
			{0,1,0,0},// ㅁ
			{0,1,0,0},// ㅁ
			{0,1,0,0},// ㅁ
			{0,1,0,0} // ㅁ
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1}, // ㅁㅁㅁㅁ
			{0,0,0,0}
		}
	},

	{   // L자 블럭
		{
			{0,0,0,0},
			{1,0,0,0},// ㅁ
			{1,1,1,0},// ㅁㅁㅁ
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,0,0},// ㅁㅁ
			{1,0,0,0},// ㅁ
			{1,0,0,0}//  ㅁ
		},
		{
			{0,0,0,0},
			{1,1,1,0}, // ㅁㅁㅁ
			{0,0,1,0}, //     ㅁ
			{0,0,0,0}
		},
		{
			{0,1,0,0},//   ㅁ
			{0,1,0,0},//   ㅁ
			{1,1,0,0},// ㅁㅁ
			{0,0,0,0}
		}
	},
	{   // L자 블럭 반대
		{
			{0,0,0,0},
			{0,0,1,0},//     ㅁ
			{1,1,1,0},// ㅁㅁㅁ
			{0,0,0,0}
		},
		{
			{1,0,0,0},// ㅁ
			{1,0,0,0},// ㅁ
			{1,1,0,0},// ㅁㅁ
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,1,0},// ㅁㅁㅁ
			{1,0,0,0},// ㅁ
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,0,0},// ㅁㅁ
			{0,1,0,0},//   ㅁ
			{0,1,0,0} //   ㅁ
		}
	},

	{   // 네모
		{
			{0,0,0,0},
			{0,1,1,0},// ㅁㅁ
			{0,1,1,0},// ㅁㅁ
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},// ㅁㅁ
			{0,1,1,0},// ㅁㅁ
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},// ㅁㅁ
			{0,1,1,0},// ㅁㅁ
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},// ㅁㅁ
			{0,1,1,0},// ㅁㅁ
			{0,0,0,0}
		}
	}
};

int BlockRot = 0; 

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

int BlockForm() {
	srand(time(NULL));
	int BlockForm = rand() % 6;
	return BlockForm;
}

void BlockEvent() {
	
	if (_kbhit()) {
		int a = _getch();
		// 블럭 회전
		if (a == UP) {
			if (BlockRot > 3) {
				BlockRot = 0;
			}
			else {
				BlockRot++;
			}
		}

		// 블럭이동
		if (a == LEFT) {
		}

		// 블럭이동
		if (a == RIGHT) {
		}

		// 블럭 내림(드랍)
		if (a == DOWN) {
		}
	}
}

void DrawBlock() {
	int i, j, k;
	k = 0;
	gotoxy(9, 0);
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (block[BlockForm()][BlockRot][i][j] == 1) {
				printf("\u25A0");
			}
			else {
				printf("  ");
			}
		}
		k++;
		gotoxy(9, k);
	}
}

// 콘솔 창 크기 및 타이틀
void gamesize() {
	system("mode con cols=50 lines=20 || title 테트리스");
}

// 커서 이동 안보이게
void init() {
	CONSOLE_CURSOR_INFO cursorinfo;
	cursorinfo.bVisible = 0;
	cursorinfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorinfo);
}

// 배경음악
void BGM() {
	PlaySound(TEXT("C:\\Users\\gksrp\\Desktop\\44\\23\\fuwafuwa.wav"), NULL, SND_ASYNC);
}

// 인터페이스
void Interface() {

	// 네모 박스
	gotoxy(27, 6);
	printf("\u250c");
	int i;
	for (i = 0; i < 20; i++) {
		gotoxy(i + 27, 6);
		printf("\u2500");
	}
	gotoxy(i + 27, 6);
	printf("\u2510");
	for (i = 0; i < 6; i++) {
		gotoxy(47, i + 7);
		printf("\u2502");
	}
	gotoxy(47, i + 7);
	printf("\u2518");
	for (i = 0; i < 20; i++) {
		gotoxy(27 + i, 13);
		printf("\u2500");
	}
	gotoxy(26, 13);
	printf("\u2514");
	for (i = 0; i < 6; i++) {
		gotoxy(26, i + 7);
		printf("\u2502");
	}
	gotoxy(26, 6);
	printf("\u250C");

	// 설명
	gotoxy(34, 3);
	printf("조작법");
	gotoxy(28, 7);
	printf("← , → : 블럭 이동");
	gotoxy(30, 9);
	printf("↑ : 블럭 회전");
	gotoxy(30, 11);
	printf("↓ : 블럭 놓기");

	// 점수
	gotoxy(30, 15);
	printf("점수  :");
}

void developer() {
	gotoxy(28, 17);
	printf(" 개발자 : HyeonJoong ");
}

void deathline() {
	gotoxy(25, 0);
	printf("-- OutLine");
	Sleep(500);
	gotoxy(25, 0);
	printf("                ");
	Sleep(500);
	gotoxy(25, 0);
	printf("-- OutLine");
	Sleep(500);
	gotoxy(25, 0);
	printf("               ");
	Sleep(500);
	gotoxy(25, 0);
	printf("-- OutLine");
	Sleep(500);
	gotoxy(25, 0);
	printf("               ");
	Sleep(500);
	gotoxy(25, 0);
	printf("-- OutLine");
	Sleep(500);
	gotoxy(25, 0);
	printf("               ");

}

// 블럭


int map[21][12] = {
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1,1,1}
};


void mapload() {
	gotoxy(0, 0);
	int i, j;
	for (i = 0; i < 21; i++) {
		for (j = 0; j < 12; j++) {
			if (map[i][j] == 1) {
				printf("\u25A0");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
}


int main(void) {
	//
	init();
	// BGM();
	gamesize();
	mapload();
	// deathline();
	Interface();
	DrawBlock();
	//
	//
	while (1) {
		Sleep(100);
	}
}







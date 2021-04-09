#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <MMsystem.h>
#include <stdbool.h>

clock_t startDropT, endT, startGroundT;
int x = 8, y = 0;
int blockForm;
int blockRotation = 0;
int key;
int score = 0;
int a, b;
int color = 0;
int randscore = 0;

void RandomScore() {
	srand(time(NULL));
	randscore = rand() % 150 + 100;
}

#define UP 72
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define ESC 27
#define DOWN 80

// color
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define qhfk "\033[35m"
#define CR "\033[36m"
#define dkanrjsk "\033[33m"

void randomcolor() {
	srand(time(NULL));
	color = rand() % 7 + 0;
}

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

//int score() {
	//gotoxy();

//}


void CreateRandomForm() {
	srand(time(NULL));
	blockForm = rand() % 7;
}

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

int DrawScore() {
	gotoxy(39,15);
	printf("%d", score);
}

// 충돌 확인
bool CheckCrash(int x, int y) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[blockForm][blockRotation][i][j] == 1) {
				int t = map[i + y][j + x / 2];
				if (t == 1 || t == 2) { // 벽일 때, 블럭일 때
					return true;
				}
			}
		}
	}
	return false;
}

// 블럭 drop
void DropBlock() {
	endT = clock();
	if ((float)(endT - startDropT) >= 800) {
		if (CheckCrash(x, y + 1) == true) {
			return;
		}
		else {
			y++;
			startDropT = clock();
			startGroundT = clock();
			system("cls");
		}
	}
}

// 땅
void BlockToGround() {
	if (CheckCrash(x, y + 1) == true) {
		if ((float)(endT - startGroundT) > 1000) {
			// 현재 블록 저장
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (block[blockForm][blockRotation][i][j] == 1) {
						map[i + y][j + x / 2] = 2;
					}
				}
			}
			x = 8;
			y = 0;
			CreateRandomForm();
			randomcolor();
		}
	}
}


// 1줄 라인 제거
void RemoveLine() {
	for (int i = 21; i >= 0; i--) { // 벽라인 제외한 값
		int cnt = 0;
		for (int j = 1; j < 11; j++) { //  12
			if (map[i][j] == 2) {
				cnt++;
			}
		}
		if (cnt >= 10) { // 벽돌이 다 차있다면
			for (int j = 0; i - j >= 0; j++) {
				for (int x = 1; x < 11; x++) {
					if (i - j - 1 >= 0)
						map[i - j][x] = map[i - j - 1][x];
					else      // 천장이면 0저장
						map[i - j][x] = 0;
				}
			}
			score += randscore;
		}
	}
}

// 맵
void DrawMap() {
	gotoxy(0, 0);
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 12; j++) {
			if (map[i][j] == 1) {
				gotoxy(j * 2, i);
				printf("□");
			}
			else if (map[i][j] == 2) {
				gotoxy(j * 2, i);
				printf("■");
			}
		}
	}
}

// 블럭그리기
void DrawBlock() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[blockForm][blockRotation][i][j] == 1) {
				if (color == 0) {
					printf(RED);
				}
				if (color == 1) {
					printf(GREEN);
				}
				if (color == 2) {
					printf(YELLOW);
				}
				if (color == 3) {
					printf(CR);
				}
				if (color == 4) {
					printf(dkanrjsk);
				}
				if (color == 5) {
					printf(qhfk);
				}
				if (color == 6) {
					printf(BLUE);
				}
				gotoxy(x + j * 2, y + i);
				printf("■");
				printf("\033[0m");
			
			}
		}
	}
}

// 키입력 받기
void InputKey() {
	if (_kbhit()) {
		key = _getch();
		switch (key) {
		case 72: // space
			blockRotation++;
			if (blockRotation >= 4) blockRotation = 0;
			startGroundT = clock();
			break;
		case 75: // left
			if (CheckCrash(x - 2, y) == false) {
				x -= 2;
				startGroundT = clock();
			}
			break;
		case 77: // right
			if (CheckCrash(x + 2, y) == false) {
				x += 2;
				startGroundT = clock();
			}
			break;
		case 80: // down
			if (CheckCrash(x, y + 1) == false)
				y++;
			break;
		}
		system("cls");
	}
}

// 콘솔 창 크기 및 타이틀
void gamesize() {
	system("mode con cols=52 lines=22 || title 테트리스");
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
	PlaySound(TEXT("C:\\Users\\user\\Desktop\\hyeonjoong\\rhythm\\tetris.wav"), NULL, SND_ASYNC);
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

int main() {
	init();
	startDropT = clock();
	CreateRandomForm();
	gamesize();
	DrawMap();
	Interface();
	DrawScore();
	developer();
	deathline();
	BGM();

	while (true) {
		DrawMap();
		Interface();
		developer();
		DrawBlock();
		DropBlock();
		BlockToGround();
		RemoveLine();
		RandomScore();
		DrawScore();
		InputKey();
	}
	
	return 0;
}







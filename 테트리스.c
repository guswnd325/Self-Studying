#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <MMsystem.h>
#include <stdbool.h>

clock_t BlockDropTime, endTime, mapblocktime;
int x = 8, y = 0;
int key;
int score = 0;
int color = 0;
int line = 0;
int gameend = 0;
int groundblockcolor = 0;

// 다음 블럭
int nextblockform = 0;
// 현재 블럭
int blockForm = 0;
int blockRotation = 0;

// 키 입력 받기
#define UP 72
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define ESC 27
#define DOWN 80

// 블럭 색 지정
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define dkanrjsk "\033[35m"
#define CR "\033[36m"
#define dkanrjsk "\033[33m"
#define rkdwh "\033[1m"

// 랜덤한 색
void randomcolor() {
	srand(time(NULL));
	color = rand() % 7;
}

// 맵
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


// 랜덤 블럭
void RandomBlockForm() {
	srand(time(NULL));
	nextblockform = rand() % 7;
}


// 커서이동
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}


// 블럽 4차원 배열
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

// 전 블럭 지우기
void RemoveBlock() {
	for (int row = 0; row < 4; row++) {
		for (int cols = 0; cols < 4; cols++) {
			if (block[blockForm][blockRotation][row][cols] == 1) {
				gotoxy((x + cols * 2), (y + row)); // 지정된 색으로 블럭을그림. x = 8, y = 0 (4x4)
				printf("  ");
				printf("\033[0m"); // 색깔 효과 없애기
			}
		}
	}
}
// 다음칸 청소
void nextclear() {
	for (int row = 0; row < 4; row++) {
		for (int cols = 0; cols < 4; cols++) {
			if (block[nextblockform][0][row][cols] == 1) { // block값이 1일떄 == block이 잇을때
				gotoxy((cols * 2) + 60, (row + 7)); // 지정된 색으로 블럭을그림. x = 8, y = 0 (4x4)
				printf("  ");
			}
		}
	}

}


// 점수 업데이트
void DrawScore() {
	gotoxy(39, 15);
	printf("%d", score);
}


// 점수 업데이트
void DrawLine() {
	gotoxy(39, 17);
	printf("%d", line);
}


// 충돌 확인
bool crash(int x, int y) { // x,y 를 매개변수로 받음.
	for (int row = 0; row < 4; row++) { // y값 검사
		for (int cols = 0; cols < 4; cols++) { // x값 검사
			if (block[blockForm][blockRotation][row][cols] == 1) { // 블럭 1값을 찾으면,
				int scan = map[row + y][cols + x / 2]; // scan변수 선언,  scan변수는 맵의[][]의 값을 가지며 if문을 들어가 검사함. 
				if (scan == 1 || scan == 2 || scan == 3 || scan == 4 || scan == 5 || scan == 6 || scan == 7 || scan == 8) { // 그래서 1이나 2가 감지되면, 
					return true; // true값을 반환, 
				}
			}
		}
	}
	return false; // 아니면 false값을 반환함.
}

// 블럭 drop
void blockdrop() {
	endTime = clock(); // endTime 시간재기
	if ((endTime - BlockDropTime) >= 850) { // endTime - BlockDropTime 블럭이나온지 0.8 초뒤 0.8초마다 내려감 y + 1
		if (crash(x, y + 1) == true) { // x = 8 , y + 1 = 아래칸이 충돌했을 때.
			return; // 함수종료.
		}
		else {
			RemoveBlock();
			y++; // y값,
			BlockDropTime = clock(); // 시간재기
			mapblocktime = clock(); // 시간재기
			//system("cls"); // cls 콘솔 클리어 전 블럭 지우기.
		}
	}
}

// 땅
void blockDownStop(int timeA) {
	if (crash(x, y + 1) == true) { // 만약 아래에 충돌이있으면.
		if ((endTime - mapblocktime) > timeA) { // end-T - startGround값이 > 1000 즉 1초보다 크다면
			// 현재 블럭모양으로
			if (color == 0) {
				groundblockcolor = 2;
			}
			if (color == 1) {
				groundblockcolor = 3;
			}
			if (color == 2) {
				groundblockcolor = 4;
			}
			if (color == 3) {
				groundblockcolor = 5;
			}
			if (color == 4) {
				groundblockcolor = 6;
			}
			if (color == 5) {
				groundblockcolor = 7;
			}
			if (color == 6) {
				groundblockcolor = 8;
			}
			for (int row = 0; row < 4; row++) {
				for (int cols = 0; cols < 4; cols++) {
					if (block[blockForm][blockRotation][row][cols] == 1) {
						map[row + y][cols + x / 2] = groundblockcolor; // 맵에 2로 채우도록함.
					}
				}
			}
			x = 8; // 초기화
			y = 0; // 초기화
			blockForm = nextblockform;
			nextclear();
			RandomBlockForm(); // 블럭을 놓았다면, blockform을 랜덤으로 바꿈.
			randomcolor(); // 색도 바꾸기
		}
	}
}

// 다음 블럭
void nextblock() {
	for (int row = 0; row < 4; row++) {
		for (int cols = 0; cols < 4; cols++) {
			if (block[nextblockform][0][row][cols] == 1) { // block값이 1일떄 == block이 잇을때
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
					printf(dkanrjsk);
				}
				if (color == 6) {
					printf(BLUE);
				}
				gotoxy((cols * 2) + 60, (row + 7)); // 지정된 색으로 블럭을그림. x = 8, y = 0 (4x4)
				printf("■");
				printf("\033[0m"); // 색깔 효과 없애기

			}
		}
	}
	
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
	gotoxy(34, 4);
	printf(rkdwh);
	printf(YELLOW);
	printf("조작법");
	printf("\033[0m");
	printf(rkdwh);
	
	gotoxy(28, 7);
	printf("← , → : 블럭 이동");
	gotoxy(30, 8);
	printf("↑ : 블럭 회전");
	gotoxy(30, 9);
	printf("↓ : 블럭 놓기");
	gotoxy(32, 10);
	printf("space : 드랍");
	gotoxy(31, 11);
	printf("esc : 멈춰!");
	gotoxy(33, 12);
	printf("e = 종료");
	printf("\033[0m");
	
	// 점수
	gotoxy(30, 15);
	printf(rkdwh);
	printf(BLUE);
	printf("점수  :");
	printf("\033[0m");
	gotoxy(30, 17);
	printf(rkdwh);
	printf(GREEN);
	printf("라인  :");
	printf("\033[0m");

	// 다음
	gotoxy(59, 3);
	printf(rkdwh);
	printf(YELLOW);
	printf("다음블럭");
	printf("\033[0m");
	
	//
	
	//
	printf(CR);
	gotoxy(55, 5);
	for (i = 0; i < 8; i++) {
		printf("■");
	}
	gotoxy(55, 6);
	printf("■");
	for (i = 0; i < 6; i++) {
		printf("  ");
	}
	printf("■");
	gotoxy(55, 7);
	printf("■");
	for (i = 0; i < 6; i++) {
		printf("  ");
	}
	printf("■");
	gotoxy(55, 8);
	printf("■");
	for (i = 0; i < 6; i++) {
		printf("  ");
	}
	printf("■");
	gotoxy(55, 9);
	printf("■");
	for (i = 0; i < 6; i++) {
		printf("  ");
	}
	printf("■");
	gotoxy(55, 10);
	printf("■");
	for (i = 0; i < 6; i++) {
		printf("  ");
	}
	printf("■");
	gotoxy(55, 11);
	printf("■");
	for (i = 0; i < 6; i++) {
		printf("  ");
	}
	printf("■");
	gotoxy(55, 12);
	for (i = 0; i < 8; i++) {
		printf("■");
	}
	printf("\033[0m");
}

// 개발자
void developer() {
	gotoxy(28, 19);
	printf(rkdwh);
	printf(YELLOW);
	printf(" 개발자 : HyeonJoong ");
	printf("\033[0m");
}

// 1줄 라인 제거
bool RemoveLine() {
	for (int ScanLine = 21; ScanLine >= 0; ScanLine--) { // 22 ( 세로 1 ) 아래에서부터 위로
		int count = 0;
		for (int ScanCols = 1; ScanCols < 12; ScanCols++) { //  ( 가로 1 )
			if (map[ScanLine][ScanCols] == 2 || map[ScanLine][ScanCols] == 3 || map[ScanLine][ScanCols] == 4 || map[ScanLine][ScanCols] == 5 || map[ScanLine][ScanCols] == 6 || map[ScanLine][ScanCols] == 7 || map[ScanLine][ScanCols] == 8) { // 맵의 아래쪽부터 위로 검사함. 2발견시
				count++; // count++;
			}
			else {
				count += 0;
			}
		}
		// ScanLine == 21 - 10 = 11
		if (count >= 10) { // 벽돌이 다 차있다면
			for (int j = 0; ScanLine - j >= 0; j++) { // i번째 
				for (int cols = 1; cols < 11; cols++) { // 줄 검사
					if (ScanLine - j - 1 >= 0)
					{
						map[ScanLine - j][cols] = map[ScanLine - j - 1][cols];
					}
					else
					{
						map[ScanLine - j][cols] = 0;
					}
				}
			}
			system("cls");
			Interface();
			developer();
			score += 100; // 라인이 없어지고나면 score(점수)를 +=
			line += 1; // 라인이 없어지고 나면 line을 +=
		}
	}
}
/*
한줄 제거 되는 원리

22 번 반복
10번반복
즉 맵검사용 반복문임.
map[y][x]에 블럭이 감지되면 count++ 을 해준다.

아니면 count += 0;
그걸계속 반복하는데,

그러다 count가 10보다 커질때,
j가 (row(현재검사하고있는라인)-j(j가0이면 현재층 j가1이면 현재층에-1이므로 그 윗층이된다.

즉 row - j (현재층) - 1은 현재돌고있는 층의 윗층이된다. 현재돌고있는층의 윗층이 없을떄까지 반복하고,
만약 윗층이 없다면, 0으로 채운다. 그리고 점수와 라인 변수에 각각의 수를 더해준다.

*/

// 맨 윗줄에 블럭이 감지되면 게임 종료
void gameover() {
	for (int row = 0; row < 2; row++) {
		for (int cols = 0; cols < 12; cols++) {
			if (map[row][cols] == 2 || map[row][cols] == 3 || map[row][cols] == 4 || map[row][cols] == 5 || map[row][cols] == 6 || map[row][cols] == 7 || map[row][cols] == 8) {
				gotoxy(8, 8);
				printf(RED);
				printf("GAME OVER!");
				gameend = 1;
				return;
			}
		}
	}
}

// 맵 그리기
void DrawMap() {
	gotoxy(0, 0);
	for (int row = 0; row < 21; row++) {
		for (int cols = 0; cols < 12; cols++) {
			if (map[row][cols] == 1) { // 벽
				gotoxy(cols * 2, row);
				printf("□");
			} 
			else if (map[row][cols] == 2) {
				printf(RED);
				gotoxy(cols * 2, row); // 블럭
				printf("■");
				printf("\033[0m");
			}
			else if (map[row][cols] == 3) {
				printf(GREEN);
				gotoxy(cols * 2, row); // 블럭
				printf("■");
				printf("\033[0m");
			}
			else if (map[row][cols] == 4) {
				printf(YELLOW);
				gotoxy(cols * 2, row); // 블럭
				printf("■");
				printf("\033[0m");
			}
			else if (map[row][cols] == 5) {
				printf(CR);
				gotoxy(cols * 2, row); // 블럭
				printf("■");
				printf("\033[0m");
			}
			else if (map[row][cols] == 6) {
				printf(dkanrjsk);
				gotoxy(cols * 2, row); // 블럭
				printf("■");
				printf("\033[0m");
			}
			else if (map[row][cols] == 7) {
				printf(dkanrjsk);
				gotoxy(cols * 2, row); // 블럭
				printf("■");
				printf("\033[0m");
			}
			else if (map[row][cols] == 8) {
				printf(BLUE);
				gotoxy(cols * 2, row); // 블럭
				printf("■");
				printf("\033[0m");
			}
		}
	}
}

// 블럭그리기
void DrawBlock() {
	for (int row = 0; row < 4; row++) {
		for (int cols = 0; cols < 4; cols++) {
			if (block[blockForm][blockRotation][row][cols] == 1) { // block값이 1일떄 == block이 잇을때
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
					printf(dkanrjsk);
				}
				if (color == 6) {
					printf(BLUE);
				}
				gotoxy((x + cols * 2), (y + row)); // 지정된 색으로 블럭을그림. x = 8, y = 0 (4x4)
				printf("■");
				printf("\033[0m"); // 색깔 효과 없애기

			}
		}
	}
}

// 키입력 받기 (수정 필요)
void control() {
	if (_kbhit()) { // 만약, 키보드 입력을 받았다면
		key = _getch(); // key변수안에 _getch 입력값을 저장한다.
		switch (key) { // 스위치문

		case UP: { // UP
			RemoveBlock();
			if (crash(x + 2, y)) {
				x -= 2;
				y;
				blockRotation++;
			}
			RemoveBlock();
			if (crash(x - 2, y)) {
				x += 2;
				y;
				blockRotation++;
			}
			RemoveBlock();
			if (crash(x, y + 1)) {
				x;
				y -= 2;
				blockRotation++;
			}
			RemoveBlock();
			if (crash(x, y - 1)) {
				x;
				y += 2;
				blockRotation++;
			}
			if (blockRotation >= 4)
			{
				blockRotation = 0;
				mapblocktime = clock();
			}

			else {
				blockRotation++;
				if (blockRotation >= 4) {
					blockRotation = 0;
					mapblocktime = clock();
				}
				break;
			}
		}
		case LEFT: {// 왼쪽 화살표 키
			if (crash(x - 2, y) == false) {
				RemoveBlock();
				x -= 2; // 왼쪽 충돌검사 x - 2(자릿수)
				mapblocktime = clock();
			}
			break;
		}
		case RIGHT: { // 오른쪽 화살표 키
			if (crash(x + 2, y) == false) { // 오른쪽 충돌검사 false = x+= 2  ? + 사용한 블럭 유니코드의 자릿수가 2이므로.
				RemoveBlock();
				x += 2;
				mapblocktime = clock();
			}
			break;
		}
		case DOWN: { // 아래쪽 화살표 키
			if (crash(x, y + 1) == false){ // 아래 충돌검사 false = y++
				RemoveBlock();
			y++;
			break;
		}
			if (crash(x, y + 1 == true)) {
				return;
					break;
			}
		}
		case 32: { // space
			while (crash(x, y + 1) == false) {
				RemoveBlock();
				y++;
			}
			blockDownStop(0);
			break;
		}
		case 27: {
			system("pause");
			break;
		}
		case 101: {
			gameend = 1;
			break;
		}
		}
		//system("cls"); // 콘솔 창 지우기
	}
	return;
}

// 콘솔 창 크기 및 타이틀
void gamesize() {
	system("mode con cols=77 lines=22");
	system("title 테트리스");
}

// 커서 이동 안보이게
void CursorRemove() {
	CONSOLE_CURSOR_INFO cursorinfo;
	cursorinfo.dwSize = 1;
	cursorinfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorinfo);
}



// 데드라인
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

// 메인함수
int main() {
	system("title 테트리스");
	CursorRemove();
	RandomBlockForm();
	gamesize();
	DrawMap();
	Interface();
	DrawScore();
	DrawLine();
	developer();
	deathline();


	// 콘솔 업데이트 반복
	while (1) {
		DrawMap();
		nextblock();
		DrawBlock();
		blockdrop();
		gameover();
		if (gameend == 1) {
			Sleep(3000);
			return 0;
		}
		blockDownStop(1000);
		RemoveLine();
		DrawScore();
		DrawLine();
		control();
	}
	return 0;
}





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
int line = 0;
int randscore = 0;
int gameend = 0;

// 0 ~ 150 랜덤 점수
void RandomScore() {
	srand(time(NULL));
	randscore = rand() % 150;
}

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
#define qhfk "\033[35m"
#define CR "\033[36m"
#define dkanrjsk "\033[33m"

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
	blockForm = rand() % 7;
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
bool CheckCrash(int x, int y) { // x,y 를 매개변수로 받음.
	for (int i = 0; i < 4; i++) { // y값 검사
		for (int j = 0; j < 4; j++) { // x값 검사
			if (block[blockForm][blockRotation][i][j] == 1) { // 검사중 1값이 보이면
				int scan = map[i + y][j + x / 2]; // scan변수 선언,  scan변수는 맵의[][]의 값을 가지며 if문을 들어가 검사함. 
				if (scan == 1 || scan == 2) { // 그래서 1이나 2가 감지되면, 
					return true; // true값을 반환, 
				}
			}
		}
	}
	return false; // 아니면 false값을 반환함.
}

// 블럭 drop
void DropBlock() {
	endT = clock(); // endT 시간재기
	if ((float)(endT - startDropT) >= 800) { // endT - startDropT 블럭이나온지 0.8 초뒤 0.8초마다 내려감 y + 1
		if (CheckCrash(x, y + 1) == true) { // x = 8 , y + 1 = 아래칸이 충돌했을 때.
			return; // 함수종료.
		}
		else {
			y++; // y값,
			startDropT = clock(); // 시간재기
			startGroundT = clock(); // 시간재기
			system("cls"); // cls 콘솔 클리어 전 블럭 지우기.
		}
	}
}

// 땅
void BlockToGround() {
	if (CheckCrash(x, y + 1) == true) { // 만약 아래에 충돌이있으면.
		if ((float)(endT - startGroundT) > 1000) { // end-T - startGround값이 > 1000 즉 1초
			// + 보다 크다면
			// 현재 블록 저장
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (block[blockForm][blockRotation][i][j] == 1) {
						map[i + y][j + x / 2] = 2; // 맵에 2로 채우도록함.
					}
				}
			}
			x = 8; // 초기화
			y = 0; // 초기화
			RandomBlockForm(); // 블럭을 놓았다면, blockform을 랜덤으로 바꿈.
			randomcolor(); // 색도 바꾸기
		}
	}
}


// 1줄 라인 제거
void RemoveLine() {
	for (int i = 21; i >= 0; i--) { // 22
		int count = 0;
		for (int j = 1; j < 12; j++) { //  10
			if (map[i][j] == 2) { // 맵의 아래쪽부터 위로 검사함. 2발견시
				count++; // count++;
			}
		}

		if (count >= 10) { // 벽돌이 다 차있다면
			for (int j = 0; i - j >= 0; j++) { // 12,11,10......
				for (int x = 1; x < 11; x++) { 
					if (i - j - 1 >= 0) 
					{
						map[i - j][x] = map[i - j - 1][x];
					}
					else 
					{      // 천장이면 0저장
						map[i - j][x] = 0;
					}
				}
			}
			score += randscore; // 라인이 없어지고나면 score(점수)를 +=
			line += 1; // 라인이 없어지고 나면 line을 +=
		}
	}
}

// 맨 윗줄에 블럭이 감지되면 게임 종료
void gameover() {
	for (int j = 0; j < 1; j++) {
		for (int i = 0; i < 12; i++) {
			if (map[j][i] == 2) {
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
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 12; j++) {
			if (map[i][j] == 1) { // 벽
				gotoxy(j * 2, i);
				printf("□");
			}
			else if (map[i][j] == 2) { 
				gotoxy(j * 2, i); // 블럭
				printf("■");
			}
		}
	}
}

// 블럭그리기
void DrawBlock() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[blockForm][blockRotation][i][j] == 1) { // block값이 1일떄 == block이 잇을때
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
				gotoxy((x + j * 2), (y + i)); // 지정된 색으로 블럭을그림. x = 8, y = 0 (4x4)
				printf("■");
				printf("\033[0m"); // 색깔 효과 없애기

			}
		}
	}
}

// 키입력 받기 (수정 필요)
void InputKey() {
	if (_kbhit()) { // 만약, 키보드 입력을 받았다면
		key = _getch(); // key변수안에 _getch 입력값을 저장한다.
		switch (key) { // 스위치문
		case 72: {// UP
				blockRotation++;
				if (blockRotation >= 4)
				{
					blockRotation = 0;
					startGroundT = clock();
					break;
				}
			break;
		}

		case 75: {// 왼쪽 화살표 키
			if (CheckCrash(x - 2, y) == false) {
				x -= 2;
				startGroundT = clock();
			}
			break;
		}
		case 77: { // 오른쪽 화살표 키
			if (CheckCrash(x + 2, y) == false) { // 오른쪽 충돌검사 false = x+= 2  ? + 사용한 블럭 유니코드의 자릿수가 2이므로.
				x += 2;
				startGroundT = clock();
			}
			break;
		}
		case 80: { // 아래쪽 화살표 키
			if (CheckCrash(x, y + 1) == false) // 아래 충돌검사 false = y++
				y++;
			break;
		}
		}
		system("cls"); // 콘솔 창 지우기
	}
}

// 콘솔 창 크기 및 타이틀
void gamesize() {
	system("mode con cols=52 lines=22 || title 테트리스");
}

// 커서 이동 안보이게
void CursorRemove() {
	CONSOLE_CURSOR_INFO cursorinfo;
	cursorinfo.dwSize = 1;
	cursorinfo.bVisible = 0;
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
	gotoxy(30, 17);
	printf("라인  :");
}

// 개발자
void developer() {
	gotoxy(28, 19);
	printf(" 개발자 : HyeonJoong ");
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
	CursorRemove();
	startDropT = clock();
	RandomBlockForm();
	gamesize();
	DrawMap();
	Interface();
	DrawScore();
	developer();
	deathline();
	BGM();

	// 콘솔 업데이트 반복
	while (true) {
		CursorRemove();
		DrawMap();
		Interface();
		developer();
		DrawBlock();
		DropBlock();
		BlockToGround();
		RemoveLine();
		RandomScore();
		DrawScore();
		DrawLine();
		InputKey();
		gameover();
		if (gameend == 1) {
			return 0;
		}
		
	}

	return 0;
}







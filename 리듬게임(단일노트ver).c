#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <mmsystem.h>
#include <conio.h>
#include <time.h>

void Init() {
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	srand(time(NULL));
}

int score = 0;
int combo = 0;
int count = 0;
int scoreR = 459;
int missX = 45;
int missY = 21;
int KeyBoradInput() {
	int keycode;
	keycode = _getch();

	// key
	if (keycode == 'p' || keycode == 'P') {
		return 0;
	}
	if (keycode == 'c' || keycode == 'C') {
		return 1;
	}
	if (keycode == 'e' || keycode == 'E') {
		return 2;
	}
	if (keycode == 'r' || keycode == 'R') {
		return 3;
	}

	// 노트 조작키
	if (keycode == 'd' || keycode == 'D') {
		return 4;
	}
	if (keycode == 'f' || keycode == 'F') {
		return 5;
	}
	if (keycode == 'j' || keycode == 'J') {
		return 6;
	}
	if (keycode == 'k' || keycode == 'K') {
		return 7;
	}
}

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// 노트
void note(int x, int y) {

	gotoxy(x, y);
	printf("\u25A0\u25A0\u25A0\u25A0");

}

// 공백 노트
void noteB(int x, int y) {
	gotoxy(x, y);
	printf("        ");
}

// 첫번쨰 줄 노트
void note1(int sleep) {
	int loop = 0;
	for (loop = 0; loop < 33; loop++) {
		if (loop == 30) {
			continue;
		}
		else {
			note(2, loop + 1);
			Sleep(sleep);
			noteB(2, loop + 1);
		}
	}
	if (loop > 30) {
		if (_kbhit()) {
			int a = KeyBoradInput();
			if (a == 4) {
				score += scoreR;
				gotoxy(45, 15);
				printf("점수 : %d", score);
				gotoxy(45, 18);
				combo += 1;
				printf("콤보 : %d", combo);
			}
			else {
				score += 0;
				combo = 0;
				gotoxy(45, 18);
				printf("          ");
				gotoxy(45, 18);
				printf("콤보 : 0");
				count += 1;
				gotoxy(45, 21);
				printf("틀린 횟수 : %d", count);
			}
		}
		else {
			gotoxy(45, 18);
			printf("          ");
			score += 0;
			combo = 0;
			gotoxy(45, 18);
			printf("콤보 : %d", combo);
			count += 1;
			gotoxy(45, 21);
			printf("틀린 횟수 : %d", count);
		}
	}
}


// 두번쨰 줄 노트
int note2(int sleep) {
	int loop = 0;
	for (loop = 0; loop < 33; loop++) {
		if (loop == 30) {
			continue;
		}

		else {
			note(13, loop + 1);
			Sleep(sleep);
			noteB(13, loop + 1);
		}
	}
	if (loop > 30) {
		if (_kbhit()) {
			int a = KeyBoradInput();
			if (a == 5) {
				score += scoreR;
				gotoxy(45, 15);
				printf("점수 : %d", score);
				gotoxy(45, 18);
				combo += 1;
				printf("콤보 : %d", combo);
			}
			else {
				score += 0;
				combo = 0;
				gotoxy(45, 18);
				printf("          ");
				gotoxy(45, 18);
				printf("콤보 : 0");
				count += 1;
				gotoxy(45, 21);
				printf("틀린 횟수 : %d", count);
			}
		}
		else {
			gotoxy(45, 18);
			printf("          ");
			score += 0;
			combo = 0;
			gotoxy(45, 18);
			printf("콤보 : %d", combo);
			count += 1;
			gotoxy(45, 21);
			printf("틀린 횟수 : %d", count);
		}
	}
}

// 세번째 줄 노트
void note3(int sleep) {
	int loop = 0;
	for (loop = 0; loop < 33; loop++) {
		if (loop == 30) {
			continue;
		}
		else {
			note(23, loop + 1);
			Sleep(sleep);
			noteB(23, loop + 1);
		}
	}
	if (loop > 30) {
		if (_kbhit()) {
			int a = KeyBoradInput();
			if (a == 6) {
				score += scoreR;
				gotoxy(45, 15);
				printf("점수 : %d", score);
				gotoxy(45, 18);
				combo += 1;
				printf("콤보 : %d", combo);
			}
			else {
				score += 0;
				combo = 0;
				gotoxy(45, 18);
				printf("          ");
				gotoxy(45, 18);
				printf("콤보 : 0");
				count += 1;
				gotoxy(45, 21);
				printf("틀린 횟수 : %d", count);
			}
		}
		else {
			gotoxy(45, 18);
			printf("          ");
			score += 0;
			combo = 0;
			gotoxy(45, 18);
			printf("콤보 : %d", combo);
			count += 1;
			gotoxy(45, 21);
			printf("틀린 횟수 : %d", count);
		}
	}
}

// 4번째 줄 노트
void note4(int sleep) {
	int loop = 0;
	for (loop = 0; loop < 33; loop++) {
		if (loop == 30) {
			continue;
		}
		else {
			note(33, loop + 1);
			Sleep(100);
			noteB(33, loop + 1);
		}
	}
	if (loop > 30) {
		if (_kbhit()) {
			int a = KeyBoradInput();
			if (a == 7) {
				score += scoreR;
				gotoxy(45, 15);
				printf("점수 : %d", score);
				combo += 1;
				gotoxy(45, 18);
				printf("콤보 : %d", combo);
			}
			else {
				score += 0;
				combo = 0;
				gotoxy(45, 18);
				printf("          ");
				gotoxy(45, 18);
				printf("콤보 : 0");
				count += 1;
				gotoxy(45, 21);
				printf("틀린 횟수 : %d", count);
			}
		}
		else {
			gotoxy(45, 18);
			printf("          ");
			score += 0;
			combo = 0;
			gotoxy(45, 18);
			printf("콤보 : %d", combo);
			count += 1;
			gotoxy(45, 21);
			printf("틀린 횟수 : %d", count);
		}
	}
}


// 주문을 외울게 매핑 // 테스트 값
void MAP() {
	gotoxy(45, 15);
	printf("점수 : ");
	gotoxy(45, 18);
	printf("콤보 : ");
	note1(100);
	note3(50);
	note4(40);
	note1(30);
	note4(40);
	note3(30);
	note2(40);
	note4(50);
	note1(60);
	note1(70);
	note4(60);
	note2(50);
	note1(50);
	note1(50);
	note1(50);
	note3(50);
	note4(30);
	note3(30);
	note2(30);
	note1(50);
	note3(60);
	note1(50);
	note2(50);
	note4(70);
	note2(50);
	note1(50);
	note4(70);
	note1(60);
	note2(50);
	note1(50);
	note4(60);
	note3(50);
	note2(50);
	note1(60);
	note3(50);
	note1(50);
	note2(50);
	note4(70);
}

// BMP
int width, height;

unsigned char* readBMP(const char* filename)
{
	FILE* f = fopen(filename, "rb");
	unsigned char info[54];


	fread(info, sizeof(unsigned char), 54, f);


	width = *(int*)&info[18];
	height = *(int*)&info[22];


	int size = 3 * width * height;
	unsigned char* data = (unsigned char*)malloc(size);


	fread(data, sizeof(unsigned char), size, f);
	fclose(f);

	int j;
	for (j = 0; j < size; j += 3)
	{

		unsigned char tmp = data[j];
		data[j] = data[j + 2];
		data[j + 2] = tmp;
	}

	return data;
}

void scoreframe(int score) {
	gotoxy(45, 15);
	printf("점수 : %d", score);
	gotoxy(45, 17);
	printf("콤보 : %d", score);

}

// bmp 뿌리기
void drawBMP() {
	HWND myconsole = GetConsoleWindow();
	HDC dc = GetDC(myconsole);
	int i;
	COLORREF color = RGB(0, 255, 0);
	int x = 0;
	int y = 0;
	unsigned char* arr = readBMP("C:\\Users\\gksrp\\Desktop\\44\\23\\hqdefaulst.bmp"); //   
	for (i = width * height; i > 0; i--) {
		color = RGB(arr[3 * i], arr[3 * i + 1], arr[3 * i + 2]);
		SetPixel(dc, (x + 380), (y + 30), color);
		x++;
		if (x % width == 0) {
			x = 0;
		}
		if (i % width == 0) {
			y++;
		}
	}
}

// 게임 프레임
void gameframe() {
	// 위
	printf("\u250c");
	int i;
	for (i = 0; i < 40; i++) {
		if (i == 10 || i == 20 || i == 30) {
			printf("\u252c");
		}
		else {
			printf("\u2500");
		}
	}
	// 오른쪽 , 칸
	printf("\u2510");
	for (i = 0; i < 30; i++) {
		gotoxy(41, i + 1);
		printf("\u2502");
	}
	gotoxy(41, i + 1);
	printf("\u2524");
	gotoxy(41, i + 1);
	printf("\u2502");
	gotoxy(41, i + 2);
	printf("\u2502");
	gotoxy(41, i + 3);
	printf("\u2502");


	for (i = 0; i < 30; i++) {
		gotoxy(31, i + 1);
		printf("\u2502");
	}
	gotoxy(31, i + 1);
	printf("\u2502");
	gotoxy(31, i + 2);
	printf("\u2502");
	gotoxy(31, i + 3);
	printf("\u2502");
	gotoxy(31, i + 1);
	printf("\u2534");
	for (i = 0; i < 30; i++) {
		gotoxy(21, i + 1);
		printf("\u2502");
	}
	gotoxy(21, i + 1);
	printf("\u2502");
	gotoxy(21, i + 2);
	printf("\u2502");
	gotoxy(21, i + 3);
	printf("\u2502");
	gotoxy(21, i + 1);
	printf("\u2534");
	for (i = 0; i < 30; i++) {
		gotoxy(11, i + 1);
		printf("\u2502");
	}
	gotoxy(11, i + 1);
	printf("\u2502");
	gotoxy(11, i + 2);
	printf("\u2502");
	gotoxy(11, i + 3);
	printf("\u2502");
	gotoxy(11, i + 1);
	printf("\u2534");

	// 왼쪽 줄
	for (i = 0; i < 30; i++) {
		gotoxy(0, i + 1);
		printf("\u2502");
	}
	gotoxy(0, i + 1);
	printf("\u251c");

	// 아래
	for (i = 0; i < 40; i++) {
		if (i == 10 || i == 20 || i == 30) {
			gotoxy(i, 42);
			printf("\u253c");
		}
		else {
			gotoxy(i, 42);
			printf("\u2500");
		}
	}

	// 판정선
	for (i = 0; i < 4; i++) {
		gotoxy(0, i + 30);
		printf("\u2502");
	}
	gotoxy(0, i + 30);
	printf("\u2514");
	for (i = 0; i < 40; i++) {
		if (i == 10 || i == 20 || i == 30) {
			gotoxy(i, 42);
			printf("\u2534");
		}
		else {
			gotoxy(i + 1, 42);
			printf("\u2500");
		}
	}

	gotoxy(i + 1, 42);
	printf("\u2518");
	printf("\n\n");
	printf("    ");
	system("pause");
	printf("\n\n");
	printf("  (종료 : E) (돌아가기 : R) (노트 : DFJK) (개발자 : HyeonJoong)");
}

// 메뉴 화면 구현
void menudraw() {
	gotoxy(22, 14);
	printf("게임 시작 = P\n");
	gotoxy(23, 15);
	printf("종료 = E\n");

}

// 창 크기
void start() {
	system("mode con cols=60 lines=20 | title 리듬게임 : 메뉴 화면");
}

void game() {
	system("mode con cols=65 lines=41 | title 리듬게임 : 게임 화면");
}

// 타이틀 
void title() {
	printf("\n\n\n");
	printf("        #       #    #    #    ###     #     ###          \n");
	printf("        # #   # #    #    #   #        #    #             \n");
	printf("        #  # #  #    #    #    ###     #   #              \n");
	printf("        #   #   #    #    #       #    #    #             \n");
	printf("        #   #   #     ####     ###     #     ####         \n");
}

// 메인
int main(void) {
	Init();
	int combo = 0;
	FILE* fp;
	FILE* fps;
	start();
	title();
	menudraw();
	int c;
	int music;
	int choice;
	int key = 0;
	int reload = 0;
	int a = KeyBoradInput();
	while (reload != 1) {
		key = 0;
		reload = 0;
		switch (a)
		{
		case 0: { // 음악 선택 메뉴
			system("cls");
			fp = fopen("C:\\Users\\gksrp\\Desktop\\44\\23\\musiclist.txt", "r");
			printf("==================================\n");
			printf("[1]\n");
			while ((c = fgetc(fp)) != EOF) {
				putchar(c);
			}
			printf("\n==================================");
			printf("\n\n");
			printf("==================================\n");
			printf("[2]\n");
			fps = fopen("C:\\Users\\gksrp\\Desktop\\44\\23\\musiclist2.txt", "r");
			while ((c = fgetc(fps)) != EOF) {
				putchar(c);
			}
			printf("\n==================================");
			fclose(fp);
			printf("\n");
			printf("\n음악을 선택해주세요 : ");
			scanf_s("%d", &music);

			if (music == 1) { // 주문을 외울게
				game();
				system("cls");
				gameframe();
				PlaySound(TEXT("C:\\Users\\gksrp\\Desktop\\44\\23\\ju.wav"), NULL, SND_ASYNC);
				MAP();
				system("cls");
				printf("점수 : %d", score);
				choice = KeyBoradInput();
				if (choice == 3) {
					PlaySound(NULL, NULL, 0);
					continue;
				}
				if (choice == 2) {
					return 0;
				}
			}
			break;
		}
		case 1: { // 조작법
			system("cls");
			break;
		}
		case 2: { // 종료
			return 0;
			break;
		}
		default: {
			return 0;
			break;
		}
		}
	}
	return 0;
}

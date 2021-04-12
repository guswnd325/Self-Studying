#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <mmsystem.h>
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

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void menudraw() {
	gotoxy(22, 14);
	printf("음악 듣기 = p\n");
	/* 메뉴 2 gotoxy(26, 15);
	printf(" = m\n");
	*/
	gotoxy(24, 16);
	printf("종료 = esc\n");
}

void start() {
	system("mode con cols=60 lines=20 | title HyeonJoong 음악 플레이어!");
}
void player() {
	system("mode con cols=70 lines=20");
}

int KeyBoradInput() {
	int keycode;
	keycode = getch();
	if (keycode == 'p' || keycode == 'P') {
		return 0;
	}
	if (keycode == 'm' || keycode == 'M') {
		return 1;
	}
	if (keycode == 'e' || keycode == 'E') {
		return 2;
	}
	if (keycode == 'r' || keycode == 'R') {
		return 3;
	}
}


void title() {
	printf("\n\n\n");

	printf("        #       #    #    #    ###     #     ###          \n");
	printf("        # #   # #    #    #   #        #    #             \n");
	printf("        #  # #  #    #    #    ###     #   #              \n");
	printf("        #   #   #    #    #       #    #    #             \n");
	printf("        #   #   #     ####     ###     #     ####         \n");


}
int main() {
	HWND myconsole = GetConsoleWindow();
	HDC dc = GetDC(myconsole);
	int i;
	COLORREF color = RGB(0, 255, 0);
	int x = 0;
	int y = 0;
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
		case 0: {
			system("cls");
			fp = fopen("C:\\Users\\gksrp\\Desktop\\44\\23\\musiclist.txt", "r");
			printf("==================================\n");
			printf("(1)\n");
			while ((c = fgetc(fp)) != EOF) {
				putchar(c);
			}
			printf("\n==================================");
			printf("\n");
			printf("==================================\n");
			printf("(2)\n");
			fps = fopen("C:\\Users\\gksrp\\Desktop\\44\\23\\musiclist2.txt", "r");
			while ((c = fgetc(fps)) != EOF) {
				putchar(c);
			}
			printf("\n==================================");
			fclose(fp);
			printf("\n트실 음악을 입력해주세요 : ");
			scanf_s("%d", &music);
			if (music == 1) {
				system("cls");
				player();
				Sleep(100);
				unsigned char* arr = readBMP("C:\\Users\\gksrp\\Desktop\\44\\23\\hqdefault.bmp"); //   
				x = 0; y = 0;
				for (i = width * height; i > 0; i--) {
					color = RGB(arr[3 * i], arr[3 * i + 1], arr[3 * i + 2]);
					SetPixel(dc, (x + 300), (y + 50), color);
					x++;
					if (x % width == 0) {
						x = 0;
					}
					if (i % width == 0) {
						y++;
					}
				}
				printf("돌아가기 = r, 종료 = e");
				gotoxy(10, 9);
				printf("곡 이름 : 주문을 외울게\n");
				gotoxy(10, 10);
				printf("아티스트 : M2U\n");
				PlaySound(TEXT("C:\\Users\\gksrp\\Desktop\\44\\23\\ju.wav"), NULL, SND_ASYNC); // 경로
				choice = KeyBoradInput();
				if (choice == 3) {
					PlaySound(NULL, NULL, 0);
					continue;
				}
				if (choice == 2) {
					return 0;
				}
			}
			if (music == 2) {
				system("cls");
				player();
				Sleep(100);
				unsigned char* arr = readBMP("C:\\Users\\gksrp\\Desktop\\44\\23\\muyaho.bmp"); // 경로
				x = 0; y = 0;
				for (i = width * height; i > 0; i--) {
					color = RGB(arr[3 * i], arr[3 * i + 1], arr[3 * i + 2]);
					SetPixel(dc, (x + 300), (y + 50), color);
					x++;
					if (x % width == 0) {
						x = 0;
					}
					if (i % width == 0) {
						y++;
					}
				}
				printf("돌아가기 = r, 종료 = e");
				gotoxy(10, 9);
				printf("곡 이름 : 무야호 리믹스\n");
				gotoxy(10, 10);
				printf("아티스트 : JEFF");
				PlaySound(TEXT("C:\\Users\\gksrp\\Desktop\\44\\23\\muyaho.wav"), NULL, SND_ASYNC); // 경로
				choice = KeyBoradInput();
				if (choice == 3) {
					PlaySound(NULL, NULL, 0);
					continue;
				}
				if (choice == 2) {
					return 0;
				}
			}
		}
		case 1: {
			system("cls");
			break;
		}
		case 2: {
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

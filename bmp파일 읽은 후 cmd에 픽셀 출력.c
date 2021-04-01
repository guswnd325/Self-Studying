#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

int width, height;

unsigned char* readBMP(const char* filename)
{
    FILE* f = fopen(filename, "rb");
    unsigned char info[54];

    // 비트맵 정보를 읽어들임.
    fread(info, sizeof(unsigned char), 54, f);

    // 읽은 비트맵 정보에서 width,height값을 각각 할당.
    width = *(int*)&info[18];
    height = *(int*)&info[22];

    // 3바이트마다 1픽셀 씩 할당. rgb데이터를 저장할 곳을 만들어준다.
    int size = 3 * width * height;
    unsigned char* data = (unsigned char*)malloc(size);

    // 파일에서 데이터값을 읽은 후 할당함. 파일 닫음.
    fread(data, sizeof(unsigned char), size, f);
    fclose(f);
    // size값은 3bit x 사이즈, 즉 3바이트마다 배열로 선언해주면된다.
    int j;
    for (j = 0; j < size; j += 3)
    {
        // 3bit 마다 r g b값 받기.
        unsigned char tmp = data[j];
        data[j] = data[j + 2];
        data[j + 2] = tmp;
    }

    return data; // 데이터 배열을 반환함.
}
//
int main() {
    Sleep(100);
    HWND myconsole = GetConsoleWindow();
    HDC dc = GetDC(myconsole);
    int i;
    int a = 0;
    COLORREF color = RGB(0, 255, 0);
    int x = 0;
    int y = 0;
//

    unsigned char* arr = readBMP("C:\\Users\\gksrp\\Desktop\\44\\images.bmp");

    // 
    for (i = width * height; i > 0; i--) {
        color = RGB(arr[3 * i], arr[3 * i + 1], arr[3 * i + 2]);
        SetPixel(dc, x, y, color); 
        x++;
        if (x == width) {
            x = 0;
        }
        if (i % width == 0) {
            y++;   
        }      
    }
    while (1) {
     Sleep(100); 
    }
    
    return 0;
}
//

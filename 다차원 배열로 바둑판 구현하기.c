// 0 = 검은 돌
// 1 = 휜색 돌
// 2 = 프로그램 종료
#include <stdio.h>

int main(void) {
    char map[19][19] = { 0 };
    int a = 0;
    int color, floor, room;
    while (a != 2) {
        scanf("%d %d %d", &color, &floor, &room);
        if (color == 0) {
        map[floor-1][room-1] = 'B';
        }
        else if (color == 1) {
            map[floor-1][room-1] = 'W';
        }
        if (color == 2){
            break;
        }
    }
    for (int i = 0; i < 19; i++)
    {
      for (int j = 0; j < 19; j++)
    {
      printf("%c ", map[i-1][j-1]);
    }
    printf("\n");
    }
    return 0;
}


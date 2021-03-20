#include <stdio.h>

int main(void) {
    int num1, num2, big, small, list[1000];
    int be = 0;
    int st = 0;
    printf("첫 번째 수 : ");
    scanf("%d", &num1);
    printf("두 번째 수 : ");
    scanf("%d", &num2);
    if (num1 < num2) {
        big = num2; small = num1;
    }
    else {
        big = num1; small = num2;
    }
    printf("공약수\n");
    for (int i = 1; i <= big; i++) {
        if (num1 % i == 0 && num2 % i == 0) {
            printf("%d\n", i);
            list[be] = i;
            be++;
        }
    }
    while (list[st] != '\0') {
      st++;
    }
    printf("최대 공약수는 %d입니다\n", list[st-1]);

    return 0;
}

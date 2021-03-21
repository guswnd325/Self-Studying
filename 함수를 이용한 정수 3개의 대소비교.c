#include <stdio.h>

int Big(int a, int b, int c) {
    if (a > b) {
        return (a > c ? a : c);
    }
    else {
        return (b > c ? b : c);
    }
}

int Small(int d, int e, int f) {
    if (d < e) {
        return (d < f ? d:f);
    }
    else {
        return (e < f ? e : f);
}
}


int main(void) {
    int Num1, Num2, Num3;
    printf("첫 번째 수 : ");
    scanf("%d", &Num1);
    printf("두 번째 수 : ");
    scanf("%d", &Num2);
    printf("세 번째 수 : ");
    scanf("%d", &Num3);
    int big = Big(Num1, Num2, Num3);
    int small = Small(Num1, Num2, Num3);
    printf("가장 큰 값은 : %d\n", big);
    printf("가장 작은 값은 : %d\n", small);
}

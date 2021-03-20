#include <stdio.h>

int main(void) {
    int size1, size2;
    printf("세로 : ");
    scanf("%d", &size1);
    printf("가로 : ");
    scanf("%d", &size2);
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}


#include <stdio.h>

int main(void) {
    int floor;
    printf("floor : ");
    scanf("%d", &floor);
    for (int i = 0; i < floor; i++) {
        for (int j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}

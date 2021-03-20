#include <stdio.h>

int main(void) {
    int floor, setfloor, blank, star;
    printf("floor : ");
    scanf("%d", &floor);
    for (setfloor = 0; setfloor < floor; setfloor++) {
        for (blank = floor; blank > setfloor; blank--) {
            printf(" ");
        }
        for (star = 0; star <= 2 * setfloor; star++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

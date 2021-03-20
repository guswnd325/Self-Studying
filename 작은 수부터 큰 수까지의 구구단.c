#include <stdio.h>

int main(void) {
    int num1, num2, big, small, setnum;
    printf("answer : ");
    scanf("%d %d", &num1, &num2);
    if (num1 > num2) {
        big = num1;
        small = num2;
    }
    else {
        big = num2;
        small = num1;
    }
    
    setnum = small;
    for (; setnum <= big; setnum++) {
        for (int j = 1; j < 10; j++) {
            printf("%d x %d = %d\n", setnum, j, (setnum * j));
            }
        printf("\n");
    }
    return 0;
}


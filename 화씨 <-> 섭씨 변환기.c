#include <stdio.h>

float CelToFah (float c) {
    return 1.8 * c + 32;
}

float FahToCel (float d) {
    int p = 32;
    return d-p/1.8;
}

int main(void) {
    float cel, fah; int a; float result;
    printf("섭씨 -> 화씨 = 1\n");
    printf("화씨 -> 섭씨 = 2\n");
    printf("> ");
    scanf("%d", &a);
    switch (a) {
        case 1:
            scanf("%f", &cel);
            result = CelToFah(cel);
            printf("%.2f", result);
            break;
        case 2:
            scanf("%f", &fah);
            result = FahToCel(fah);
            printf("%.2f", result);
            break;
        default:
            break;
    }
    return 0;
}


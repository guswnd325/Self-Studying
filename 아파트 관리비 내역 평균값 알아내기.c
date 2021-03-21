#include <stdio.h>

int main(void) {
    int floor;
    int i = 0;
    printf("몇 층의 관리비 평균을 보실건가요?\n");
    printf("> ");
    scanf("%d", &floor);
    int house[3][4] = {{111000,125000,136000,98000}, {136000, 142000, 112000, 135000}, {127000, 133000,155000,143000}};
    int OneSum = 0;
    int TwoSum = 0;
    int ThreeSum = 0;
    int OneFaverage = 0;
    int TwoFaverage = 0;
    int ThreeFaverage = 0;
    int allaverage = 0;
            for (i = 0; i < 4; i++) {
                OneSum += house[0][i];
                OneFaverage = OneSum / 4;
            }
            for (i = 0; i < 4; i++) {
                TwoSum+= house[1][i];
                TwoFaverage = TwoSum / 4;
            }
            for (i = 0; i < 4; i++) {
                ThreeSum += house[2][i];
                ThreeFaverage = ThreeSum / 4;
            }
    switch (floor) {
        case 1: {
            printf("%d층의 관리비 평균은 \'%d\'입니다\n", floor, OneFaverage);
            break;
        }
        case 2: {
            printf("%d층의 관리비 평균은 \'%d\'입니다\n", floor, TwoFaverage);
            break;
        }
        case 3: {
            printf("%d층의 관리비 평균은 \'%d\'입니다\n", floor, ThreeFaverage);
            break;
        }
        default: {
            printf("존재 하지 않는 데이터 값입니다\n");
            break;
        }
    }

    printf("아파트 전체 관리비 평균을 보시겠습니까? (1/2)\n");
    printf("> ");
    int choice;
    int floorall;
    int Number;
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            printf("아파트의 전체 층수를 입력해주세요 : ");
            scanf("%d", &floorall);
            printf("아파트의 한층의 호실 갯수를 입력해주세요 : ");
            scanf("%d", &Number);
            allaverage = (OneSum + TwoSum + ThreeSum) / (floorall * Number);
            printf("아파트 전체 관리비의 평균 : \'%d\'\n", allaverage);
            break;
        }
        case 2: {
            printf("프로그램을 종료합니다......\n");
            break;
        }
        default:
            break;
    }
    return 0;
}

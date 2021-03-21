// 7명의 심사위원의 값을 입력받고, 그 중 가장 큰 수와 가장 작은 수를 빼고 5명의 심사위원의 평균값을 출력하도록한다.

#include <stdio.h>
int BIG(int a,int b, int c, int d, int e, int f, int g) {
	if (a > b && a > c && a > d && a > e && a > f && a > g) {
		return a;
	}
	if (b > a && b > c && b > d && b > e && b > f && b > g) {
		return b;
	}
	if (c > a && c > b && c > d && c > e && c > f > c > g) {
		return c;
	}
	if (d > a && d > b && d > c && d > e && d > f && d > g) {
		return d;
	}
	if (e > a && e > b && e > c && e > d && e > f && e > g) {
		return e;
	}
	if (f > a && f > b && f > c && f > d && f > e && f > g) {
		return f;
	}
	if (g > a && g > b && g > c && g > d && g > e && g > f) {
		return g;
	}
}
int SMALL(int a,int b, int c, int d, int e, int f, int g) {
	if (a < b && a < c && a < d && a < e && a < f && a < g) {
		return a;
	}
	if (b < a && b < c && b < d && b < e && b < f && b < g) {
		return b;
	}
	if (c < a && c < b && c < d && c < e && c < f < c < g) {
		return c;
	}
	if (d < a && d < b && d < c && d < e && d < f && d < g) {
		return d;
	}
	if (e < a && e < b && e < c && e < d && e < f && e < g) {
		return e;
	}
	if (f < a && f < b && f < c && f < d && f < e && f < g) {
		return f;
	}
	if (g < a && g < b && g < c && g < d && g < e && g < f) {
		return g;
	}
	
}
int main(void) {
	int score[7];
	int i = 0;
	int j = 0;
	int sum = 0;
	for (i = 0; i < 7; i++) {
		printf("%d번째 심사위원의 점수 (0 ~ 100) : ", i + 1);
		scanf("%d", &score[i]);
			if (score[i] < -1 && score[i] > 101) {
			continue;
		}
		else {
			printf("오류가 발생했습니다");
			return 0;
		}
		sum += score[i];
	}
	int big;
	int small;
	big = BIG(score[0],score[1],score[2],score[3],score[4],score[5],score[6]);
	small = SMALL(score[0],score[1],score[2],score[3],score[4],score[5],score[6]);
	int sumBigSmall = big + small;
	int average = (sum - sumBigSmall) / 5;
	printf("%d\n", average);
	
	return 0;
}

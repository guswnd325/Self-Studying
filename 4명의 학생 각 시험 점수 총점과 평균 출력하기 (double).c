double totalScore(double score[]) {
    double sum = 0;
    int i = 0;
    for (i = 0; i < 6; i++) {
        sum += score[i];
    }
    return sum;
}
double average(double score[]) {
    double sum = 0;
    int i = 0;
    for (i = 0; i < 6; i++) {
        sum += score[i];
    }
    return (sum / 4);
}

#include <stdio.h>

int main(void) {
    double student1[6] = {87,92,95,91,0,0};
    double student2[6] = {68,95,76,88,0,0};
    double student3[6] = {77,88,91,87,0,0};
    double student4[6] = {78,81,96,76,0,0};
    double student1sum = totalScore(student1);
    double student2sum = totalScore(student2);
    double student3sum = totalScore(student3);
    double student4sum = totalScore(student4);
    double student1average = average(student1);
    double student2average = average(student2);
    double student3average = average(student3);
    double student4average = average(student4);
    printf("1번 학생의 총점 : %lf, 평균 : %lf\n", student1sum, student1average);
    printf("2번 학생의 총점 : %lf, 평균 : %lf\n", student2sum, student2average);
    printf("3번 학생의 총점 : %lf, 평균 : %lf\n", student3sum, student3average);
    printf("4번 학생의 총점 : %lf, 평균 : %lf\n", student4sum, student4average);
    return 0;
}

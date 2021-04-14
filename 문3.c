#include <stdio.h>

int main(void)
{
    int Arr[100][100] = {0,};

    int n;
    scanf("%d",&n);
    int center = (n+1)/2;
    int num = 0;
    
    int y = 1;
    int x = center;
    for(int k = 0; k< n*n; k++){
        Arr[y][x] = ++num;
        if(num%n == 0)
        {
          y++;
          }
        else
        {
            y--;
            x++;
        }
        if(y < 1)
        {
           y = n;
           }
        if(x > n)
        {
          x = 1;
          }
        
    }
 
 printf("참가번호(01) 성명() 학교명()\n");
 printf("==========================================================\n");
    for(y = 1; y <=n; y++){
        for(x = 1; x<= n; x++){
            printf("%d ",Arr[y][x]);
        }
        printf("\n");
    }
 
    return 0;
}
 

#include <stdio.h> 


//19
//17
//15

int main(void) {
	
	int setfloor, blank, star,i = 0 , setM = 0, j = 0, k = 0, g = 0, temp = 7, temp2 = 19, temp3 = 15;
	
		for (setfloor = 0; setfloor < 3; setfloor++) 
		{
		for (blank = 9; blank > setfloor; blank--) 
		{
			printf(" ");
		}
		for (star = 0; star <= 2 * setfloor; star++) 
		{
			printf("*");
		}
		printf("\n");
}
		for (i = 0; i < 19; i++) 
		{
		printf("*");
		} 
		printf("\n");
		for (i = 0; i < 3; i++) 
		{
		for (j = 0; j <= i; j++) 
		{
			printf(" "); // 19 17 15
		}
		for(k = 0; k < temp2-2; k++) 
		{
			printf("*");
		}
		printf("\n");
		temp2--;
		temp2--;
		}
		for (i = 0; i < 3; i++) {
		for (j = 0; j <= 1-i; j++) {
			printf(" ");
		}
		for (k = 0; k <temp3; k++) {
			printf("*");
		}
		printf("\n");
		temp3++;
		temp3++;
		}
		for (setfloor = 0; setfloor < 3; setfloor++) {
		for (blank = 0; blank < temp; blank++) { // 7 8 9
			printf(" ");
		}
		temp++;
		for (star = 5; star > 2 * setfloor; star--) {
			printf("*");
		}
		printf("\n");
} 
	 	return 0;
}




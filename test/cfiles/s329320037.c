#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int GetDigit(int num){
	int digit = 0;
	while (num != 0){
		num /= 10;
		digit++;
	}
	return digit;
}

int main(void)
{	
	double a;
	

	int sum = 0;
	int max = 0;
	scanf("%lf", &a);


	for (int i = 0; i <= a; i++){
		int num = GetDigit(i);
		int i_copy = i;
		for (int j = 0; j < num; j++){
			sum += i_copy % 10;
			i_copy /= 10;
		}
		
		if (sum > max){
			max = sum;
		}
		sum = 0;
	}
	
	printf("%d\n",max);

	return 0;

}
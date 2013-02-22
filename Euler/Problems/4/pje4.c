//******************************************************
// Project Euler - Problem 4
// Coded by Tom Wilkinson
// 17/01/2013
//******************************************************

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int getDigitFromDec(double dec, int dig)
{
	dec /= pow(10,dig);
	//printf("digit: %d\n",((int)dec % 10));
	return (int)dec % 10;
}

double checkpalindrome(double num)
{
	int k, digit;
	int array[6];
	//num = 123321;
	for(k=0;k<6;k++)
	{
		
		digit = getDigitFromDec(num, k);
		array[k] = digit;
		//printf("num: %f k: %d, digit: %d\n", num, k, array[k]);
	}
	
	//printf("num: %f k: %d\n", num, k);
	//printf("%d  %d  %d  %d  %d  %d\n", array[0], array[1], array[2], array[3],array[4],array[5]);
	
	if(array[0] == array[5] && array[1] == array[4] && array[2] == array[3] )
	{
	return 1;	
	}
	else
	{
		return 0;
	}
}

int pje4()
{
	
	int i,j;
	double num, num2, ans;
	
	for (i = 100;i<1000;i++)
	{
		for(j = 100;j<1000;j++)
		{
			num = j * i;
			num2 = num;
			if (checkpalindrome(num)==1)
			{				
			ans = num2;
			}
		}
		printf("ans: %f num: %f\n", ans, num2);
	}
	
	//printf("Answer: %f\n", ans);
	
	return 0;
}

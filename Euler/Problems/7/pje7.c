//****************************************
// Project Euler Problem 7
// Author - Tom Wilkinson
// Date - 17/1/13
//****************************************

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

double checkprime (double num)
{
	double counter = 2;
	double fpart, ipart, d;
	while (1)
	{
		d = num/counter;
		fpart = modf (d, &ipart);
		
		if (!(fpart != 0)) return 0;
		if ((num/counter) < counter) return counter;
		counter++;
	}
}

int main(void)
{
	int p = (int) getpid();
	clock_t cstart = clock();
	clock_t cend = 0;	
	
	double num, start, i;
	int fin;
	
	printf("Finds the nth prime. Enter n:\n");
	scanf("%d", &fin);
	
	printf("n=%d\n",fin);
	
	fin += 1;
	
	while(start<fin)
	{
		if(checkprime(i))
		{
			start++;
		}
		i++;
	}
	
	printf("Answer: %f\n", i-1);
		
	cend = clock();
	printf ("%.3f cpu sec\n", ((double)cend - (double)cstart)* 1.0e-6);
	
	return 0;
}

#include <stdio.h>
#include <math.h>

// finds sum of all multiples of 3 and/or 5 below 1000

double pje1()
{

	int num;
//	int end;
    double sum = 0;
	int max;
	int i;
	int div;
	
	max = 1000;
	for(i=0; i < max; i++)
	{
	num = i;
	
	if (num % 3 == 0)
	{
		div++;
	}
	else if (num % 5 == 0)
	{
		div++;
	}
	else
	{
	div = 0;
	}
	
	if ( div != 0)
	{
		sum = sum + num; 
			
	div = 0;
	}
	}
   // printf("Problem 1. Sum = %f \n", sum);

    return sum;

}

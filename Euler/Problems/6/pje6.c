//****************************************
// Project Euler Problem 6 
// Author - Tom Wilkinson
// Date - 17/1/13
//****************************************


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int pje6()
{

	double sqr, sum, sqr_sum, dif;
	int i,max;
	
	printf("Finds the difference between the (1 to max)^2 and (sum(1 to max))^2.\nEnter max:");
	scanf("%d",&max);
	
	for(i=1;i<max+1;i++)
	{
		sqr += (i*i);
		
		sum += i;
	}
	
	sqr_sum = sum*sum;
	
	printf("Sum of sqr: %f\nSqr: %f\n",sqr_sum, sqr);
	
	dif = sqr_sum - sqr;
	
	printf("Answer: %f\n",dif);

	return 0;
}

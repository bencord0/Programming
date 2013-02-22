#include <stdio.h>
#include <math.h>

//Solves Project Euler Problem 2

int main()
{
	double numa, numb, div, fib;
	double max;
	double sum;
	double i;
	double fractpart, intpart;
	
	sum = 0;
	max = 4000001;
	i = 2;
	fib = 1;
	
	while (i < max)
	{
		numa = fib;
		numb = i;
		fib = numb;
				
		div = numb / 2;
		fractpart = modf (div, &intpart);
		if (fractpart == 0)
		{
			sum += numb;
		}
		
		i = numa + numb;
	}
	
	printf("sum = %f\n", sum);
	
	return 0;
}
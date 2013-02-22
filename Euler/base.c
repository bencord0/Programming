//****************************************
// Project Euler Problem 
// Author - Tom Wilkinson
// Date -
//****************************************


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
	int p = (int) getpid();
	clock_t cstart = clock();
	clock_t cend = 0;
	
	cend = clock();
	printf ("%.3f cpu sec\n", ((double)cend - (double)cstart)* 1.0e-6);
	
	return 0;
}

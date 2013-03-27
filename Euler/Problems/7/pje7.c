//****************************************
// Project Euler Problem 7
// Author - Tom Wilkinson
// Date - 17/1/13
//****************************************

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include <unistd.h>

/*double checkprime (double num)
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
}*/

double pje7()
{
	
    double start = 0;
    double i = 0;
	int fin;

    //printf("Finds the nth prime. Enter n:\n");
    //scanf("%d", &fin);
    fin = 10001;
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
	
  //  printf("Problem 7. Answer: %f\n", i-1);
		
    return i-1;
}

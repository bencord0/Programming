#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

double pje3(int go)
{

    double num, start, i, fractpart, intpart, div, ans;
	
    if(go == 0){
        return 0;
    }
    else{
	start = 600851475143;
	//start = 13195;
	num = sqrt (start); //trial division of primes - see wikipedia
	
	while (i < num)
	{
		div = start / i;
		
		if (checkprime (i))
		{
			fractpart = modf (div, &intpart);
		if (fractpart == 0)
			{
				ans = i;
			}
		}
				
		i++;
	}
	
	printf("Answer: %f\n", ans);
		
    return ans;
    }
}

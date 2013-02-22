//****************************************
// Project Euler Problem 5
// Author - Tom Wilkinson
// Date - 17/1/13
//****************************************

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int pje5()
{
		

	int max, i, j, ans, div;
	
	printf("Calculates smallest number evenly divisible by 1 to max. Enter max: ");
	scanf("%d", &max);
	
	ans=0;
	j=2;
	
	while(ans==0)
	{
		div = 0;
		for(i=2;i<max+1;i++)
		{
			if( j % i != 0)
			{
				div++;
			}
		}
		
		if(div==0)
		{
			ans = j;
		}
		j++;
		
	}
	
	printf("Answer: %d\n",ans);
	
	return 0;
}

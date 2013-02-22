#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])	/*Makes program use command line arguments*/
{
	double a, b, c, x1, x2;	/*Define variable names*/
	a = 0; b = 0; c = 0;	/*Set all variables to zero erases any data previously saved to these names*/
	
	if(argc!=4)		/*The number of arguments must be four*/
	{
		printf("Error: Must be of form: prog2A a b c for any quadratic ax^2+bx+c=0\n");
		return 0;
	}
	
	a = strtod(argv[1],0);	/*Setting the array values to variables*/
	b = strtod(argv[2],0);
	c = strtod(argv[3],0);
	
	if(a==0)
	{
		printf("A cannot be 0\n");
		return 0;
	}
	
	if(((b*b)-(4*a*c))<0)	/*Accounts for imaginnary roots*/
	{
		printf("There are 0 roots\n");
		printf("The determinant is less than zero so no real roots can be found\n");
		return 0;
	}
	
	else if (((b*b)-(4*a*c))==0)	/*Accounts for equal roots case*/
	{
        	printf("There is 1 root\n");
		printf("The determinant is zero so the roots are equal\n");		
    	}
	
	else if (((b*b)-(4*a*c))>0)	/*All other cases*/
    	{
        	printf("There are 2 roots\n");
    	}
	
	x1  = (-b+sqrt((b*b)-(4*a*c)))/(2*a);	/*Calculates the two roots*/
	x2 = (-b-sqrt((b*b)-(4*a*c)))/(2*a);
	printf("Root1 = %f",x1);
	printf(" Root2 = %f\n",x2);
	return 0;
}

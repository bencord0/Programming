/************************************
**Tom Wilkinson
**Uni ID: 0707007
**Assignment 2A
************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char *argv[ ])
{
	/*Declare variables*/
	int valid1, valid2, valid3;
	float a, b, c, X1, X2, det;
	/*Ensure all variables are set to zero at start*/
	a = 0; b = 0; c = 0; X1 = 0; X2 = 0; det = 0;
	/*Take command line values to variables a, b and c*/
	valid1=sscanf(argv[1], "%f", &a);
	valid2=sscanf(argv[2], "%f", &b);
	valid3=sscanf(argv[3], "%f", &c);
	/*Check correct number of variables entered*/
	if (argc !=4)
	{
		printf("Please enter 3 variables as command line arguments.\n");
		printf("For the quadratic ax^2 + bx +c, use the form: prog2A a b c\n");
		return 0;
	}
	/*Check numbers entered*/
	if ((valid1) && (valid2) && (valid3))
	{
		printf("Calculating.");
 	}
	else
	{
		printf("Please enter only numbers\n");
		return (EXIT_FAILURE);
	}
	/*Check a is not =0*/
	if (a ==0)
	{
		printf("a is 0, this is not a quadratic equation\n");
		return (EXIT_FAILURE);
	}
	/*Calculate Determinant*/
	det = ((b*b) - (4*a*c));
	/*Determine number of roots*/
	if (det <0)
	{
		printf("There are 0 roots\n");
		printf("Reason: If the determinant is less than zero all roots are imaginary\n");
		return 0;
	}
	else if (det ==0)
	{
		printf("There is 1 root\n");
	}
	else if (det >0)
	{
		printf("There are 2 roots\n");
	}
	/*Calculate X1*/
	X1 = ((-b + sqrt(det))/(2*a));
	/*Calculate X2*/
	X2 = ((-b - sqrt(det))/(2*a));
	/*Return results*/
	printf("Root1=%f  Root2=%f\n", X1, X2);
	return 0;
}

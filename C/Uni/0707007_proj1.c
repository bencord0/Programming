/********************************
** Uni ID: 0707007
** Final Assignment
********************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char *argv[])
{
	/*Declare variables*/
	int i, valid1, valid2, valid3, valid4, valid5, valid6;
	int valid_inputs;
	float m_minus, m_plus, x0, y0, vel_x, vel_y, dt, a_plus, a_minus, r_plus, r_minus, partrad;
	float ax_plus, ay_plus, ax_minus, ay_minus, y, x, time, yprev, xprev, xtemp, ytemp;
	FILE *output;
	/*Set all variables to zero*/
	x0 = 0; y0 = 0; vel_x = 0; vel_y = 0; m_minus = 0; m_plus = 0; valid_inputs = 0;
	time = 0; i = 0; valid1 = 0; valid2 = 0; valid3 = 0; valid4 = 0; valid5 = 0; valid6 = 0;
	a_minus = 0; a_plus = 0; r_plus = 0; r_minus = 0; y = 0; x = 0;
	ax_plus = 0; ax_minus = 0; ay_plus = 0; ay_minus = 0; dt = 0;
	/*Set timestep*/
	dt = 0.005;
	/*Check correct number of variables*/
	if (argc != 7)
		{
		printf("Please enter 6 values.\n");
		printf("Input of the form: x0, y0, mass-, mass+, v in x direction, v in y direction.\n");
		return (EXIT_FAILURE);
		}
	/*Take Command line values to variables*/
	valid1=sscanf(argv[1], "%f", &x0);
	valid2=sscanf(argv[2], "%f", &y0);
	valid3=sscanf(argv[3], "%f", &m_minus);
	valid4=sscanf(argv[4], "%f", &m_plus);
	valid5=sscanf(argv[5], "%f", &vel_x);
	valid6=sscanf(argv[6], "%f", &vel_y);
	/*Check entered variables are valid*/
	valid_inputs = (valid1 != 0) && (valid1 != EOF);
	valid_inputs = valid_inputs && (valid2 != 0) && (valid2 != EOF);
	valid_inputs = valid_inputs && (valid3 != 0) && (valid3 != EOF);
	valid_inputs = valid_inputs && (valid4 != 0) && (valid4 != EOF);
	valid_inputs = valid_inputs && (valid5 != 0) && (valid5 != EOF);
	valid_inputs = valid_inputs && (valid6 != 0) && (valid6 != EOF);
	
	if (valid_inputs)
		{
		printf("Calculating ...\n");
		}
	else
		{
		printf("Inputs invalid. Program Ends.\n");
		return (EXIT_FAILURE);
		}
	/*Open file to output data to*/
	output=fopen("0707007_proj1.out", "w");
	/*Print start of file*/
	fprintf(output, "Tom Wilkinson: Restricted 3-Body Force problem\n");
	fprintf(output, "Initial values: x0=%f y0=%f vel_x0=%f vel_y0=%f m+=%f m-=%f\n", x0, y0, vel_x, vel_y, m_plus, m_minus);
	fprintf(output, "x y t\n");
	/*Ensure x and y start at x0*/
	x = x0; y = y0;
	/*Set temporary x and y*/
	xtemp = 0; ytemp = 0;
	/*Find radial distance from both masses*/
	r_plus = sqrt((x-1)*(x-1) + (y*y));
	r_minus = sqrt((x+1)*(x+1) + (y*y));
	/*Find acceleration in terms of r+ and r-*/
	a_plus = -((m_plus*r_plus)/(fabs((r_plus)*(r_plus)*(r_plus))));
	a_minus = -((m_minus*r_minus)/(fabs((r_minus)*(r_minus)*(r_minus))));
	/*Find acceleration in terms of x and y*/
	ax_plus = ((x-1)*a_plus)/r_plus;
	ax_minus = ((x+1)*a_minus)/r_minus;
	ay_plus = (y*a_plus)/r_plus;
	ay_minus = (y*a_minus)/r_minus;
	/*Find new velocities*/
	vel_x = vel_x + (ax_plus + ax_minus)*dt;
	vel_y = vel_y + (ay_plus + ay_minus)*dt;
	/*Find new x and y values*/
	x = x0 + vel_x*dt;
	y = y0 + vel_y*dt;
	time = dt;
	fprintf(output, "%f %f %f\n", x, y, time);
	/*Set n-1 x and y values*/
	xprev = x0;
	yprev = y0;
	/*Set particle radius for collision detection*/
	partrad = 0.1;
	/*Start loop with collision detection*/
	while (i < 10000)
		{
		if(x < (1+partrad) && x > (1-partrad) && y < (0+partrad) && y > (0-partrad))
			{
			printf("The particle collided with m+ at %f seconds\n", time);
			return (EXIT_FAILURE);
			}
		else if(x < (-1+partrad) && x > (-1-partrad) && y < (0+partrad) && y > (0-partrad))
			{
			printf("The particle collided with m- at %f seconds\n", time);
			return (EXIT_FAILURE);
			}
		else 
		{
		/*Find radial distance from both masses*/
		r_plus = sqrt((x-1)*(x-1) + (y*y));
		r_minus = sqrt((x+1)*(x+1) + (y*y));
		/*Find acceleration in terms of r+ and r-*/
		a_plus = -((m_plus*r_plus)/(fabs((r_plus)*(r_plus)*(r_plus))));
		a_minus = -((m_minus*r_minus)/(fabs((r_minus)*(r_minus)*(r_minus))));
		/*Find acceleration in terms of x and y*/
		ax_plus = ((x-1)*a_plus)/r_plus;
		ax_minus = ((x+1)*a_minus)/r_minus;
		ay_plus = (y*a_plus)/r_plus;
		ay_minus = (y*a_minus)/r_minus;
		/*Temporary x and y assigned*/
		xtemp = x;
		ytemp = y;
		/*Find new x and y*/
		x = (2*x) - xprev + (dt*dt*(ax_plus + ax_minus));
		y = (2*y) - yprev + (dt*dt*(ay_plus + ay_minus));
		/*Find time passed*/
		time += dt;
		fprintf(output, "%f %f %f\n", x, y, time);
		xprev = xtemp;
		yprev = ytemp;
		i++;
		}
	}
 	printf("Data printed to file.\n");
	fclose(output);
	/*End program*/ 	
	return (EXIT_SUCCESS);
}

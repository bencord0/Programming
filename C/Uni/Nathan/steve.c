*****************************************************
**Student# 0717670
**C Programming Final - Three Body Problem
** (Command Code: gcc -lm problem1.c -o problem1)
**
******************************************************/
#include <stdio.h>           /*Libraries to draw upon*/
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define PARTICLE_SIZE 0.05f     /*Here the particle size is inputted*/
#define MAX_RUN_TIME 5000.0f    /*Here the maximum run time is inputted*/

struct sBody { /*Hold details of bodies*/
  double mass; /*Mass*/
  double x; /*Position*/
  double y;
  double vx; /*Velocity*/
  double vy;
  double ax; /*Acceleration*/
  double ay;
};

double mag(double x) /*Returns the number but positive*/
{
  if (x > 0)
  {
    return x;
  }
  else
  {
    return -x;
  }
}

int main(int argc, char *argv[])
{

  if (argc == 7) /*If all 6 variables on command line then...*/
  {
    /*Create 3 bodies*/
    struct sBody FixedA;
    struct sBody FixedB;
    struct sBody Third;

    FixedA.x = -1; FixedA.y = 0; FixedA.vx = 0; FixedA.ax = 0;
    FixedB.x = 1; FixedB.y = 0; FixedB.vx = 0; FixedB.ax = 0;

    FixedA.mass = 1.0f;
    FixedB.mass = 1.0f;

    Third.ax = 0; Third.ay = 0;

    /*Open up output file*/
    FILE *output = fopen("stdnum_proj1.out","w");

    /*Read In Command Line Arguments - Convert Strings to float*/
    FixedA.mass = atof(argv[1]);
    FixedB.mass = atof(argv[2]);

    Third.x = atof(argv[3]);
    Third.y = atof(argv[4]);

    Third.vx = atof(argv[5]);
    Third.vy = atof(argv[6]);

    /*Setup Time*/
    double SimTime = 0.0f;
    double TimeStep = 0.005f;

    double DistanceX = 0;
    double DistanceY = 0;
    double DistanceSq = 0;
    double Acceleration = 0;
    double Angle = 0;

    /*Output To File*/
    fprintf(output,"%f %f %f\n", TimeStep, Third.x, Third.y);

    /*Output To Screen*/
    printf("Simulation Time: %f X: %f Y: %f\n",SimTime, Third.x, Third.y);


    int Running = 1;

    while(Running && ((SimTime += TimeStep) < MAX_RUN_TIME)) /*Intill we hit a particle or we run out of time*/
    {

      /*Calucate Acceleration For First Body*/

      /*Get Distances*/
      DistanceX = mag(Third.x - FixedA.x);
      DistanceY = mag(Third.y - FixedA.y);
      DistanceSq = (DistanceX * DistanceX) + (DistanceY * DistanceY);
      Acceleration = FixedA.mass / DistanceSq;

      /*Set Acceleration to 0*/
      Third.ax = 0;
      Third.ay = 0;

      /*Split Acceleration into X & Y*/
      Angle = atan(DistanceY / DistanceX);

      if (Third.x < FixedA.x) /*Set Direction of Acceleration*/
      {
	Third.ax += cos(Angle) * Acceleration;
      }
      else
      {
	Third.ax -= cos(Angle) * Acceleration;
      }

      if (Third.y < FixedA.y)
      {
	Third.ay += sin(Angle) * Acceleration;
      }
      else
      {
	Third.ay -= sin(Angle) * Acceleration;
      }

      /*Calucate Acceleration For Second Body*/

      /*Get Distances*/
      DistanceX = mag(Third.x - FixedB.x);
      DistanceY = mag(Third.y - FixedB.y);
      DistanceSq = (DistanceX * DistanceX) + (DistanceY * DistanceY);
      Acceleration = FixedB.mass / DistanceSq;

      /*Split Acceleration into X & Y*/
      Angle = atan(DistanceY / DistanceX);

      if (Third.x < FixedB.x) /*Set Direction of Acceleration*/
      {
	Third.ax += cos(Angle) * Acceleration;
      }
      else
      {
	Third.ax -= cos(Angle) * Acceleration;
      }

      if (Third.y < FixedB.y)
      {
	Third.ay += sin(Angle) * Acceleration;
      }
      else
      {
	Third.ay -= sin(Angle) * Acceleration;
      }

      /*Calucate Velocity*/
      Third.vx = Third.vx + (Third.ax * TimeStep);
      Third.vy = Third.vy + (Third.ay * TimeStep);

      /*Calucate Change in position*/
      Third.x = Third.x + (Third.vx * TimeStep);
      Third.y = Third.y + (Third.vy * TimeStep);

      /*Output To File*/
      fprintf(output,"%f %f %f\n", TimeStep, Third.x, Third.y);

     /*Output To Screen*/
      printf("Simulation Time: %f X: %f Y: %f\n",SimTime, Third.x, Third.y);

     /*Detect Collision*/
      if (Third.x < FixedA.x + PARTICLE_SIZE && Third.x > FixedA.x - PARTICLE_SIZE && Third.y < FixedA.y + PARTICLE_SIZE && Third.y > FixedA.y - PARTICLE_SIZE)
      {
	printf("Detected Collision with Point A\n");
	Running = 0;
      }

      if (Third.x < FixedB.x + PARTICLE_SIZE && Third.x > FixedB.x - PARTICLE_SIZE && Third.y < FixedB.y + PARTICLE_SIZE && Third.y > FixedB.y - PARTICLE_SIZE)
      {
	printf("Detected Collision with Point B\n");
	Running = 0;
      }
    }

    fclose(output); /*Close File*/

    }
    else
    {
      printf("Please use command line arguments\n Mass_ Mass+ IntialPositionX InitialPositionY VelocityX VelocityY\n");
     return -1;
    }


  return 0;
}


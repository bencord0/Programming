//****************************************
// Project Euler Problem 
// Author - Tom Wilkinson
// Date -
//****************************************


#include <iostream>
#include <cmath>
using namespace std;

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

double pje10()
{
	double max = 2e6;
    double sum, i = 0;
	
	i=3;
	sum=2;

	while(i<=max)
	{
		if(checkprime(i))
		{
			sum += i;
			//cout << "i: " << i <<endl;
			//cout << "Sum: " << sum <<endl;
		}
		i++;
	}
    //cout.precision(15);
    //cout << "Problem 10. Answer: " << sum <<endl;
	
    return sum;

}

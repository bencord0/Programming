//****************************************
// Project Euler Problem 12
// Author - Tom Wilkinson
// Date - 1/6/14
//****************************************

#include <iostream>
#include <cstdlib>
using namespace std;

double pje12()
{
    //initiate variables - one for the triangle number, two counts , one for the number of divisors
    int tri, i, j, divs;
    tri=0;
    j=0;
    i=1;
    divs=0;

    while(divs!=500)
    {
        tri+=i;
        i++;

        divs = 0;
        for(j=2;j<tri+1;j++)
        {
            if( tri % j == 0)
            {
                divs++;
            }
        }

    }
    return tri;
}

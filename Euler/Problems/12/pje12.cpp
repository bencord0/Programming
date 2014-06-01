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
    /** initiate variables:
     * tri: the triangle number
     * i, j: counts
     * divs: number of divisors

    int tri = 0;
    int i = 1;
    int j = 0;
    int divs = 0;

    while (divs < 500) {
        tri += i++;

        divs = 0;
        for(j = 2; j < (tri + 1); j++) {
            if( tri % j == 0) {
                divs++;
            }
        }

    }
    return tri;
}

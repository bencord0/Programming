//****************************************
// Project Euler Problem 9
// Author - Tom Wilkinson
// Date - 24/3/13
//****************************************


#include <iostream>
using namespace std;

double pje9()
{
	int n, a, b, c = 0;
    double ans, sum(0) , ab, c2 =0;
	
	n=5;

	while(sum!=1000)
	{
		
		c = n;
		for(b=0;b<c;b++)
		{
			for (a=0;a<b;a++)
			{
				ab = (a*a)+(b*b);
				c2 = (c*c);
				if(ab == c2){
					sum = a+b+c;
                    //cout << "Sum:" << sum << endl;
					if(sum == 1000)
					{
						ans = a*b*c;
	
                       // cout << "Problem 9. Product of abc=" << ans << endl;
                        return ans;
					}
				}
			}
		}
		n++;
	}
	
    return 0;

}

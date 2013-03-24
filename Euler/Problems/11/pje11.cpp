//****************************************
// Project Euler Problem 11
// Author - Tom Wilkinson
// Date - 24/3/13
//****************************************


#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

double up(int array[20][20])
{
	double u, temp =0;
	int i, j;
	for (i=0;i<20;i++)
	{
		for(j=0;j<17;j++)
		{
			temp = array[i][j] * array[i][j+1] * array[i][j+2] * array[i][j+3];
			if(temp>u){u=temp;}
		}
	}
	cout << "Up: " << u << endl;
	return u;
}

double left(int array[20][20])
{
	double l, temp =0;
	int i, j;
	for (i=0;i<17;i++)
	{
		for(j=0;j<20;j++)
		{
			temp = array[i][j] * array[i+1][j] * array[i+2][j] * array[i+3][j];
			if(temp>l){l=temp;}
		}
	}
	cout << "Left: " << l << endl;
	return l;
}

double diagonalr(int array[20][20])
{
	double dr, temp =0;
	int i, j;
	for (i=0;i<17;i++)
	{
		for(j=0;j<17;j++)
		{
			temp = array[i][j] * array[i+1][j+1] * array[i+2][j+2] * array[i+3][j+3];
			if(temp>dr){dr=temp;}
		}
	}
	cout << "Right diagonal: " << dr << endl;
	return dr;
}

double diagonall(int array[20][20])
{
	double dl, temp =0;
	int i, j;
	for (i=19;i>2;i--)
	{
		for(j=0;j<17;j++)
		{
			temp = array[i][j] * array[i-1][j+1] * array[i-2][j+2] * array[i-3][j+3];
			if(temp>dl){dl=temp;}
		}
	}
	cout << "Left Diagonal: " << dl << endl;
	return dl;
}


int main()
{
	int i, j;
	int arr[20][20];
	double ansarr[6];
	double ans =0;
	//completely unneccesary file i/o to teach myself how
	ifstream file ("pje11.dat", ios::in);
	if (file.is_open())
	{
		for(i=0;i<20;i++)
		{
			for(j=0;j<20;j++)
			{
				file >> arr[i][j];
			}
		}
	file.close();
	}
	else cout << "File error." << endl;
	
	//run greatest of diff directions
	ansarr[0] = up(arr);
	ansarr[1] = left(arr);
	ansarr[2] = diagonalr(arr);
	ansarr[3] = diagonall(arr);
	
	ans = ansarr[0];
	
	for(i=1;i<4;i++)
	{
		if (ansarr[i] > ans)
		{
			ans = ansarr[i];
		}
	}
	cout.precision(15);
	cout<< "Answer: " << ans << endl;
	
	return 0;
}

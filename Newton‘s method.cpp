//newton
#include<bits/stdc++.h>
#define EPSILON 0.001
#include<math.h>
using namespace std;
double func(double x)
{
	return cos(x)-x*exp(x);
}
double derivFunc(double x)
{
	return -sin(x)-exp(x)*(x+1);
}

void newtonRaphson(double x)
{
	double h = func(x) / derivFunc(x);
	while (abs(h) >= EPSILON)
	{
		h = func(x)/derivFunc(x);
		x = x - h;
	}
	cout << "The value of the root is : " << x;
}

int main()
{
	double x0 = 0; 
	newtonRaphson(x0);
	return 0;
}


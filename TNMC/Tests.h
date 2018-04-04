#pragma once
#include <cstdlib>
#include "ToDegree.h"
#include "NOD.h"


bool fermasTest(unsigned int n, int t)
{
	int r, a;
	for (int i = 0; i<t; ++i)
	{
		a = 2 + rand() % (n - 3);
		r = todegreeRL(a, n - 1, n);
		if (r != 1)
		{
			return false;
		}
	}
	return true;
}


int Jacobi(unsigned int a, unsigned int n)
{
	if (a == 0) return 0;
	if (a == 1) return 1;
	
	int k;
	int s = getI(a);
	int r = a >> s;
	//std::cout << a <<"=2^" << s << "*" << r << std::endl;

	if((s&1)==0)
	{
		k = 1;
	}
	else 
		if ( (n&7) == 1 || (n&7) == 7)
		{
			k = 1;
		}
		else
		{
			k = -1;
		}
	if ((r&3) == 3 && (n&3) == 3)
	{
		k = -k;
	}
	if (r == 1)
	{
		return k;
	}
	return k * Jacobi(n%r, r);
}

bool SoloveyShtrass(unsigned int n, int t)
{
	int r, a, s;
	for (int i = 0; i < t; i++)
	{
		a = 2 + rand() % (n - 3);
		r = todegreeRL(a, (n - 1) / 2, n);

		if (r != 1 && r != n-1)
		{
			return false;
		}

		s = Jacobi(a,n);
		//std::cout << "Jacobi("<<a<<","<<n<<")="<< s << std::endl;
		//std::cout << "MOD=" << s%n << std::endl;

		if (s == -1)
		{
			s = n - 1;
		}

		if (r != s)
		{
			return false;
		}
	}
	return true;
}

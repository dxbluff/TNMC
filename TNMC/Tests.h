#pragma once
#include <cstdlib>
#include "ToDegree.h"
#include "NOD.h"
#include <map>

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

int Jacobi(unsigned int a, unsigned int n)      //secondary function
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

bool MullerRabbinTest(unsigned int n, int t)
{
	int s, r, a, b, j;
	s = getI(n-1);
	r = n >> s;
	for(int i=0; i<t; i++)
	{
		a = 2 + rand() % (n - 3);
		b = todegreeLR(a, r, n);
		if (b != 1 && b != n - 1)
		{
			j = 1;
			while (j < s && b != n - 1)
			{
				b = (b*b) % n;
				if (b == 1) 
					return false;
				j++;
			}
			if (b != n - 1)
				return false;
		}
	}
	return true;
}


void kanon(int n, std::map<int, int> &kan)   //secondary function
{
	int s = getI(n);
	if (s > 0)
	{
		kan[2] = s;
		n = n >> s;
	}
	int div = 3;

	while (n > 1)
	{
		while (n % div == 0)
		{
			kan[div]++;
			//std::cout << " * " << div;
			n = n / div;
		}
		div+=2;
	}

	std::cout << "RAZLOZHENIE:\n 1";
	for (auto it : kan)
	{
		for (int i = 0; i < it.second; i++)
			std::cout << " * "  << it.first;
	}
	std::cout << std::endl;
}


bool LuksMethod(unsigned int n, int t)
{
	std::map<int, int> razlozhenie;
	kanon(n - 1, razlozhenie);
	
	int r, a;

	for (int i = 0; i < t; i++)
	{
		bool flag = true;
		a = 2 + rand() % (n - 3);
		std::cout << "i=" << i << " a=" << a << std::endl;
		r = todegreeLR(a, n-1, n);
		if (r != 1)
		{
			return false;
		}

		int deg;

		for (auto it : razlozhenie)
		{
			deg = (n - 1) / (it.first);
			if (todegreeLR(a, deg, n) == 1)
			{
				/*std::cout << todegreeLR(a, deg, n) << std::endl;
				std::cout << a << " 18/" << it.first << " " << deg << std::endl;*/
				flag = false;
				break;
			}
		}
		if (flag == true) return true;
	}
	return false;
}
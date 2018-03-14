#pragma once

int nlz(unsigned int x)    //SECONDARY FUNCTION
{
	int n = 0;
	if ((x >> 16) == 0)
	{
		n += 16;
		x <<= 16;
	}
	if ((x >> 24) == 0)
	{
		n += 8;
		x <<= 8;
	}
	if ((x >> 28) == 0)
	{
		n += 4;
		x <<= 4;
	}
	if ((x >> 30) == 0)
	{
		n += 2;
		x <<= 2;
	}
	if ((x >> 31) == 0)
	{
		n++;
	}
	return n;
}

unsigned long long int todegreeRL(unsigned int x, unsigned int y, unsigned int m)
{
	unsigned long long int q(x);
	unsigned long long int  z;
	if (y & 1)
		z = x;
	else
		z = 1;
	while (y >>= 1)
	{
		q = (q*q) % m;
		if (y & 1) z = (z*q) % m;
	}
	return z;
}

unsigned long long int  todegreeLR(unsigned int x, unsigned int y, unsigned int m)
{
	unsigned long long int z(x);
	int size = sizeof(y) * 8;
	for (int i = size - nlz(y) - 2; i >= 0; i--)
	{
		z = (z*z) % m;
		if (y&(1 << i))
		{
			z = (z*x) % m;
		}
	}
	return z;
}
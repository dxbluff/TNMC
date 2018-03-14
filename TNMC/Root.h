#pragma once


int root(unsigned int a)
{
	unsigned int a0 = a - 1;
	unsigned int a1;
	do {
		a1 = a0;
		a0 = ((a / a0) + a0) >> 1;
	} while (a0<a1);
	return a1;
}

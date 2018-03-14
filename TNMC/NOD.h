#pragma once

int getI(int a)    //SECONDARY FUNCTION
{
	int i;
	for (i = 0; !((a >> i) & 1); i++);
	return i;
}

int NOD(unsigned int a, unsigned int b)
{
	unsigned int i = getI(a);
	unsigned int j = getI(b);
	unsigned int a1 = a >> i;
	unsigned int b1 = b >> j;
	unsigned int c;
	int k = i<j ? i : j;

	while (a1 != b1)
	{
		if (a1<b1)
		{
			int tmp = a1;
			a1 = b1;
			b1 = tmp;
		}
		c = a1 - b1;
		a1 = c >> getI(c);
	}
	return a1 << k;
}
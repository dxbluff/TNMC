#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

unsigned int NOD(unsigned int a, unsigned int b)
{
	while(a!=b)
	{
		if(a<b)
		{
			a+=b;
			b=a-b;
			a=a-b;
		}
		a-=b;
	}
	return b;
}


int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	srand(time(NULL));
	for(int i=0; i<100; i++)
	{	
		int a=rand()%99+1;
		int b=rand()%999+1;
		cout<<NOD(a,b)<<endl;
		cout<<gcd(a,b)<<endl<<endl;
		if(NOD(a,b)!=gcd(a,b))
		{
			cout<<"error!!!!!"<<endl;
		}
	}
}



#include <iostream>
#include "GenOdd.h"
#include "ToDegree.h"

using namespace std;



int main()
{
	srand(time(NULL));
	for(int i = 4; i<33; i++)
	cout << GenPrime(i) << endl;

	//std::cout << Jacobi(8, 5) << std::endl;
	cin.get();
	return 0;
}


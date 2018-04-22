#include <iostream>
#include "GenOdd.h"
#include "ToDegree.h"


using namespace std;

int main()
{
	srand(time(NULL));

	std::cout << LuksMethod(19, 5)<<std::endl;

	/*for (int i = 4; i < 33; i++)
		std::cout << GenPrime(i) << std::endl;*/
	cin.get();
	return 0;
}


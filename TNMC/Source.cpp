#include <iostream>
#include "GenOdd.h"
#include "ToDegree.h"

using namespace std;



int main()
{
	srand(time(NULL));
	cout << Gen(10) << endl;
	cin.get();
	return 0;
}


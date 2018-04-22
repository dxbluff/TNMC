#pragma once
#include <bitset>
#include <cstdlib>
#include <time.h>
#include "Tests.h"

unsigned int GenPrime(int k)
{
	unsigned int random;
	do
	{
		random = rand();
		unsigned int tmp = rand();
		random = random | (tmp << 15);
		random = random | 1;
		random = random | (1 << k - 1);
		random = (random << (32 - k)) >> (32 - k);
	} 
	//while (!SoloveyShtrass(random, 5));	
	while (!LuksMethod(random, 5));
	return random;
}


//GENODD
unsigned int GenOdd(int k) 
{
	unsigned int random;
	random = rand();
	unsigned int tmp = rand();    //for get first 16 random bits
								  //std::cout << random << std::endl << std::bitset<32>(random) << std::endl;
	random = random | (tmp << 15);
	random = random | 1;
	//std::cout << std::bitset<32>(random) << std::endl;
	random = random | (1 << k - 1);
	//std::cout << std::bitset<32>(random) << std::endl;
	random = (random << (32 - k)) >> (32 - k);
	//std::cout << std::bitset<32>(random) << std::endl;
	return random;
}

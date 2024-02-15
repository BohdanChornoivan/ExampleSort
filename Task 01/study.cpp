#include <iostream>

unsigned int GetSeedRandom()
{
	return static_cast<unsigned>(std::time(nullptr));
}

void SetRandomSeed(unsigned seed = GetSeedRandom())
{
	std::srand(seed);
}

int GetRandomNumRange(int min, int max)
{
	return std::rand() % (max - min) + 1 + min;
}
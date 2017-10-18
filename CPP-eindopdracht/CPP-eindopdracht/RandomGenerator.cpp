#include "RandomGenerator.h"

RandomGenerator::RandomGenerator()
{
	generator = new default_random_engine();
	generator->seed(time(0));
}

RandomGenerator::~RandomGenerator()
{
	delete generator;
}

int RandomGenerator::GetRandomNumber(int low, int high) const
{
	uniform_int_distribution<int> distribution(low, high);
	return distribution(*generator);
}

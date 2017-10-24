#include "RandomGenerator.h"

RandomGenerator::RandomGenerator()
{
	generator = new std::default_random_engine();
	generator->seed(time(0));
}

RandomGenerator::~RandomGenerator()
{
	delete generator;
}

int RandomGenerator::GetRandomNumber(int low, int high) const
{
	std::uniform_int_distribution<int> distribution(low, high);
	return distribution(*generator);
}

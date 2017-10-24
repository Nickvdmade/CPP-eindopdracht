#pragma once

#include <random>
#include <ctime>

class RandomGenerator
{
private:
	std::default_random_engine* generator;

public:
	RandomGenerator();
	~RandomGenerator();
	int GetRandomNumber(int, int) const;
};

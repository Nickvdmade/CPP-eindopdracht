#pragma once

#include <random>
#include <ctime>

using namespace std;

class RandomGenerator
{
private:
	default_random_engine* generator;

public:
	RandomGenerator();
	~RandomGenerator();
	int GetRandomNumber(int, int) const;
};

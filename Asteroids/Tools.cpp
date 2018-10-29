#include "Tools.h"



Tools::Tools()
{
}


Tools::~Tools()
{
}
float Tools::generateRandomFloat(float minRange, float maxRange)
{
	std::random_device mRandomDev;
	std::mt19937 mRandom(mRandomDev());
	std::uniform_real_distribution<float> randomInt(minRange, maxRange);
	return randomInt(mRandom);
}
int Tools::generateRandomInt(int minRange, float maxRange){
	std::random_device mRandomDev;
	std::mt19937 mRandom = std::mt19937(mRandomDev());
	std::uniform_int_distribution<int> randomInt(minRange, maxRange);
	return randomInt(mRandom);
}


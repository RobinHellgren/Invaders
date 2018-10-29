#pragma once
#include "Random"
class Tools
{
public:
	Tools();
	~Tools();
	static float generateRandomFloat(float minRange, float maxRange);
	static int generateRandomInt(int minRange, float maxRange);
};


#include "Iterator.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

Iterator::Iterator(const double min, const double max, const double step) :
	min(min),
	max(max),
	step(step)
{
}

double Iterator::GetNextValue(double value)
{
	value += step;

	if (value > max)
	{
		value = max;
		step = -step;
	}

	if (value < min)
	{
		value = min;
		step = -step;
	}

	return value;
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
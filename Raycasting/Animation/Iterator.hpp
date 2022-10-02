#ifndef ITERATOR_H
#define ITERATOR_H

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

class Iterator
{
public:
	Iterator(const double min, const double max, const double step);

	Iterator(const Iterator&) = delete;

	~Iterator() = default;

	Iterator& operator = (const Iterator&) = delete;

	double GetNextValue(double value);

private:
	const double min;
	const double max;
	double step;
};

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

#endif // !ITERATOR_H
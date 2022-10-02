#include <stdio.h>
#include <math.h>

#include "DoubleMath.hpp"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

// Учитываем только 14 первых значимых цифр. 
// При этом сравниваем 15 значимую цифру. Double гарантирует, что число содержит не менее 15 значимых цифр.
static const double epsilon = 1.0e-15;

inline bool DoubleEqual(double left, double right)
{
	return fabs(right - left) < epsilon;
}

struct DoubleEqualTest_t
{
	double Number1;
	double Number2;
	bool   Answer;
};

void DoubleEqualTest()
{
	DoubleEqualTest_t tests[] = 
	{
		{1e-14  , 1e-14  , true },
		{1.1e-14, 1.2e-14, true },
		{1.1e-14, 1.9e-14, false},
		{0.9e-14, 1.9e-14, false},
		{1.9e-14, 2.0e-14, true },
		{1e-21  , 1e-20  , true },

		{0.12345678901234, 0.12345678901234, true},
		{0.12345678901235, 0.12345678901234, false},
		{0.12345678901234, 0.12345678901235, false},

		{12345678901234, 12345678901234, true},
		{12345678901235, 12345678901234, false},
		{12345678901234, 12345678901235, false},

		{123456789012340001, 123456789012340001, true},
		{123456789012350001, 123456789012340001, false},
		{123456789012340001, 123456789012350001, false},
	};

	size_t count = sizeof(tests) / sizeof(tests[0]);

	puts(" N: DoubleEqual RightAnswer");
	for (size_t st = 0; st < count; st++)
	{
		bool equal = DoubleEqual(tests[st].Number1, tests[st].Number2);

		printf("%2zd  %11s %11s\n", st, equal ? "true" : "false", tests[st].Answer ? "true" : "false");
	}
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
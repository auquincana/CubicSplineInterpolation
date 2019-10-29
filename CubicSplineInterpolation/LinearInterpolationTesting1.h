// LinearInterpolation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>   

#include "LinearInterpolation.h"

using namespace std;

void LinearInterpolationTesting()
{
	size_t n = 5;
	pair<vector<double>, vector<double>> points(n, n);

	iota(begin(points.first), end(points.first), 0);
	transform(begin(points.first), end(points.first), begin(points.second),
		[](auto element) {return exp(element); });

	LinearInterpolation linealInt(points);

	auto h = 0.5;
	auto accum = 0.0;
	while (accum  <= points.first.back())
	{
		accum += h;
		std::cout << accum << '\t';
		std::cout << linealInt(accum) << '\t';
		std::cout << '\n';
	}
}

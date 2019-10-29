// CubicSplineInterpolation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>   

#include "ClampedSpline.h"
#include "NaturalSpline.h"

using namespace std;

void CubicSplineInterpolationTesting()
{
	size_t n = 4;
	pair<vector<double>, vector<double>> points(n, n);

	iota(begin(points.first), end(points.first), 0);
	transform(begin(points.first), end(points.first), begin(points.second),
		[](auto element) {return exp(element); });

	ClampedSpline exponetialClamped(points);
	NaturalSpline exponetialNatural(points);

	auto h = 0.5;
	auto accum = 0.0;
	while (accum  <= points.first.back())
	{
		accum += h;
		std::cout << accum << '\t';
		std::cout << exponetialClamped(accum) << '\t';;
		std::cout << exponetialNatural(accum);
		std::cout << '\n';
	}
}

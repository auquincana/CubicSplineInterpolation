#pragma once
#include "Interpolation.h"

using namespace detail;

class LinearInterpolation :
	public Interpolation
{
public:
	LinearInterpolation() = delete;

	/*! \fn
	* Constructor.
	* @param nodes (pair<vector<double>, vector<double>> const &) nodes especified de data points
	*/
	LinearInterpolation(pair<vector<double>, vector<double>> const &nodes);

	/*! \fn
	* Overload Function Call () Operator.
	* @param t (double) value to interpolate.
	* @return f(t)b(double) value the linear interpolation in t.
	*/
	double operator()(double t) const;

	virtual ~LinearInterpolation();

protected:

	/*! \fn
	* Construct the coefficients of Spline.
	* @param x (vector<double> const & ) x - coordinates of points.
	* @param y (vector<double> const & ) y - coordinates of points.
	*/
	void constructCoefficients(vector<double> const & x, vector<double> const & y);

private:
	size_t const n;
	vector <double> x;
	vector <double> y;
	solution coefficients;
};


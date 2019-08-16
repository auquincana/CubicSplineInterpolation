#include "CubicSpline.h"
#include "QCIndexTemplates.h"


CubicSpline::CubicSpline(pair<vector<double>, vector<double>> const & nodes) : n(nodes.first.size() - 1), x(nodes.first)
{
}


CubicSpline::~CubicSpline()
{
}

double CubicSpline::operator()(double t) const
{
	// fin the index for interpolation
	auto it = lower_bound_custom(begin(x), end(x), t);
	double splineResult(0.0);

	if (it != end(x))
	{
		auto j = it - begin(x);
		auto tAux = t - *it;

		splineResult = coefficients.a[j] + coefficients.b[j] * tAux + coefficients.c[j] * tAux * tAux + coefficients.d[j] * tAux * tAux  * tAux;
	}
		return splineResult;
}

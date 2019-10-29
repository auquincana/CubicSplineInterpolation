#include "LinearInterpolation.h"
#include "QCIndexTemplatesNew.h"



LinearInterpolation::LinearInterpolation(pair<vector<double>, vector<double>> const &nodes) :
	n(nodes.first.size() - 1), x(nodes.first)
{
	constructCoefficients(nodes.first, nodes.second);
}


LinearInterpolation::~LinearInterpolation()
{
}

double LinearInterpolation::operator()(double t) const
{
	// fin the index for interpolation
	auto it = lower_bound_custom(begin(x), end(x), t);
	double linearResult(0.0);
	
	if (it != end(x))
	{
		auto j = it - begin(x);
		auto tAux = t - *it;
		auto slope = coefficients.b[j];

		linearResult = slope * tAux  + coefficients.a[j];
	}
	
	return linearResult;
}

void LinearInterpolation::constructCoefficients(vector<double> const & x, vector<double> const & y)
{
	// Container solutions
	coefficients.a.resize(n + 1);
	coefficients.b.resize(n + 1);
	coefficients.c.resize(n + 1);

	for (size_t i = 0; i < n; i++) {
		coefficients.c.at(i) = x[i + 1] - x[i];
		coefficients.b.at(i) = (y[i + 1] - y[i]) / coefficients.c[i];
		coefficients.a.at(i) = y[i];
	}

	// La ultima pendiente queda en cero.
	coefficients.a.at(n) = y[n];
}
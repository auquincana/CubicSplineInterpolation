#include "NaturalSpline.h"
#include "QCIndexTemplates.h"


NaturalSpline::NaturalSpline(pair<vector<double>, vector<double>> const & nodes): CubicSpline(nodes)
{
	// costruct natural spline coefficients
	NaturalSpline::constructSpline(x, nodes.second);
}

/*
Constuct Clamped Spline Interpolation
Burden Numerical Analysis
Algorithm 3.4, pag 149
*/
void NaturalSpline::constructSpline(vector<double> const & x, vector<double> const & y)
{
	// Asign dimentios to vector's
	vector <double> h(n), l(n + 1), u(n + 1);
	vector <double> alpha(n + 1), z(n + 1);
	
	// Container solutions
	coefficients.a.resize(n + 1),
	coefficients.b.resize(n + 1),
	coefficients.c.resize(n + 1),
	coefficients.d.resize(n + 1);

	for (size_t i = 0; i < n; i++)
		h.at(i) = x[i + 1] - x[i];

	for (size_t i = 1; i < n; i++)
		alpha.at(i) = ((y[i + 1] - y[i])) * (3.0 / h.at(i)) - ((y[i] - y[i - 1])) * (3.0 / h.at(i - 1));

	l.at(0) = 1;
	u.at(0) = 0;
	z.at(0) = 0;

	for (size_t i = 1; i < n; i++)
	{
		l.at(i) = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * u[i - 1];
		u.at(i) = h[i] / l[i];
		z.at(i) = (alpha[i] - z[i - 1] * h[i - 1]) / l[i];
	}

	l.at(n) = 1;
	z.at(n) = 0;
	coefficients.c.at(n) = 0;

	auto i = n;
	for (size_t j = 1; j < (n + 1); j++)
	{
		i = n - j;
		coefficients.c.at(i) = z[i] - coefficients.c[i + 1] * u[i]; 
		coefficients.b.at(i) = (y[i + 1] - y[i]) / h[i] - ((coefficients.c[i + 1] + coefficients.c[i] * 2) * h[i]) / 3;
		coefficients.d.at(i) = (coefficients.c[i + 1] - coefficients.c[i]) / (3 * h[i]);
		coefficients.a.at(i) = y[i];
	}

	coefficients.b.at(n) = coefficients.d.at(n) = 0;
	coefficients.a.at(n) = y[n];

}

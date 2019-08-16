#include "ClampedSpline.h"

ClampedSpline::ClampedSpline(pair<vector<double>, vector<double>> const & nodes): CubicSpline(nodes)
{
	vector <double> y(nodes.second);

	// boundary conditions: Linear aproximation
	fp0 = (y[1] - y[0]) / (x[1] - x[0]);
	fpn = (y[n] - y[n - 1]) / (x[n] - x[n - 1]);

	// costruct spline aproximation
	ClampedSpline::constructSpline(x, y);
}

/*
Constuct Clamped Spline Interpolation
Burden Numerical Analysis
Algorithm 3.5, pag 155
*/
void ClampedSpline::constructSpline(vector<double> const & x, vector<double> const & y)
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

	alpha.at(0) = ((y[1] - y[0]) * 3) / h[0] - fp0 * 3;
	alpha.at(n) = fpn * 3 - ((y[n] - y[n - 1]) * 3) / h[n - 1];

	for (size_t i = 1; i < n; i++)
		alpha.at(i) = ((y[i + 1] - y[i])) * (3.0 / h.at(i)) - ((y[i] - y[i - 1])) * (3.0 / h.at(i - 1));

	l.at(0) = 2 * h[0];
	u.at(0) = 0.5;
	z.at(0) = alpha[0] / l[0];

	for (size_t i = 1; i < n; i++)
	{
		l.at(i) = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * u[i - 1];
		u.at(i) = h[i] / l[i];
		z.at(i) = (alpha[i] - z[i - 1] * h[i - 1]) / l[i];
	}

	l.at(n) = h[n - 1] * (2 - u[n - 1]);
	z.at(n) = (alpha[n] - z[n - 1] * h[n - 1]) / l[n];
	coefficients.c.at(n) = z[n];

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


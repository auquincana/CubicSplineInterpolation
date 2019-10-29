#pragma once
#include <vector>
#include "Interpolation.h"

using namespace std;

enum class BoundaryConditions { Natural, Clamped };

/*!
\class        CubicSpline class.h "include/CubicSpline.h"
*  \brief     Cubic Spline data Interpolantion.
*  \details   Cubic Spline Interpolantion generate the polynomial of grade 3 coefficients for the
              data points{(x0, y0),(x1, y1),...,(xn,yn)}.
*
*  \author    Maria Solange Becerra
*  \version   0.2a
*  \date      2019/08
*  \pre
*  \bug
*  \warning
*
*  \copyright Maria Solange Becerra
*/

using namespace detail;

class CubicSpline :public Interpolation
{
public:

	CubicSpline() = delete;

	/*! \fn
    * Constructor.
    * @param nodes (pair<vector<double>, vector<double>> const &) nodes especified de data points 
    */
	CubicSpline(pair<vector<double>, vector<double>> const &nodes);

	/*! \fn
	* Overload Function Call () Operator.
	* @param t (double) value to interpolate.
	* @return f(t)b(double) value the spline in t.
	*/
	double operator()(double t) const;

	/*! \fn
    * Destructor.
    */
	virtual ~CubicSpline();

protected:

	/*! \fn
	* Construct the coefficients of Spline.
	* @param x (vector<double> const & ) x - coordinates of points.
	* @param y (vector<double> const & ) y - coordinates of points.
	*/
	virtual void constructSpline(vector<double> const & x, vector<double> const & y) = 0;

	size_t const n;
	vector <double> x;
	solution coefficients;
};


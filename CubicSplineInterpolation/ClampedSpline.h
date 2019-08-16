/*!
\class        ClampedSpline class.h "include/ClampedSpline.h"
*  \brief     Clamped Spline data Interpolantion.
*  \details   Generate the polynomial of grade 3 coefficients for the
			  data points{(x0, y0),(x1, y1),...,(xn,yn)} using clamped boundary.
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

#pragma once
#include <vector>
#include "CubicSpline.h"

using namespace std;


class ClampedSpline :public CubicSpline
{
public:
	ClampedSpline() = delete;
	/*! \fn
	* Constructor.
	* @param nodes (pair<vector<double>, vector<double>> const &) nodes especified de data points
	*/
	ClampedSpline(pair<vector<double>, vector<double>> const &nodes);

	~ClampedSpline() = default;

protected:
	/*! \fn
	* Construct the coefficients of Spline.
	* @param x (vector<double> const & ) x - coordinates of points.
	* @param y (vector<double> const & ) y - coordinates of points.
	*/
	void constructSpline(vector<double> const & x, vector<double> const & y);

private:

	double fp0 = 0.0;
	double fpn = 0.0;
};




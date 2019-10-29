#pragma once
#include <vector>

using namespace std;

namespace detail {

	enum class interpolationsMethods { Linear, Cubic, LogLinear };;

	struct solution
	{
		vector<double> a;
		vector<double> b;
		vector<double> c;
		vector<double> d;
	};
}


/*!
\class        Interpolation class.h "include/Interpolation.h"
*  \brief     Base clase for Interpolantion methods.
*  \details   Interpolation for the data points {(x0, y0),(x1, y1),...,(xn,yn)}.
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

class Interpolation
{
public:

	Interpolation() = default;

	/*! \fn
	* Overload Function Call () Operator.
	* @param t (double) value to interpolate.
	* @return f(t)b(double) value the interpolation method in t.
	*/
	virtual double operator()(double t) const = 0;

	/*! \fn
    * Destructor.
    */
	virtual ~Interpolation() {};

protected:
};


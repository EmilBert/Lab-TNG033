/*********************************************************
* Class Expression member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "expression.h"



// Displays Expression
std::ostream & operator<<(std::ostream & os, const Expression & E)
{
    E.display(os);
    return os;
}

// Returns true if absolute value is less than EPSILON
bool Expression::isRoot(double x) const
{
    return (std::abs(getValue(x)) < EPSILON);
}

double Expression::operator()(double d) const
{
    return getValue(d);
}

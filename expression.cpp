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
    return (std::abs((*this)(x)) < EPSILON);
}

/*
// calculate value of Expression with doubl value x
double Expression::operator()(double d) const
{
    return getValue(d);
}
 */

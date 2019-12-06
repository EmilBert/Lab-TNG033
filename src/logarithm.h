/*************************
* Class Logarithm        *
* TNG033: Lab 2          *
**************************/


#ifndef LOGARITHM_H
#define LOGARITHM_H

#include <iostream>
#include "expression.h"

class Logarithm : public Expression
{
public:
    // Constructor
    Logarithm();
    Logarithm(const Expression& E, const double c1, const double c2, const int b);
    Logarithm(const Logarithm& L);
    ~Logarithm();

    Logarithm* copy() const override;
    //double getValue(const double x) const override;
    std::ostream& display(std::ostream& os) const override;
    Logarithm& operator=(const Logarithm& L);
    double operator()(double d) const override;
    
protected:
    int base;
    double p;
    double q;
    Expression* LogArg;
};

#endif

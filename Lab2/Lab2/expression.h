/*************************
* Class Expression       *
* TNG033: Lab 2          *
**************************/

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <cmath>

const double EPSILON = 1.0e-5;


class Expression
{
    
public:
    // Constructors and virtual destructors!
    virtual ~Expression(){};
    bool isRoot(double x) const;
    double operator()(double d) const;
    friend std::ostream& operator<<(std::ostream& os, const Expression& E);
    virtual Expression* copy() const = 0;
    virtual std::ostream& display(std::ostream& os) const = 0;
    void operator=(const Expression& E) = delete;
    virtual double getValue(double x) const= 0;
    
protected:
    
};


#endif

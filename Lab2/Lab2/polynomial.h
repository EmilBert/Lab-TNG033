/*************************
* Class Polynomial       *
* TNG033: Lab 2          *
**************************/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <cmath>

#include "expression.h"

class Polynomial : public Expression
{
public:
    // Constructors
    Polynomial();
    Polynomial(int n, const double a[]); //constructor
    Polynomial(const double n); // convert constructor
    Polynomial(const Polynomial& c); // copy constructor
    
    // Destructor
    ~Polynomial();

    // Operator overloading
    Polynomial& operator=(const Polynomial& c);
    friend Polynomial operator+(const Polynomial& lh, const Polynomial& rh);
    Polynomial operator+(const double x);
    double& operator[](const int x);
    double operator[](const int x) const;
    

    // Virtual methods to override
    Polynomial* copy() const override;
    double getValue(double x) const override;
    std::ostream& display(std::ostream& os) const override;
    
protected:
    int degree;
    double* poly;
    
private:

};


#endif

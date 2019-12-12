/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "polynomial.h"


//ADD implementation of the member functions for class Polynomial

Polynomial::Polynomial()
{
}

//constr
Polynomial::Polynomial(const int n, const double a[])
{
    poly = new double[n+1];
    degree = n;

    for (int i = 0; i < degree + 1; i++) {
        poly[i] = a[i];
    }
}

// convert constr.
Polynomial::Polynomial(const double n)
{
    degree = 0;
    //first slot is a constant
    poly = new double[1]{n};
}

//copy constr.
Polynomial::Polynomial(const Polynomial& c)
{
    degree = c.degree;
    poly = new double[degree+1];
    
    //copy polynom to new polynom array
    for (int i = 0; i < degree + 1; i++) {
        poly[i] = c.poly[i];
    }
}

Polynomial::~Polynomial()
{
    delete[] poly;
   
}

Polynomial* Polynomial::copy() const
{
    return new Polynomial{ *this };
}

double Polynomial::getValue(double x) const
{
    double current_value = 0;

    for (int i = 0; i < degree + 1; i++) {
        current_value += poly[i] * pow(x, i);
    }

    return current_value;
}

std::ostream & Polynomial::display(std::ostream& os) const
{
    // TODO: insert return statement here
    for (int i = 0; i < degree + 1; i++) {
        if (i == 0) {
            os << poly[i];
        }
        else {
            os << " + " << poly[i] << "x^" << i;
        }
    }
    return os;
}

        
Polynomial& Polynomial::operator=(const Polynomial& c)
{
    if (this != &c) {
        // Deallocate old memory
        delete[] poly;

        //*this = Polynomial(c);
        poly = new double[c.degree + 1];

        this->degree = c.degree;
        for (int i = 0; i < this->degree + 1; i++) {
            this->poly[i] = c.poly[i];
        }
    }

    return *this;
}

double& Polynomial::operator[](const int x)
{
    return this->poly[x];
}
double Polynomial::operator[](const int x) const
{
    return this->poly[x];
}

Polynomial Polynomial::operator+(const double x)
{
    Polynomial newPoly( *this);
    newPoly.poly[0] += x;
    delete[] poly;
    return newPoly;
}

Polynomial operator+(const Polynomial & lh, const Polynomial & rh)
{
    // 1. Find the longer poly
    const Polynomial* longerPoly = (lh.degree > rh.degree) ? &lh : &rh;
    const Polynomial* shorterPoly = (lh.degree > rh.degree) ? &rh : &lh;

    // Make a new poly that is a copy of the longer poly
    Polynomial newPoly{ *longerPoly };
    
    for(int i = 0; i < shorterPoly->degree+1; i++){
        newPoly.poly[i] += shorterPoly->poly[i];
    }
    
    
    
    return newPoly;

}

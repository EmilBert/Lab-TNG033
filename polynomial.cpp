/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "polynomial.h"

//Default constructor
Polynomial::Polynomial(){}

//Constructor
Polynomial::Polynomial(const int n, const double a[])
{
    poly = new double[n+1];
    degree = n;

    for (int i = 0; i < degree + 1; i++) {
        poly[i] = a[i];
    }
}

//Constructor with a single double value
Polynomial::Polynomial(const double n)
{
    degree = 0;
    //first slot is a constant
    poly = new double[1]{n};
}

//Copy constructor
Polynomial::Polynomial(const Polynomial& c)
{
    degree = c.degree;
    poly = new double[degree+1];
    
    //copy polynom to new polynom array
    for (int i = 0; i < degree + 1; i++) {
        poly[i] = c.poly[i];
    }
}

//Destructor
Polynomial::~Polynomial()
{
    delete[] poly;
}

//Creates copy of Polynomial
Polynomial* Polynomial::copy() const
{
    return new Polynomial{ *this };
}

/*
//Returns value of polynomial with double value x
double Polynomial::getValue(double x) const
{
    double current_value = 0;

    for (int i = 0; i < degree + 1; i++) {
        current_value += poly[i] * pow(x, i);
    }

    return current_value;
}
 */

//Displays the polynomial
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

//Assignement operator
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

//Gets value of poly[x] by reference
double& Polynomial::operator[](const int x)
{
    return this->poly[x];
}

//Gets value of poly[x] by reference
double Polynomial::operator[](const int x) const
{
    return this->poly[x];
}

//Addition operator for adding a const double x to the constant value
Polynomial Polynomial::operator+(const double x)
{
    Polynomial newPoly( *this);
    newPoly.poly[0] += x;
    delete[] poly;
    return newPoly;
}

double Polynomial::operator()(double d) const { 
    double current_value = 0;

  for (int i = 0; i < degree + 1; i++) {
      current_value += poly[i] * pow(d, i);
  }

  return current_value;
}


//Addition operator for 2 polynomials
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

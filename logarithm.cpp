/*********************************************************
* Class Logarithm member functions implementation        *
* TNG033: Lab 2                                          *
**********************************************************/

#include "logarithm.h"
#include "polynomial.h"

//Default constructor
Logarithm::Logarithm(){
    base=2;
    double x[]={0,1};
    LogArg = new Polynomial(1,x);
    p = 0;
    q = 1;
}

//Constructor
Logarithm::Logarithm(const Expression& E, const double c1, const double c2, const int b){
    base=b;
    p = c1;
    q = c2;
    LogArg= E.copy();
}

//Copy Constructor
Logarithm::Logarithm(const Logarithm& L){
    
    base = L.base;
    p = L.p;
    q = L.q;
    LogArg = L.LogArg->copy();
}

//Destructor
Logarithm::~Logarithm(){
    delete LogArg;
    LogArg = nullptr;
}

//Clones an existing Logarithm
Logarithm* Logarithm::copy() const {
    return new Logarithm(*this);
}

/*
//Solves logarithm width double value x
double Logarithm::getValue(const double x) const {
    return (p + q*(log(LogArg->getValue(x))/log(base)));
}
*/

//Displays a logarithm
std::ostream& Logarithm::display(std::ostream& os) const {
    
    os << p <<" + "<< q << "log_" << base << "(" << *LogArg << ")";
    
    return os;
}

//Assignment operator
Logarithm& Logarithm::operator=(const Logarithm& L){
    
    if(this != &L){
        base = L.base;
        p = L.p;
        q = L.q;
        LogArg = L.LogArg->copy();
    }
    return *this;
}

double Logarithm::operator()(double d) const {
    double exprValue = LogArg->operator()(d);
    return (p + q*(log(exprValue)/log(base)));
}

/*********************************************************
* Class Logarithm member functions implementation        *
* TNG033: Lab 2                                          *
**********************************************************/

#include "logarithm.h"
#include "polynomial.h"

//ADD implementation of the member functions for class Logarithm

Logarithm::Logarithm(){
    base=2;
    double x[]={0,1};
    LogArg = new Polynomial(1,x);
    p = 0;
    q = 1;
}
Logarithm::Logarithm(const Expression& E, const double c1, const double c2, const int b){
    base=b;
    p = c1;
    q = c2;
    LogArg= E.copy();
}
Logarithm::Logarithm(const Logarithm& L){
    
    base = L.base;
    p = L.p;
    q = L.q;
    LogArg = L.LogArg->copy();
}

Logarithm::~Logarithm(){
    delete LogArg;
    LogArg = nullptr;
}

Logarithm* Logarithm::copy() const {
    return new Logarithm(*this);
}
double Logarithm::getValue(const double x) const {
    return (p + q*(log(LogArg->getValue(x))/log(base)));
}
std::ostream& Logarithm::display(std::ostream& os) const {
    
    os << p <<" + "<< q << "log_" << base << "(" << *LogArg << ")";
    
    return os;
}
Logarithm& Logarithm::operator=(const Logarithm& L){
    
    if(this != &L){
        base = L.base;
        p = L.p;
        q = L.q;
        LogArg = L.LogArg->copy();
    }
    return *this;
}

#include<iostream>
#include<list>

using namespace std;

struct Monomial{
    int coefficient;
    int power;
};


class Polynomial{
private:
    list<Monomial> l;

public:
    void print()const;
    void add_monomial(const Monomial&);
    Polynomial operator+(const Polynomial&) const;
};

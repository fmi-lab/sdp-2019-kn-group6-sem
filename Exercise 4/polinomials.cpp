#include "polinomials.h"

void Polynomial::print()const{
    typename list<Monomial>::const_iterator it = l.begin();
    for(;it != l.end(); it++){
        if(it->coefficient > 0){
            cout<<" +";
        } else{
            cout<<' ';
        }
        cout<<it->coefficient<<"*x^"<<it->power;
    }
    cout<<endl;
}

void Polynomial::add_monomial(const Monomial& mono){
    if(mono.coefficient == 0){
        return;
    }
    typename list<Monomial>::iterator it = l.begin();
    for(;it->power < mono.power; it++);
    if(it->power == mono.power){
        it->coefficient += mono.coefficient;
        if(it->coefficient == 0){
            l.erase(it);
        }
    } else {
        l.insert(it, mono);
    }
}

Polynomial Polynomial::operator+(const Polynomial& other) const{
    Polynomial result = *this;
    typename list<Monomial>::const_iterator it = other.l.begin();
    for(; it != other.l.end(); it++){
        result.add_monomial(*it);
    }
    return result;
}



int main(){
    Polynomial p1, p2;

    Monomial m1, m2, m3, m4, m5, m6, m7, m8;

    m1.coefficient = 5;
    m1.power = 1;

    m2.coefficient = 0;
    m2.power = 2;

    m3.coefficient = -5;
    m3.power = 1;

    m4.coefficient = 2;
    m4.power = 4;

    m5.coefficient = 1;
    m5.power = 5;

    m6.coefficient = 2;
    m6.power = 2;

    m7.coefficient = -4;
    m7.power = 3;

    m8.coefficient = 20;
    m8.power = 5;

    p1.add_monomial(m4);
    p1.add_monomial(m2);
    p1.add_monomial(m3);
    p1.add_monomial(m1);

    p2.add_monomial(m5);
    p2.add_monomial(m6);
    p2.add_monomial(m7);
    p2.add_monomial(m8);

    p1 = p1 + p2;


    p2.print();

}

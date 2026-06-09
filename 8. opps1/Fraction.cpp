#include<bits/stdc++.h>
using namespace std;
class Fraction{
    private:
    int numerator;
    int denominator;
    public:
    Fraction(int numerator,int denominator){
        this->numerator=numerator;
        this->denominator = denominator;
    }
    void print(){
        cout<<this -> numerator<<" / "<<denominator<<endl;
    }
    void simplify(){
        int gcd=1;
        for(int i=gcd;i<=min(numerator,denominator);i++)
        {
            if(numerator%i == 0 && denominator%i == 0)
            {
                gcd=i;
            } 
        }
        numerator/=gcd;
        denominator/=gcd;
    }
    void add(Fraction f2){
        int lcm=denominator*f2.denominator;
        int x= lcm/denominator;
        int y=lcm/f2.denominator;
        numerator = x*numerator+y*f2.numerator;
        denominator = lcm;
        simplify();
    }
};
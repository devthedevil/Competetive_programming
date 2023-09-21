#include<bits/stdc++.h>
using namespace std;
class Fraction{
    private:
    int numerator;
    int denominator;
    public:
    Fraction(){

    }
    Fraction(int numerator,int denominator){
        this->numerator=numerator;
        this->denominator = denominator;
    }
    int getNumerator() const{
        return numerator;
    }
    int getDenominator() const{
        return denominator;
    }
    void setNumerator(int numerator){
        this->numerator=numerator;
    }
    void setDenominator(int denominator){
        this->denominator=denominator;
    }
    void print() const{
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
    Fraction add(Fraction const f2){
        int lcm=denominator*f2.denominator;
        int x= lcm/denominator;
        int y=lcm/f2.denominator;
        int num = x*numerator+y*f2.numerator;
        
        Fraction fnew(num,lcm);
        fnew.simplify();
        return fnew;
    }
    Fraction operator+(Fraction const f2) const{
        int lcm=denominator*f2.denominator;
        int x= lcm/denominator;
        int y=lcm/f2.denominator;
        int num = x*numerator+y*f2.numerator;
        
        Fraction fnew(num,lcm);
        fnew.simplify();
        return fnew;
    }
    void multiply(Fraction const f2){
        numerator*=f2.numerator;
        denominator*=f2.denominator;
        simplify();
    }
    Fraction operator*(Fraction const f2) const{
        int n=numerator*f2.numerator;
        int d=denominator*f2.denominator;
        Fraction fnew(n,d);
        fnew.simplify();
        return fnew;
    }
    bool operator==(Fraction &f2){
        this->simplify();
        f2.simplify();
        return (this->numerator == f2.numerator && this->denominator == f2.denominator);
       
    }
    //Pre-increment operator
    Fraction& operator++(){
        numerator+=denominator;
        simplify();

        return *this;

    }
    //Post-increment operator
    Fraction operator++(int){
        Fraction fnew(numerator,denominator);
        numerator+= denominator;
        simplify();
        fnew.simplify();
        return fnew;

    }
    //+=operator
    Fraction& operator+=(Fraction const &f2){
        int lcm=denominator*f2.denominator;
        int x= lcm/denominator;
        int y=lcm/f2.denominator;
        int num = x*numerator+y*f2.numerator;
        numerator = num;
        denominator = lcm;
        
        simplify();
        return *this;
    

    }
};
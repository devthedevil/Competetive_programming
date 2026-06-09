#include<bits/stdc++.h>
#include"Fraction2.cpp"
using namespace std;
int main(){
    Fraction f1(10,3);
    Fraction f2(5,2);
    (f1+=f2)+=f2;
    f1.print();
    f2.print();
    // int i=5,j=3;
    // (i+=j)+=j;
    // cout<<i<<" "<<j<<endl;
    // Fraction f1(10,3);
    // Fraction f2(5,2);
    // Fraction f3=f1++;
    // f1.print();
    // f3.print();
    /*f1.print();
    // f1.print();
    // ++f1;
    // f1.print();

    Fraction f3 = ++(++f1);
        
    f1.print();
    f3.print();*/
    /*
    Fraction f3= f1+f2;
    Fraction f4= f1 + f2;

    f1.print();
    f2.print();
    f3.print();
    f4.print();
    Fraction f5=f1*f2;
    f5.print();

    if(f1==f2)
    cout<<" Equal "<<endl;
    else
    cout<<" Not Equal"<<endl; */
    
}
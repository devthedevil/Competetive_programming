#include<bits/stdc++.h>
#include"Fraction.cpp"
using namespace std;
int main(){
    Fraction f1(10,2);
    Fraction f2(15,4);
    f1.add(f2);
    f1.print();
    f2.print();
}
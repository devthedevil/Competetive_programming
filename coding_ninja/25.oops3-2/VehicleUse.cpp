#include<bits/stdc++.h>
using namespace std;
#include "Car.cpp"
int main(){
    Vehicle v;

    Car c;
    // v.print();
    // c.print();

    Vehicle *v1=new Vehicle;

    Vehicle *v2;

    // v2=&v;
    v2=&c;
    v1->print();

    v2->print();
}
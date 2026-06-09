#include <bits/stdc++.h>
using namespace std;
#include "Car.cpp"
#include "Truck.cpp"
class Bus: public Car, public Truck {
    public:
    Bus():Vehicle(5){
        cout<<"Bus's Constructor "<<endl;
    }
    ~Bus(){
        cout<<"Bus's destructor "<<endl;
    }
    void print(){
        cout<<"print Bus "<<endl;
    }
};
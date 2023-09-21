#include <bits/stdc++.h>
using namespace std;
// #include "Vehicle.cpp"
class Truck : virtual public Vehicle{
    public:
    Truck():Vehicle(4){
        cout<<"Truck's constructor"<<endl;
    }
    ~Truck(){
        cout<<"Truck's destructor"<<endl;
    }
    
};
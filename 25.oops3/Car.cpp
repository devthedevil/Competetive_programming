#include <bits/stdc++.h>
using namespace std;
#include "Vehicle.cpp"
class Car: virtual public Vehicle{
    public:
    int numGears;

    Car() :Vehicle(3){
        cout<<"Car's default constructor"<<endl;
    }
    // Car(int x,int y):Vehicle(x){
    //     cout<<"Parametrized Car's  constructor"<<endl;
    //     numGears=y;
    // }
    ~Car(){
        cout<<"Car's destructor "<<endl;
    }

    void print(){
        cout<<" car "<<endl;
    //     cout<<"numTyres "<<numTyres<<endl;
    //     cout<<"Color "<<color<<endl;
    //     cout<<"Num Gears "<<numGears<<endl;
    //     cout<<" maxspeed "<<maxSpeed<<endl;
    }
};

#include "Car.cpp"
#include <bits/stdc++.h>
using namespace std;
class HondaCity: public Car{
    public:
    HondaCity(){
        cout<<"deafult cons of HondaCity"<<endl;
    }
    HondaCity(int x,int y):Car(x,y){
        cout<<"parametrized of HondaCity"<<endl;
    }
    ~HondaCity(){
        cout<<"deafult destructor of HondaCity"<<endl;
    }
};
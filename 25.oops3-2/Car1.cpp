#include "Vehicle1.cpp"
class Car:public Vehicle{
    public:
    int numGears;

    void print(){
        cout<<"Car"<<endl;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Vehicle{
    private:
    int maxSpeed;

    protected:
    int numTyres;

    public:
    string color;

    // Vehicle(){
    //     cout<<"Vehicle's default constructor "<<endl;
    // }
    void print(){
        cout<<"print Vehicle "<<endl;
    }
    Vehicle(int z){
        cout<<"Vehicle parametrized constructor "<<z<<endl;
        maxSpeed = z;
    }
    ~Vehicle(){
        cout<<"Vehicle's destructor "<<endl;
    }

};
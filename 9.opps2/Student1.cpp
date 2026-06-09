#include<bits/stdc++.h>
using namespace std;
class Student {
    public:

    int age;
    const int rollNumber;
    int &x;//age refernce variable

    Student(int r,int age): rollNumber(r), age(age) ,x(this->age){
        // rollNumber=r;
        cout<<this->rollNumber<<" "<<this->age<<" "<<this->age<<endl;
    }

};
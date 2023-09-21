#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
    int age;
    char *name;
    public:
    Student(int age,char *name){
        this->age=age;
        //Shallow copy
        // this->name = name;

        //Deep copy
        this->name=  new char[strlen(name)+1];
        strcpy(this->name ,name);
    }
    //copy constructor
    Student(Student const &s){
    this->age=s.age;
    // this->name=s.name; Shallow copy
 
    //Deep copy
    this->name=new char[strlen(s.name)+1]; //Deep copy
    strcpy(this->name,s.name);
    }
    void display(){
        cout<<name<<" "<<age<<endl;
    }

};
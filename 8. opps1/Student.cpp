#include<iostream>
using namespace std;
class Student
{
    public:
    int rollNumber;
    private:
    int age;
    public:
    ~Student(){
        cout<<"Desconstructor calling !"<<endl;
    }

    //Default COnstructor
    Student(){
        cout<<"Constructor 1 calling !"<<endl;
    }
    //Parametrised constructor
    Student(int rollNumber){
        this->rollNumber = rollNumber;
        cout<<"Constructor 2 calling with roll number!"<<endl;
    }
     Student(int age,int rollNumber){
        this->rollNumber = rollNumber;
        this->age = age;
        cout<<"Constructor 3 calling with age and roll number!"<<endl;
    }
    void display(){
        cout<<age<<" "<<rollNumber<<endl;
    }
    int getAge(){
        return age;
    }
    void setAge(int age,int password){
        if(password != 123){
        return;
        }
        if(age<0){
        return;
        }
        this->age=age;
    }
};


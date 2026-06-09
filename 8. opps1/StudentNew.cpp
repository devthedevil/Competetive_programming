#include<iostream>
using namespace std;
#include "Student.cpp"
int main()
{
    Student S1;

    Student *S2=new Student;

    S1.setAge(20,123);
    S2->setAge(30,123);

    S1.display();
    S2->display();


} 

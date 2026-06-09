#include<bits/stdc++.h>
#include "Student.cpp"
using namespace std;
int main()
{
    Student s1; //cons 1 called
    Student s2(100); //cons 2 called
    Student s3(100,1002); //cons 3 called
    Student s4(s1);//copy constructor
    s2=s3; //copy assignment operator
    Student s5 = s1; //copy constructor

}
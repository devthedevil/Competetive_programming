#include<bits/stdc++.h>
#include "Student.cpp"
using namespace std;
int main()
{
    Student s1(10,1001);
    cout<<" S1: ";
    s1.display();
    Student *s2=new Student(20,2002);
    cout<<" S2: ";
    s2->display();
    *s2=s1;
    cout<<" new S2: ";
    s2->display();
    Student s3(30,3003);
    cout<<" S3: ";
    s3=s1;
    s3.display();
    delete s2;
}
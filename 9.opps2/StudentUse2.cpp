#include<bits/stdc++.h>
#include "Student2_static.cpp"
using namespace std;
int main(){
    Student s1;
    cout<<s1.rollNumber<<" "<<s1.age<<endl;
    cout<<s1.totalStudents<<endl;
    s1.totalStudents =20;
    Student s2;
    cout<<s2.totalStudents<<endl;
    cout<<Student :: totalStudents<<endl;
}
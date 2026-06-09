#include <bits/stdc++.h>
#include "Student.cpp"
int main()
{
    char name[] = "abcd";
    Student s1(12,name);
    s1.display();

    Student s2(s1);
    s2.name[0] = 'x';
    s2.display();
    s1.display();
    /*
    name[3]='e';
    Student s2(13,name);
    s2.display(); 

    s1.display();

    cout<<name<<endl;*/



}
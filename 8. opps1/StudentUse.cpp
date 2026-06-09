#include<iostream>
using namespace std;
#include "Student.cpp"
int main()
{
    // Create Objects Statically
    Student S1;
    Student S2;
    S1.rollNumber =40l;
    S2.rollNumber =402;
    // S1.age=13;
    cout<<"S1.age: "<<S1.getAge()<<endl;
    cout<<"S1 roll number :"<<S1.rollNumber<<endl;
    // S2.age=30;
    S1.display();
    S2.display();



    Student S4,S5;
    // Create Objects Dynamically

    Student *S6=new Student;
    // (*S6).age=23;
    (*S6).rollNumber=104;
    
    // cout<<(*S6).rollNumber<<endl;
    // cout<<S6->rollNumber<<endl;
    
    (*S6).display();
    cout<<"S6 age :"<<S6->getAge()<<endl;
    // cout<<(*S6).age<<endl;
    // cout<<S6->age<<endl; 

    // S6->age=23;
    S6->rollNumber=104;
    S6->display();

    return 0;
}
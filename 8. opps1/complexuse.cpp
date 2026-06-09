#include<bits/stdc++.h>
#include "complex.cpp"
using namespace std;
int main()
{
    int real1,img1,real2,img2;
    cin>>real1>>img1;
    cin>>real2>>img2;

    ComplexNumber c1(real1,img1);
    ComplexNumber c2(real2,img2);

    int choice;
    cin>>choice;

    if(choice==1)
    {
        c1.add(c2);
        c1.print();
    }
    else if(choice==2)
    {
        c1.mul(c2);
        c1.print();
    }
    else
    {
        return 0;
    }


    

}

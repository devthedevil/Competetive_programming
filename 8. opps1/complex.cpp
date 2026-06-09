#include<bits/stdc++.h>
using namespace std;
class ComplexNumber{
    private:
    int real;
    int img;
    public:
    ComplexNumber(int real,int img){
        this->real=real;
        this->img=img;
    }
    void add(ComplexNumber c)
    {
        real+=c.real;
        img+=c.img;
    }
    void mul(ComplexNumber c)
    {
        int t_real=real;
        t_real = real*c.real - img*c.img;
        img = real * c.img + img * c.real; 
        real=t_real;
    }
    void print()
    {
        cout<<real<<" + "<<img<<" i "<<endl;
    }

};
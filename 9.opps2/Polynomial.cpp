#include<bits/stdc++.h>
using namespace std;
class Polynomial{
    int *degCoeff;
    int capacity;

    public:
    Polynomial(){
        degCoeff =new int[5];
        capacity = 5;
        for(int i=0;i<capacity;i++)
        degCoeff[i]=0;
    }
    Polynomial(Polynomial const &p){

        this->degCoeff =new int[p.capacity];
        for(int i=0;i<p.capacity;i++)
        this->degCoeff[i]=p.degCoeff[i];

        this->capacity = p.capacity;
    }
    void operator=(Polynomial const &p){

        this->degCoeff =new int[p.capacity];
        for(int i=0;i<p.capacity;i++)
        this->degCoeff[i]=p.degCoeff[i];

        this->capacity = p.capacity;
    }
    Polynomial operator+(Polynomial const &p){

        this->degCoeff =new int[p.capacity];
        for(int i=0;i<p.capacity;i++)
        this->degCoeff[i]=p.degCoeff[i];

        this->capacity = p.capacity;
    }
    Polynomial operator-(Polynomial const &p){

        this->degCoeff =new int[p.capacity];
        for(int i=0;i<p.capacity;i++)
        this->degCoeff[i]=p.degCoeff[i];

        this->capacity = p.capacity;
    }
    Polynomial operator*(Polynomial const &p){

        this->degCoeff =new int[p.capacity];
        for(int i=0;i<p.capacity;i++)
        this->degCoeff[i]=p.degCoeff[i];

        this->capacity = p.capacity;
    }
    void setcoeff(int d,int coeff){
        if(d<capacity)
        degCoeff[d]=coeff;
        else{
            
        }

    }
    void print(){
        for(int i=capacity; i>=0; i--){
            if(this->degCoeff[i]!=0){
                cout<<this->degCoeff[i]<<"x" <<i;
                if(i!=0)
                cout<<" + ";
            }
        }
        cout<<endl;
    }

};
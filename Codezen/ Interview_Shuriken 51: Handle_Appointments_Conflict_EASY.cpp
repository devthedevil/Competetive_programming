/*
Given an array of intervals representing ‘N’ appointments, find out if a person can attend all the appointments.
Example 1:
Appointments: [[1,4], [2,5], [7,9]]
Output: false
Explanation: Since [1,4] and [2,5] overlap, a person cannot attend both of these appointments.
Example 2:
Appointments: [[6,7], [2,4], [8,12]]
Output: true
Explanation: None of the appointments overlap, therefore a person can attend all of them.
Example 3:
Appointments: [[4,5], [2,3], [3,6]]
Output: false
Explanation: Since [4,5] and [3,6] overlap, a person cannot attend both of these appointments.
*/
#include<bits/stdc++.h>
using namespace std;
struct t
{
    int st;
    int ft;
};
bool com(t t1,t t2)
{
    return t1.st<t2.st;
}
int main() 
{
    int n,flag=0;
    cin>>n;
    t a[n];
    for(int i=0;i<n;i++)
    cin>>a[i].st>>a[i].ft;
    sort(a,a+n,com);
    for(int i=0;i<n-1;i++)
    {
        if(a[i+1].st<a[i].ft)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
     cout<<"false"<<endl;
    else
        cout<<"true"<<endl;
    
}

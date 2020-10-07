#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll fibo(ll n)
{
    if(n==0 || n==1)
    return 1;
    else
    {
        return fibo(n-1)+fibo(n-2);
    }
    

}
ll fib2(ll n,ll *arr)
{
    if(n==0 || n==1)
    return 1;
    if(arr[n]>0)
    return arr[n];
    ll out=fib2(n-2,arr)+fib2(n-1,arr);
    arr[n]=out;
    return out;
}
ll fibi(ll n)
{
    ll *arr=new ll[n+1]();
    arr[0]=1;
    arr[1]=1;
    for(ll i=2;i<=n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    ll out=arr[n];
    delete [] arr;
    return out;

}
int main()
{
    ll n;
    cin>>n;
    ll *arr=new ll [n+1]();
    cout<<fib2(n,arr)<<endl;
    cout<<fibi(n)<<endl;
    cout<<fibo(n)<<endl;
}
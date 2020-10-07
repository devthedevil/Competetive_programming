/*
 Fibonacci Sum
Send Feedback
The fibonacci sequence is defined by the following relation:

 F(0) = 0
 F(1) = 1
 F(N) = F(N - 1) + F(N - 2), N >= 2

Your task is very simple. Given two non-negative integers N and M (N <= M), you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.
Input Format :

Two non-negative integers N and M. (N <= M)

Output Format :

A single line containing the answer for the task.

Sample Input :

10 
19

Sample Output :

10857


*/
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define MOD 1000000007
void multiply(ll a[][2],ll m[][2])
{
    ll fv=(a[0][0]*m[0][0])%MOD+(a[0][1]*m[1][0])%MOD;
    ll sv=(a[0][0]*m[0][1])%MOD+(a[0][1]*m[1][1])%MOD;
    ll tv=(a[1][0]*m[0][0])%MOD+(a[1][1]*m[1][0])%MOD;
    ll lv=(a[1][0]*m[0][1])%MOD+(a[1][1]*m[1][1])%MOD;

    a[0][0]=fv%MOD; //first value
    a[0][1]=sv%MOD; //second value
    a[1][0]=tv%MOD; //third value
    a[1][1]=lv%MOD; //fourth value
}
void power(ll a[][2],ll n)
{
    if(n==0 || n==1)
    return;

    power(a,n/2);
    //multiplying a^n/2 with a^n/2
    multiply(a,a);
    if(n%2!=0)
    {
        ll m[2][2]={{1,1},{1,0}};
        multiply(a,m);
    }

}
ll fib(ll n)
{
    if(n==0)
    return 0;
    ll A[2][2]={{1,1},{1,0}};
    power(A,n-1);
    return A[0][0];

}
unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{
	return (fib(n+2)-fib(m+1)+MOD)%MOD;
}



int main()
{
    unsigned long long m,n;
    cin>>m>>n;
	cout<<fiboSum(m,n);
    return 0;
}

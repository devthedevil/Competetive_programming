/*
Write a program to find x to the power n (i.e. x^n). Take x and n from the user.
You need to print the answer.
Note : For this question, you can assume that 0 raised to the power of 0 is 1


Input format :

Two integers x and n (separated by space)

Output Format :

x^n (i.e. x raise to the power n)

Constraints:

0 <= x <= 8 
0 <= n <= 9

Sample Input 1 :

 3 4

Sample Output 1 :

81

Sample Input 2 :

 2 5

Sample Output 2 :

32


*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll power(ll x,ll n)
{
    ll ans=1;
    if(x==0 && n==0)
        return 1;
    if(x==0)
        return 0;
    while(n>0)
    {
        if(n%2==1)
        ans*=x;
        n=n>>1;
        x*=x;
        // cout<<"a"<<endl;
    }
    return ans;
}
int main() {
	ll x,n;
    cin>>x>>n;
	cout<<power(x,n)<<endl;	
}

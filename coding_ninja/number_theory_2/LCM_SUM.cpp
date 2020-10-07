/*
 LCM SUM
Send Feedback
Given n, calculate and print the sum :

LCM(1,n) + LCM(2,n) + .. + LCM(n,n)

where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
Input Format :

Line 1 : Integer n

Output Format :

Required sum

Constraints :
1 <= T <= 300000
1 <= n <= 1000000
Sample Input 1 :

5

Sample Output 1 :

55

Sample Input 2 :

2

Sample Output 2 :

4


*/
#include<bits/stdc++.h>          
using namespace std;
#define MOD 1000000007
#define lim 1000000
#define ll long long 
ll phi[lim+1];
void etf()
{
    
    for(ll i=0;i<=lim;i++)
    phi[i]=i;
    for(ll i=2;i<=lim;i++)
    {
        if(phi[i]==i)
        {
            phi[i]=i-1;
            for(ll j=2*i;j<=lim;j+=i)
            {
                phi[j]=(phi[j]*(i-1))/i;
            }
        }
    }
}
void func(long long n)
{
	etf();
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            ans+=phi[i]*i;
            // cout<<phi[i]<<" phi "<<endl;
            // cout<<i<<" i "<<endl;
            // cout<<ans<<" ans "<<endl;
        }
    }
    ans++;
    ans=(ans*n)/2;
    cout<<ans<<endl;
}

int main()
{ 
    long long n;
    scanf ( "%lld", &n );
	func(n);
    return 0;
}

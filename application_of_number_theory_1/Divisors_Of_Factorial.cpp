/*
 Divisors Of Factorial
Send Feedback
Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.
Input

The first line contains T, number of testcases.


T lines follows each containing the number N.

Output

Print T lines of output each containing the answer.

Constraints

1 <= T <= 500

0 <= N <= 50000

Sample Input:

3
2
3
4

Sample Output:

2
4
8


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
bool check(ll n)
{
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,k;
    cin>>t;
    while(t--)
    {
    cin>>n;
    if(n==0)
    {
        cout<<1<<endl;
        continue;
    }
    vector<bool> sieve(n+1,true);
    sieve[0]=sieve[1]=false;
    for(ll i=2;i*i<=n;i++)
    {
        if(sieve[i])
        {
            if(check(i))
            {
                for(ll j=i*i;j<=n;j+=i)
                {
                    sieve[j]=false;
                }
            }
        }

    }
    ll answer=1;
    ll *ans=new ll[n+1];
    for(ll i=0;i<=n;i++)
    ans[i]=0;

    for(ll i=2;i<=n;i++)
       { 
           if(sieve[i])
           {
               // cout<<i<<" prime "<<endl;
               ll num=i;
               while(num<=n)
               {
                   
                   ans[i]+=n/num;
                   num*=i;
                   
               }
               // cout<<ans[i]<<endl;
               ans[i]++;
               answer=(answer*ans[i])%MOD;
           }
       }
    cout<<answer<<endl;
    }

}
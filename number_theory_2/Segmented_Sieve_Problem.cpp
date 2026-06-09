/*
 Segmented Sieve Problem
Send Feedback
In this problem you have to print all primes from given interval.
Input

t - the number of test cases, then t lines follows. [t <= 150]
On each line are written two integers L and U separated by a blank. L - lower bound of 
interval, U - upper bound of interval. [2 <= L < U <= 2147483647] [U-L <= 1000000].

Output

For each test case output must contain all primes from interval [L; U] in increasing order.

Sample Input:

2
2 10
3 7

Sample Output:

2
3
5
7
3
5
7 


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define max 100001
vector<ll>* sieve()
{
    bool isprime[max];
    memset(isprime,1,sizeof(isprime));
    isprime[0]=isprime[1]=0;
    for(ll i=2;i<max;i++)
    {
        if(isprime[i])
        {
            for(ll j=i*i;j<max;j+=i)
            isprime[j]=0;
        }

    }
    vector<ll>* prime=new vector<ll>();
    prime->push_back(2);
    for(int i=3;i<max;i+=2)
    if(isprime[i])
    prime->push_back(i);
    return prime;
}
void printprime(ll l,ll r,vector<ll>* &prime)
{
    bool isprime[r-l+1];
    memset(isprime,1,sizeof(isprime));

    for(ll i=0;prime->at(i)*prime->at(i)<=r;i++)
    {
        ll currprime=prime->at(i);
        //just smaller or equal value to l
        ll base=(l/currprime)*currprime;
        if(base<l)
        {
            base+=currprime;
        }
        //mark all multiples within L and R as false
        for(ll j=base;j<=r;j+=currprime)
        {
            isprime[j-l]=0;
        }
        // there may be a case where base itself is a prime
        if(base==currprime)
        {
            isprime[base-l]=1;
        }
    }
    for(ll i=l;i<=r;i++)
    if(isprime[i-l])
    cout<<i<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll>* prime=sieve();
    ll t,l,r;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        printprime(l,r,prime);

    }

}

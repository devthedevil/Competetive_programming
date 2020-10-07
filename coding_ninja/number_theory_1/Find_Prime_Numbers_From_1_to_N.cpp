/*
 Find Prime Numbers From 1 to N
Send Feedback
Given a number N, find number of primes in the range [1,N].
Input:

The only line of input consists of a number N

Output:

Print the number of primes in the range [1,N].`

Constraints:

1≤N≤1000000

Sample Input :

3 

Sample Output -

2


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
    cin>>n;
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
    ll count=0;
    for(ll i=2;i<=n;i++)
        if(sieve[i])
        count++;
    cout<<count<<endl;


}

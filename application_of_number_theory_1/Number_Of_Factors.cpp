/*
 Number Of Factors
Send Feedback
A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b,
 and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1
  to be 0-factorful.
Input

Your input will consist of a single integer T followed by a newline and T test cases. Each test cases consists of a single line containing integers a, b, and n as described above.

Output

Output for each test case one line containing the number of n-factorful integers in [a, b].

Constraints

T < 10000

1 ≤ a ≤ b ≤ 10^6

0 ≤ n ≤ 10

Sample Input

5
1 3 1
1 10 2
1 10 3
1 100 3
1 1000 0

Sample Output

2 
2
0
8
1


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
    vector<bool> sieve(1000001,true);
    sieve[0]=sieve[1]=false;
    for(ll i=2;i*i<=1000000;i++)
    {
        if(sieve[i])
        {
            if(check(i))
            {
                for(ll j=i*i;j<=1000000;j+=i)
                {
                    sieve[j]=false;
                }
            }
        }

    }
    vector<ll> factors(1000001,0);
    for(ll i=2;i<=1000000;i++)
    {
        if(sieve[i])
        {
            ll num=i;
            while(num<=1000000)
            {

                factors[num]++;
                num+=i;

            }
        }
    }
    ll **mat=new ll*[11];
    for(ll i=0;i<=10;i++)
    {
        mat[i]=new ll[1000001];
        for(ll j=0;j<=1000000;j++)
        mat[i][j]=0;
    }
    for(ll i=0;i<=10;i++)
    {
        for(ll j=1;j<=1000000;j++)
        {
            if(factors[j]==i)
            mat[i][j]=mat[i][j-1]+1;
            else
            mat[i][j]=mat[i][j-1];
        }
    }
    ll t,n,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        cout<<mat[n][b]-mat[n][a-1]<<endl;
    }






}
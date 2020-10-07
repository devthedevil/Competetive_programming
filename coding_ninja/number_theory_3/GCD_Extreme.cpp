/*
 GCD Extreme
Send Feedback
Given the value of N, you will have to find the value of G. The meaning of G is given in the following code

G=0;
for(i = 1 ; i < N ; i++)
   for(j = i+1 ; j <= N ; j++) 
       G+=gcd(i,j);

Here gcd() is a function that finds the greatest common divisor of the two input numbers.
Input

The input file contains at most 20000 lines of inputs. Each line contains an integer N (1 < N < 1000001).
 The meaning of N is given in the problem statement. Input is terminated by a line containing a single zero.

Output

For each line of input produce one line of output. This line contains the value of G for the corresponding N. 
The value of G will fit in a 64-bit signed integer.

Sample Input:

10
100
200000
0

Sample Output:

67
13015
143295493160


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define lim 1000000
#define N 1000001
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
ll dp[N+1];
void gdcextreme()
{
    
    ll ans=0;
    ll res[N+1];
    memset(dp,0,sizeof(dp));
    memset(res,0,sizeof(res));
    for(ll i=1;i<N;i++)
    {
        for(ll j=2;i*j<=N;j++)
        res[i*j]+=i*phi[j];

    }
    for(ll i=1;i<=N;i++)
    {ans+=res[i];dp[i]=ans;}
    // return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    etf();
    gdcextreme();
    while(1)
    {
        cin>>n;
        if(n==0)
        break;
        cout<<dp[n]<<endl;
        // for(ll i=0;i<n;i++)

    }

}

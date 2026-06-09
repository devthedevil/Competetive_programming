#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
typedef pair<ll,ll> ipair;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,w;
    cin>>n>>w;
    ipair *arr=new ipair[n];
    for(ll i=0;i<n;i++)
    cin>>arr[i].first>>arr[i].second;
    sort(arr, arr + n);
    ll ***dp=new ll**[2];
    for(ll i=0;i<2;i++)
    {
        dp[i]=new ll*[n+1];
        for(ll j=0;j<=n;j++)
        {
            dp[i][j]=new ll[w+1];
            for(ll k=0;k<=w;k++)
            dp[i][j][k]=0;
        }
    }
    ll primes[11]={1,2,3,5,7,11,13,17,19,23,29};
    //base case
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=w;j++)
        {
            dp[0][i][j]=dp[0][i-1][j];
            if(j>=arr[i-1].second)
            {
                dp[0][i][j]=max(dp[0][i][j],dp[0][i-1][j-arr[i-1].second]+arr[i-1].first);
            }
        }
    }
    for(ll prime=1;prime<11;prime++)
    {
        ll p=prime%2;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=w;j++)
            {
                dp[p][i][j]=dp[p][i-1][j];
                if(j>arr[i-1].second)
                {
                    dp[p][i][j]=max(dp[p][i][j],
                    max(dp[p][i-1][j-arr[i-1].second]+arr[i-1].first,dp[p^1][i-1][j-arr[i-1].second]+arr[i-1].first*primes[prime]));
                }
            }
        }
    }

    cout<<dp[0][n][w]<<endl;

}

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
bool subsetsum(ll *val,ll n,ll sum)
{
    bool **dp=new bool*[n+1];
    for(ll i=0;i<=n;i++)
    {
        dp[i]=new bool[sum+1];
    }
    for(ll i=1;i<=sum;i++)
    dp[0][i]=0;
    for(ll i=0;i<=n;i++)
    dp[i][0]=1;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=sum;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=val[i-1])
            {
                dp[i][j] |=dp[i][j-val[i-1]];
            }
        }
    }
    return dp[n][sum];

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll val[]={1,3,5,7,9};
    ll sum=12;
    cout<<subsetsum(val,5,sum)<<endl; 

}

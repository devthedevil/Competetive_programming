#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll k(ll n,ll *w,ll *v,ll W)
{
    ll **dp=new ll*[n+1];
    for(ll i=0;i<=n;i++)
    {
        dp[i]=new ll[W+1];
    }
    for(ll i=0;i<=n;i++)
    dp[i][0]=0;
    for(ll i=0;i<=W;i++)
    dp[0][i]=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=W;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(w[i-1]<=j)
            {
                    dp[i][j]=max(v[i-1]+dp[i-1][j-w[i-1]],dp[i][j]);
            }
        }
    }
    return dp[n][W];



}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=4;
    ll w[4]={1, 2, 3, 5};
    ll v[4]={5, 4, 8, 6};
    ll W=5;
    cout<<k(n,w,v,W)<<endl;
}


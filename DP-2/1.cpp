#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
typedef pair<ll,ll> ipair;
ll pil(ipair *c,ll n,ll x,ll **dp)
{
    if(n==0)
    {
        if(x==0) return 0;
        else return INT_MAX;
    }
    
    if(dp[n][x]>-1) return dp[n][x];
    if(x==0)
    {
        dp[n][x]=c[0].second+pil(c+1,n-1,x+1,dp);
        return dp[n][x]; 
    }
    else if(x==n)
    {
        dp[n][x]=c[0].first+pil(c+1,n-1,x-1,dp);
        return dp[n][x];    
    }
    else
    {
        dp[x][n]=min(c[0].second+pil(c+1,n-1,x+1,dp),c[0].first+pil(c+1,n-1,x-1,dp));
        return dp[x][n];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ipair *c=new ipair[n];
    for(ll i=0;i<=n;i++)
    cin>>c[i].first>>c[i].second;
    ll **dp=new ll*[n+1];
    for(ll i=0;i<=n;i++)
    {
        dp[i]=new ll[n+1];
        for(ll j=0;j<n;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<pil(c,n,0,dp)<<endl;
}
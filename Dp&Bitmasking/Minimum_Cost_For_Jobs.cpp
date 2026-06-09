#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
//n=no.of jobs
//p=person to be assigned now
ll mincost(ll cost[][4],ll n,ll p,ll mask,ll *dp)
{
    if(p>=n)
    return 0;
    if(dp[mask]!=INT_MAX)
    return dp[mask];
    ll minimum=INT_MAX;
    for(ll j=0;j<4;j++)
    {
        if(!(mask&(1<<j)))
        {
            ll ans=mincost(cost,n,p+1,mask | (1<<j),dp)+ cost[p][j]; 
            minimum=min(minimum,ans);
        }
    }
    dp[mask]=minimum;
    return minimum;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,k;
    ll *dp=new ll[1<<4];
    for(ll i=0;i<(1<<4);i++)
    dp[i]=INT_MAX;
    ll cost[4][4]={{10,2,6,5},{1,15,12,8},{7,8,9,3},{15,13,4,10}};
    cout<<mincost(cost,4,0,0,dp)<<endl;

}

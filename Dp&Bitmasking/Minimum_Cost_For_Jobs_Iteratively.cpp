#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll mincost(ll cost[][4],ll n)
{
    ll *dp=new ll[1<<n]; dp[0]=0;
    for(ll i=1;i<(1<<n);i++)
    dp[i]=INT_MAX;
    for(ll mask=0;mask<((1<<n)-1);mask++)
    {
        ll temp=mask;
        ll k=0;
        // k=count no. of set bits
        while(temp>0)
        {
            if(temp%2)
            k++;
            temp/=2;
        }
        for(ll j=0;j<n;j++)
        {
            if(!(mask &(1<<j)))
            dp[mask | (1<<j)]=min(dp[mask| (1<<j)],dp[mask]+cost[k][j]);
        }
    }
    return dp[(1<<n)-1];
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
    cout<<mincost(cost,4)<<endl;


}

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char a[100];
    char b[100];
    cin>>a;
    cin>>b;
    ll m=strlen(a);
    ll n=strlen(b);
    ll **dp=new ll*[m+1];
    for(ll i=0;i<=m;i++)
    {
        dp[i]=new ll[n+1];
        for(ll j=0;j<=n;j++)
        {
            dp[i][j]=0;
        }
    }
    for(ll i=1;i<=m;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(a[m-i]==b[n-j])
            dp[i][j]=1+dp[i-1][j-1];
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            
        }
    }
    cout<<dp[m][n]<<endl;
}
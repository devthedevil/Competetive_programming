#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll lcs(char* s1,char* s2)
{
    if(s1[0]=='\0' || s2[0]=='\0')
    return 0;

    if(s1[0]==s2[0])
    return 1+lcs(s1+1,s2+1);
    else
    {
        return max(lcs(s1+1,s2),lcs(s1,s2+1));
    }
    
}
ll lcs2helper(char* s1,char* s2,ll m,ll n,ll **dp)
{
    if(m==0 || n==0)
    return 0;

    if(dp[m][n]>-1)
    return dp[m][n];
    ll ans;
    if(s1[0]==s2[0])
    ans=1+lcs2helper(s1+1,s2+1,m-1,n-1,dp);
    else
    {
        ans= max(lcs2helper(s1+1,s2,m-1,n,dp),lcs2helper(s1,s2+1,m,n-1,dp));
    }
    dp[m][n]=ans;
    return ans;
}
ll lcs2(char* s1,char* s2)
{
    ll m=strlen(s1);
    ll n=strlen(s2);
    ll **dp=new ll*[m+1];
    for(ll i=0;i<=m;i++)
    {
        dp[i]=new ll[n+1];
        for(ll j=0;j<=n;j++)
        {
            dp[i][j]=-1;
        }
    }
    ll ans=lcs2helper(s1,s2,m,n,dp);
    for(ll i=0;i<=m;i++)
    delete [] dp[i];
    delete [] dp;
    return ans;

}
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char a[100];
    char b[100];
    cin>>a;
    cin>>b;
    cout<<lcs2(a,b)<<endl;
    cout<<lcs(a,b)<<endl;

    
}
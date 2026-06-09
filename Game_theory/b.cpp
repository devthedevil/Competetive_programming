#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
// int solve(string A) {
//     string B=string(A.rbegin(),A.rend());
//     int dp[A.length()+1][B.length()+1];
//     memset(dp,0,sizeof(dp));
//     for(int i=0;i<=A.length();i++)
//     {
//         for(int j=0;j<=B.length();j++)
//         {
//             if(i==0 || j==0)
//             dp[i][j]=0;
//             else if(A[i]==B[j])
//             {
//             dp[i][j]=1+dp[i-1][j-1];
//             // cout<<dp[i][j]<<" i "<<i<<" j "<<j<<endl;
//             }
//             else
//             {
//             dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
//             // cout<<dp[i][j]<<" i "<<i<<" j "<<j<<endl;
//             }
//         }
//     }
//     // cout<<B<<endl;
//     return dp[A.length()][B.length()];
//     // return 1;
// }
int solve(string A) {
    
    int n=A.length();
    int dp[n][n];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    dp[i][j]=1;
    // memset(dp,0,sizeof(dp));
    // for(int i=0;i<n;i++)
    // cout<<dp[i][i]<<" ";
    // cout<<endl;
    for(int i=0;i<n-1;i++)
    {
        if(A[i]==A[i+1])
        dp[i][i+1]=2;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+2;j<n;j++)
        {
            
            if(A[i]==A[j])
            {
            dp[i][j]=2+dp[i+1][j-1];
            // cout<<dp[i][j]<<" i "<<i<<" j "<<j<<" if "<<endl;
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
                // cout<<dp[i][j]<<" i "<<i<<" j "<<j<<" else "<<endl;
            }
        }
    }
    return dp[0][n-1];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,k;
    string s,s2;
    cin>>s;
    // while(t--)
    // {
        // cin>>n;
        // for(ll i=0;i<n;i++)

    // }
    cout<<solve(s)<<endl;

}

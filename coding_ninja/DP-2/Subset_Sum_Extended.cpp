/*
 Subset Sum - Problem
Send Feedback

Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.
Input Format

First line contains a single integer n (1<=n<=1000)
Second line contains n space separated integers (1<=a[i]<=1000)
Last line contains a single positive integer k (1<=k<=1000)

Output Format

Output Yes if there exists a subset whose sum is k, else output No.

Sample Input

3
1 2 3
4

Sample Output

Yes


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
bool subsetsum(ll *val,ll n,ll sum)
{
    bool **dp=new bool*[2];
    for(ll i=0;i<=1;i++)
    {
        dp[i]=new bool[sum+1];
    }
    for(ll i=0;i<=sum;i++)
    dp[0][i]=false;
    dp[1][0]=true;
    dp[0][0]=true;
    ll flag=1;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=sum;j++)
        {
            dp[flag][j]=dp[flag^1][j];
            if(j>=val[i-1])
            {
                dp[flag][j] =dp[flag][j] || dp[flag^1][j-val[i-1]];
            }
        }
        flag=flag^1;
    }
    bool ans=dp[flag^1][sum];
    return ans;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll *val=new ll[n];
    for(ll i=0;i<n;i++)
    cin>>val[i];
    ll sum;
    cin>>sum;
    if(subsetsum(val,n,sum))
            cout<<"Yes"<<endl; 
    else
        cout<<"No"<<endl;

}


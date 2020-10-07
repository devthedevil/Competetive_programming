/*
 Square Brackets
Send Feedback
You are given:

a positive integer n,
an integer k, 1<=k<=n,
an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.

What is the number of proper bracket expressions of length 2n with opening brackets appearing in positions s1, s2,...,sk?
Illustration
Several proper bracket expressions:

[[]][[[]][]] 
[[[][]]][][[]]

An improper bracket expression:

[[[][]]][]][[]]

There is exactly one proper expression of length 8 with opening brackets in positions 2, 5 and 7.
Task
Write a program which for each data set from a sequence of several data sets:
1. reads integers n, k and an increasing sequence of k integers from input,
2. computes the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1,s2,...,sk,
3. writes the result to output.
Input

The first line of the input file contains one integer d, 1 <= d <= 10, which is the number of data sets. 
The data sets follow. Each data set occupies two lines of the input file. The first line contains two integers n and k 
separated by single space, 1 <= n <= 19, 1 <= k <= n. The second line contains an increasing sequence of k integers from 
the interval [1;2n] separated by single spaces.

Output

The i-th line of output should contain one integer - the number of proper bracket expressions of
 length 2n with opening brackets appearing at positions s1, s2,...,sk.

Sample Input

5 
1 1 
1 
1 1 
2 
2 1 
1 
3 1 
2 
4 2 
5 7 

Sample Output

1 
0 
2 
3 
2 


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll f(ll o,ll c,ll n,bool *a,ll **dp)
{
    if(o>n || c>n)
    return 0;
    if(o==n && c==n)
    return 1;
    if(dp[o][c]>-1)
    return dp[o][c];
    if(o==c || a[o+c]==true)
    {
        dp[o][c]=f(o+1,c,n,a,dp);
        return f(o+1,c,n,a,dp);
    }
    else if(o==n)
    {
        dp[o][c]=f(o,c+1,n,a,dp);
        return f(o,c+1,n,a,dp);
    }
    else
    {
        dp[o][c]=f(o+1,c,n,a,dp)+f(o,c+1,n,a,dp);
        return dp[o][c];
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,x,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        bool *a=new bool[2*n];
        for(ll i=0;i<2*n;i++)
        a[i]=false;
        ll **dp=new ll*[n+1];
        for(ll i=0;i<=n;i++)
        {
            dp[i]=new ll[n+1];
            for(ll j=0;j<=n;j++)
            dp[i][j]=-1;

        }
        for(ll i=0;i<k;i++)
        {
            cin>>x;
            a[x-1]=true;
        }
        cout<<f(0,0,n,a,dp)<<endl;

    }

}

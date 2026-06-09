/*
 Trader Profit
Send Feedback
Mike is a stock trader and makes a profit by buying and selling stocks. He buys a stock at a
 lower price and sells it at a higher price to book a profit. He has come to know the stock 
 prices of a particular stock for n upcoming days in future and wants to calculate the maximum 
 profit by doing the right transactions (single transaction = buying + selling). Can you help him maximize his profit?
Note: A transaction starts after the previous transaction has ended. Two transactions can't overlap or run in parallel.
The stock prices are given in the form of an array A for n days.
Given the stock prices and a positive integer k, find and print the maximum profit Mike can make in at most k transactions.
Input Format

The first line of input contains an integer q denoting the number of queries.

The first line of each test case contains a positive integer k, denoting the number of transactions. 

The second line of each test case contains a positive integer n, denoting the length of the array A.

The third line of each test case contains n space-separated positive integers, denoting the prices of each day in the array A.

Constraints

1<=q<=100

0<k<10

2<=n<=30

0<=elements of array A<=1000

Output Format

For each query print the maximum profit earned by Mike on a new line. 

Sample Input

3
2
6
10 22 5 75 65 80
3
4
20 580 420 900
1
5
100 90 80 50 25

Sample Output

87
1040
0


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll dp[31][11][2];
ll p(ll* a,ll n,ll k,ll ongoing,ll dp[][11][2])
{
    if(n==0 || k==0)
    return 0;
    if(dp[n][k][ongoing]>=0)
    return dp[n][k][ongoing];
    ll op1=p(a+1,n-1,k,ongoing,dp);//ignore
    if(ongoing)
    {
        ll op2=p(a+1,n-1,k-1,0,dp)+a[0];//sell
        dp[n][k][ongoing]=max(op1,op2);
        return dp[n][k][ongoing];

    }
    else
    {
        if(k>0)
        {
            ll op3=p(a+1,n-1,k,1,dp)-a[0];//buy
            dp[n][k][ongoing]=max(op1,op3);
            return dp[n][k][ongoing];
        }
    }
    dp[n][k][ongoing]=op1;
    return op1;
    
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q,k,n;
    cin>>q;
    while(q--)
    {
        cin>>k>>n;
        ll *a=new ll[n];
        for(ll i=0;i<n;i++)
        cin>>a[i];
        
        for(ll i=0;i<=n;i++)
        {
            for(ll j=0;j<=k;j++)
            {
                dp[i][j][0]=-1;
                dp[i][j][1]=-1;
            }
        }
        cout<<p(a,n,k,0,dp)<<endl;
    }

}


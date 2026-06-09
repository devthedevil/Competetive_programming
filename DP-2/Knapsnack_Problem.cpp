/*
 Knapsnack - Problem
Send Feedback
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items
 and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Space complexity should be O(W).
Input Format :

Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry

Output Format :

Line 1 : Maximum value V

Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :

4
1 2 4 5
5 4 8 6
5

Sample Output :

13


*/
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int knapsack(int* w,int* v,int n,int W)
{
    int **dp=new int*[2];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[W+1];
    }
    for(ll i=0;i<=W;i++)
    dp[0][i]=0;
    dp[1][0]=0;
    int flag=1;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=W;j++)
        {
            dp[flag][j]=dp[flag^1][j];
            if(w[i-1]<=j)
            {
                    dp[flag][j]=max(v[i-1]+dp[flag^1][j-w[i-1]],dp[flag][j]);
            }
        }
        flag=flag^1;
    }
    return dp[flag^1][W];
}

int main(){

  int n; 
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }

  for(int i = 0; i < n; i++){
    cin >> values[i];
  }

  int maxWeight;
  cin >> maxWeight;

  cout << knapsack(weights, values, n, maxWeight);

}



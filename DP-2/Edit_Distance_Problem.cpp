/*
 Edit Distance - Problem
Send Feedback
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. 
Edit Distance of two strings is minimum number of steps required to make one string equal to other. In 
order to do so you can perform following three operations only :

1. Delete a character

2. Replace a character with another one

3. Insert a character

Note - Strings don't contain spaces
Input Format :

Line 1 : String s
Line 2 : String t

Output Format :

Line 1 : Edit Distance value

Constraints

1<= m,n <= 20

Sample Input 1 :

abc
dc

Sample Output 1 :

2


*/
#include "Solution.h"

int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}



#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int editDistance(string s1, string s2){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
	ll m=s1.length();
    ll n=s2.length();
    ll **dp=new ll*[m+1];
    for(ll i=0;i<=m;i++)
    {
        dp[i]=new ll[n+1];
        for(ll j=0;j<=n;j++)
        {
            dp[i][j]=0;
        }
    }
    for(ll i=0;i<=m;i++)
        dp[i][0]=i;
    for(ll i=0;i<=n;i++)
        dp[0][i]=i;
    for(ll i=1;i<=m;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(s1[m-i]==s2[n-j])
            dp[i][j]=dp[i-1][j-1];
            else
            {
                dp[i][j]=min(1+dp[i-1][j],min(1+dp[i][j-1],1+dp[i-1][j-1]));
            }
            
        }
    }
    // cout<<dp[m][n]<<endl;
    return dp[m][n];

}

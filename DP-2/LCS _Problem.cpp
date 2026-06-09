/*
 LCS - Problem
Send Feedback
Given 2 strings of S1 and S2 with lengths m and n respectively, find the length of longest common subsequence.
A subsequence of a string S whose length is n, is a string containing characters in same relative order as they 
are present in S, but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 
to n. E.g. subsequences of string "abc" are - "",a,b,c,ab,bc,ac,abc.
Input Format :

Line 1 : String S1
Line 2 : String s2

Output Format :

Line 1 : Length of lcs

Sample Input :

adebc
dcadb

Sample Output :

3


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << lcs(s1,s2) << endl;

}



#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int lcs(string s1, string s2){

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
    for(ll i=1;i<=m;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(s1[m-i]==s2[n-j])
            dp[i][j]=1+dp[i-1][j-1];
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            
        }
    }
    // cout<<dp[m][n]<<endl;
    return dp[m][n];

}

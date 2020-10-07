/*
 Shortest Subsequence
Send Feedback
Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
Note: input data will be such so there will always be a solution.
Input Format :

Line 1 : String S of length N (1 <= N <= 1000)
Line 2 : String V of length M (1 <= M <= 1000)

Output Format :

Length of shortest subsequence in S such that it is not a subsequence in V

Sample Input :

babab
babba

Sample Output :

3


*/
#include<bits/stdc++.h>
using namespace std;

int solveh(char *S,char *V,int n,int m,int **dp)
{
    // if(S[0]=='\0')
    if(n==0)
        return 10000;
    if(m<=0)
        return 1;
    if(dp[n][m]>-1)
        return dp[n][m];
    
    for(int i=0;i<m;i++)
    {
        if(S[0]==V[i])
        {
            dp[n][m]=min(solveh(S+1,V,n-1,m,dp),1+solveh(S+1,V+i+1,n-1,m-i-1,dp));
        	return dp[n][m];
        }   
    }
    dp[n][m]=1;
    return 1;
}
int solve(string S,string V)
{
    int **dp=new int*[S.length()+1];
    for(int i=0;i<=S.length();i++)
    {
        dp[i]=new int[V.length()+1];
        for(int j=0;j<=V.length();j++)
            dp[i][j]=-1;
    }
    char s[1001];
    char v[1001];
    for(int i=0;i<S.length();i++)
    s[i]=S[i];
    for(int i=0;i<V.length();i++)
    v[i]=V[i];
    return solveh(s,v,S.length(),V.length(),dp);

}


int main()
{
	string S,V;
	cin>>S>>V;
	cout<<solve(S,V)<<endl;
	return 0;
}
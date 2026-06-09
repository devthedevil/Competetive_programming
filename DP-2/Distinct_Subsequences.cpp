/*
 Distinct Subsequences
Send Feedback
Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters.
For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.
Input

First line of input contains an integer T which is equal to the number of test cases. You are required to process all test cases. Each of next T lines contains a string s.

Output

Output consists of T lines. Ith line in the output corresponds to the number of distinct subsequences of ith input string. Since, this number could be very large, you need to output ans%1000000007 where ans is the number of distinct subsequences. 

Constraints and Limits

T ≤ 100, length(S) ≤ 100000

All input strings shall contain only uppercase letters.

Sample Input

3
AAA
ABCDEFG
CODECRAFT

Sample Output

4
128
496


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,k;
    cin>>t;
    string s;
    while(t--)
    {
        cin>>s;
        ll *last=new ll[256+1]();
        for(ll i=0;i<=256;i++)
        last[i]=-1;
        n=s.length();
        ll *dp=new ll[n+1];
        dp[0]=1;
        for(ll i=1;i<=n;i++)
        {
            // dp[i]=(dp[i-1]%MOD+dp[i-1]%MOD)%MOD;
            dp[i]=2*dp[i-1];
            // cout<<last[s[i]]<<" last "<<endl;
            if(last[s[i-1]]!=-1)
            dp[i]=(MOD+dp[i]-dp[last[s[i-1]]])%MOD;
            dp[i]%=MOD;
            last[s[i-1]]=(i-1);
            // cout<<dp[i]<<" dp "<<endl;
        }

        cout<<dp[n]%MOD<<endl;
    }

}

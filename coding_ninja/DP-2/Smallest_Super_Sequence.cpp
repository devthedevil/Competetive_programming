/*
 Smallest Super-Sequence
Send Feedback
Given two strings S and T, find and return the length of their smallest super-sequence.
A shortest super sequence of two strings is defined as the shortest possible string containing both strings as subsequences.
Note that if the two strings do not have any common characters, then return the sum of lengths of the two strings.
Input Format:

Line 1 : A string
Line 2: Another string

Output Format:

Length of the smallest super-sequence of given two strings. 

Sample Input:

ab
ac

Sample Output:

3

Sample Output Explanation:

Their smallest super-sequence can be "abc" which has length=3.


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int smallestSuperSequence(char str1[], int len1, char str2[], int len2) { 
  /* Don't write main().
    efsdf Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
     
  */
    ll **dp=new ll *[len1+1];
    for(ll i=0;i<=len1;i++)
    {
        dp[i]=new ll[len2+1];
    }
    for(ll i=len1;i>=0;i--)
        dp[i][len2]=len1-i;
    for(ll i=len2;i>=0;i--)
        dp[len1][i]=len2-i;
    for(ll i=len1-1;i>=0;i--)
    {
        for(ll j=len2-1;j>=0;j--)
        {
            if(str1[i]==str2[j])
            dp[i][j]=1+dp[i+1][j+1];
            else
                dp[i][j]=1+min(dp[i+1][j],dp[i][j+1]);
        }
    }
    return dp[0][0];

}
int main()
{
    char str1[50], str2[50];
    cin>>str1;
    cin>>str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = smallestSuperSequence(str1, len1, str2, len2);
    cout<<min_len;
    return 0;
}

/*
 String Maker
Send Feedback
According to Ancient Ninjas , string making is an art form . There are various methods of string making , one of them uses previously generated strings to make the new one . Suppose you have two strings A and B , to generate a new string C , you can pick a subsequence of characters from A and a subsequence of characters from B and then merge these two subsequences to form the new string.
Though while merging the two subsequences you can not change the relative order of individual subsequences. What this means is - suppose there two characters Ai and Aj in the subsequence chosen from A , where i < j , then after merging if i acquires position k and j acquires p then k<p should be true and the same apply for subsequence from C.
Given string A , B , C can you count the number of ways to form string C from the two strings A and B by the method described above. Two ways are different if any of the chosen subsequence is different .
As the answer could be large so return it after modulo 10^9+7 .
Input Format :

Line 1 : String A
Line 2 : String B
Line 3 : String C

Output Format :

The number of ways to form string C

Constraints :
1 <= |A|, |B|, |C| <= 50
Sample Input :

abc
abc 
abc

Sample Output :

8


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll solver(string a,string b,string c,ll x,ll y,ll z,ll ***dp)
{
    ll ans=0;
    if(z==0)
    return 1;
    if(x==0 && y==0)// && z>=0)
    {
        return 0;
    }

    if(dp[x][y][z]!=-1)
    return dp[x][y][z];
    ll ans1=0;
    ll ans2=0;
    for(ll i=x;i>0;i--)
    {
        if(a[i-1]==c[z-1])
        {
            // cout<<"a"<<endl;
        ans1=(ans1%MOD+solver(a,b,c,i-1,y,z-1,dp)%MOD)%MOD;
        }
    }
    for(ll i=y;i>0;i--)
    {
        if(b[i-1]==c[z-1])
        {
        ans2=(ans2%MOD+solver(a,b,c,x,i-1,z-1,dp)%MOD)%MOD;
         // cout<<"a"<<endl;
        }
    }
    ans=(ans1+ans2)%MOD;
    // cout<<ans<<endl;
    dp[x][y][z]=ans;
    return ans;
}
int solve(string a,string b,string c)
{
	ll ***dp=new ll**[a.size()+1];
    for(ll i=0;i<=a.size();i++)
    {
        dp[i]=new ll*[b.size()+1];
        for(ll j=0;j<=b.size();j++)
        {
            dp[i][j]=new ll[c.size()+1];
            for(ll k=0;k<=c.size();k++)
            dp[i][j][k]=-1;
        }
    }
    return solver(a,b,c,a.size(),b.size(),c.size(),dp);

}
int main()
{
	string a,b,c;
	cin>>a>>b>>c;
	cout<<solve(a,b,c)<<endl;
}
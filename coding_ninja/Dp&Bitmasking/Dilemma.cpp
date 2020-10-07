/*
 Dilemma
Send Feedback
Abhishek, a blind man recently bought N binary strings all of equal length .A binary
 string only contains '0's and '1's . The strings are numbered from 1 to N and all are distinct,
  but Abhishek can only differentiate between these strings by touching them. In one touch Abhishek
   can identify one character at a position of a string from the set. Find the minimum number of touches 
   T Abhishek has to make so that he learn that all strings are different .
Constraints :
2<=N<=10
1<=|L|<=100 , L is length of the strings .
Input Format:

Line 1 : An Integer N, denoting the number of binary strings .
Next N lines : strings of equal length

Output Format:

Return the minimum number of touches

Sample Input :

2
111010
100100

Sample Output :

2


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll find_touches(ll pos,vector<string> &v,ll mask,ll **dp)
{
    if((mask & mask-1)==0)
    return 0;
    if(pos<0)
        return 20000;
    if(dp[pos][mask]!=INT_MAX)
    return dp[pos][mask];
    ll newmask1=0,newmask2=0,touches=0;
    for(ll i=0;i<v.size();i++)
    {
        
        if(mask & 1<<i)
        {
            touches++;
            if(v[i][pos]=='0')
            {
                newmask1 |=1<<i;
            }
            else
            {
                newmask2 |=1<<i;
            }
            
        }
        
    } 
    ll ans1=find_touches(pos-1,v,newmask1,dp)+find_touches(pos-1,v,newmask2,dp)+touches;
    ll ans2=find_touches(pos-1,v,mask,dp);
    ll ans=min(ans1,ans2);
    dp[pos][mask]=ans;
    return ans;
}
int minimumTouchesRequired(int n, vector<string> v) {
    /* Don't write main().
     * Don't read input, they are passed as function arguments.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    ll **dp=new ll*[v[0].size()+1];
    for(ll i=0;i<=v[0].size();i++)
    {
        dp[i]=new ll[1<<(n+1)];
        for(ll j=0;j< 1<<(n+1);j++)
        dp[i][j]=INT_MAX;
    }    
    return find_touches(v[0].size()-1,v,(1<<n)-1,dp);
}


int main() {
    int n;
    
    vector<string> v;
    
	cin >> n;
	for(int i = 0; i < n; i++) {
		string a;
		cin >> a;
		v.push_back(a);
	}
	cout << minimumTouchesRequired(n, v) << endl;
}
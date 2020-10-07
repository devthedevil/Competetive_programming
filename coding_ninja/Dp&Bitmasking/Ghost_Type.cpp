/*
 Ghost Type
Send Feedback
Gengar has got an integer N. Now using his ghostly powers, he can create the permutation from 1 to N of this given number.
Since, he's a special kind of Poke'mon, so he thinks he deserves special permutations. He wants to find the total number of
 special permutations of length N, consisting of the integers from 1 to N

.
A permutation is called special if it satisfies following condition:

If Ap & Aq == Ap, then p < q, where p and q are two distinct indices of permutation and A is the permutation itself. 
"&" denotes the bitwise and operation.

Help Gengar in finding the number of such permutations.
Input format:

The only line of input will consist of a single integer N denoting the length of the permutation.

Output format:

Output the total number of special permutations of length N

.
Constraints:

1 ≤ N ≤ 20
SAMPLE INPUT

4
SAMPLE OUTPUT

8
Explanation

All the special permutations of length 4 are: 1 2 3 4

1 2 4 3

1 4 2 3

2 1 3 4

2 1 4 3

2 4 1 3

4 1 2 3

4 2 1 3

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007

ll assign(ll n,ll mask,ll *dp)
{

    
    if(mask==(1<<n)-1)
    {
        // cout<<mask<<" mask "<<endl;
    return 1;
    }
    if(dp[mask]!=INT_MAX)
    {
        // cout<<dp[mask]<<" dp[mask] "<<mask<<" mask "<<endl;
    return dp[mask];
    }
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        if(!(mask & (1<<i) ))
        {
            bool flag=true;
    		for(ll j=0;j<n;j++)
    		{
                 int num = (i + 1)&(j + 1);
        		if((mask & (1<<j)) && num == (i + 1))
        		    flag=false;
        		
    		}
            if(flag)
                ans+=assign(n,mask | (1<<i),dp); 
                
        }
    }
    dp[mask]=ans;
    // cout<<mask<<" mask "<<ans<<" ans "<<endl;
    return ans;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll *dp=new ll[1<<n];
    for(ll i=0;i<(1<<n);i++)
    dp[i]=INT_MAX;
    cout<<assign(n,0,dp)<<endl;

}

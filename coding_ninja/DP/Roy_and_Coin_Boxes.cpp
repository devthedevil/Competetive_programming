/*
 Roy and Coin Boxes
Send Feedback

Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.

Input

First line contains N - number of coin boxes.
Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by
 integer Q - number of queries.
Each of next Q lines contain a single integer X.a

Output

For each query output the result in a new line.

Constraints

1 ≤ N ≤ 1000000

1 ≤ M ≤ 1000000

1 ≤ L ≤ R ≤ N

1 ≤ Q ≤ 1000000

1 ≤ X ≤ N

Sample Input

7
4
1 3
2 5
1 2
5 6
4
1
7
4
2

Sample Output

6
0
0
4


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
      cin.tie(NULL);
    ll m,n,a,b;
    cin>>n>>m;
    ll *s=new ll[n]();
    ll *e=new ll[n]();
    for(ll i=0;i<m;i++)
    {
    	cin>>a>>b;
        a--;
        b--;
    	s[a]++;
    	e[b]++;
    }
    ll *dp=new ll[n];
    dp[0]=s[0];
    for(ll i=1;i<n;i++)
    dp[i]=s[i]-e[i-1]+dp[i-1];
    map<ll,ll> ma;
    for(ll i=0;i<n;i++)
    {
        ma[dp[i]]++;
    }
    ll *ans=new ll[n+1];
    for(ll i=0;i<n+1;i++)
        ans[i]=0;
        for(auto it:ma)
        {
            a=it.first;
            ans[a]=it.second;
        }
    for(ll j=n-1;j>=0;j--)
    ans[j]+=ans[j+1];
    ll q,x;
    cin>>q;
    while(q--)
    {
        cin>>x;
        cout<<ans[x]<<endl;
    }

	delete [] ans;
    delete [] s;
    delete [] e;
    delete [] dp;

}
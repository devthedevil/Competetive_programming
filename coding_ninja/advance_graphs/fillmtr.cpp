/*
Fill The Matrix

A matrix B (consisting of integers) of dimension N × N is said to be good if there exists an array A (consisting of integers) 
such that B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value of integer x.

You are given a partially filled matrix B of dimension N × N. Q of the entries of this matrix are filled by either 0 or 1. 
You have to identify whether it is possible to fill the remaining entries of matrix B (the entries can be filled by any integer,
 not necessarily by 0 or 1) such that the resulting fully filled matrix B is good.

Input

The first line of the input contains an integer T denoting the number of test cases.

The first line of each test case contains two space separated integers N, Q.

Each of the next Q lines contain three space separated integers i, j, val, which means that B[i][j] is filled with value val.

Output

For each test case, output "yes" or "no" (without quotes) in a single line corresponding to the answer of the problem.

Constraints

1 ≤ T ≤ 10^6
2 ≤ N ≤ 10^5
1 ≤ Q ≤ 10^6
1 ≤ i, j ≤ N
0 ≤ val ≤ 1
Sum of each of N, Q over all test cases doesn't exceed 106

Input

4
2 2
1 1 0
1 2 1
2 3
1 1 0
1 2 1
2 1 0
3 2
2 2 0
2 3 1
3 3
1 2 1
2 3 1
1 3 1

Output

yes
no
yes
no


*/
#include<bits/stdc++.h>
// #define ll long long;
typedef long long int ll;
using namespace std;
ll getparent(ll *parent,ll index)
{
    while(index!=parent[index])
    index=parent[index]=parent[parent[index]];
    return index;
}

void merge( ll *parent,ll *rank,ll i,ll j )
{
    ll u=getparent(parent,i);
    ll v=getparent(parent,j);

    if(rank[u]>=rank[v])
    parent[v]=u;
    else
    parent[u]=v;
    
    if(rank[u]==rank[v])
    rank[u]++;
}
bool dfs(ll i,set<ll> *g,bool *visited,bool *starting,bool *labelarr,bool currlabel)
{
    visited[i]=starting[i]=true;
    labelarr[i]=currlabel;
   // cout<<i<<" "<<labelarr[i]<<" "<<currlabel<<endl;
    for(auto  it : g[i])
    {
		if(visited[it] )
        {
			if( starting[i] && !(labelarr[it]^currlabel))
            return true;
        }
        else
        {
            if(dfs(it,g,visited,starting,labelarr,!currlabel))
            return true;
        }

		       
    }
    starting[i]=false;
    return false;
}
bool oddcycle(set<ll> *g,ll n)
{
    bool visited[n]={false},starting[n]={false},labelarr[n]={false};
    for(ll i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(dfs(i,g,visited,starting,labelarr,false))
            return true;
        }        
    }
    return false;
    
}
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q,a,b,c,sz=0;
        cin>>n>>q;
        set<ll> g[n];
        ll *parent=new ll[n];
        ll *rank=new ll[n];
        for(ll i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
        pair<ll,ll> arr[n];

        for(ll i=0; i<q;i++ )
        {
            cin>>a>>b>>c;
            a--;b--;
            if(c==0)
            {
                merge(parent,rank,a,b);
            }
            else
            {
                arr[sz++]={a,b};
            }
        }
        ll j;
        for( j=0;j<sz;j++)
        {
            ll x=getparent(parent,arr[j].first);
            ll y=getparent(parent,arr[j].second);
            if(x==y)
            {
                break;
            }
            g[x].insert(y);
            g[y].insert(x);
        }
       // cout<<oddcycle(g,n)<<endl;
        if(j<sz || oddcycle(g,n))
        cout<<"no"<<endl;
        else
        cout<<"yes"<<endl;
        
        

    }
   
}

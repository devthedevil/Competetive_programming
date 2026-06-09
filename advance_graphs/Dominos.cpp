/*
Domino

Dominos are lots of fun. Children like to stand the tiles on their side in long lines.
 When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line.
However, sometimes a domino fails to knock the next one down. In that case, we have to
 knock it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, the minimum number of dominos 
that must be knocked down by hand in order for all of the dominos to fall.

Input

The first line of input contains one integer specifying the number of test cases to follow.Each test case begins with 
a line containing two integers,each no larger than 100 000. The first integer n is the number of domino tiles and the
 second integer m is the number of lines to follow in the test case. The domino tiles are numbered from 1 to n.
Each of the following lines contains two integers x and y indicating that if domino number x falls, it will cause
 domino number y to fall as well.

Output

For each test case, output a line containing one integer, the minimum number of dominos that must be knocked
 over by hand in order for all the dominos to fall.

Sample Input

1
3 2
1 2
2 3

Sample Output

1


*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void dfs(vector<ll> *edge,ll start,bool *visited,stack <ll> &finishstack)
{
    visited[start]=true;
    for(ll i=0;i<edge[start].size();i++)
    {
        ll next=edge[start][i];
        if(!visited[next])
        {
            dfs(edge,next,visited,finishstack);
        }
    }
    finishstack.push(start);
}
void dfs2(vector<ll> *edgeT,ll start,bool*visited)
{
    visited[start]=true;
    for(ll i=0;i<edgeT[start].size();i++)
    {
        ll next=edgeT[start][i];
        if(!visited[next])
        {
        	dfs2(edgeT,next,visited);
        }
    }
}
ll getSCC(vector<ll> *edge,ll n)
{
    ll count=0;
    bool *Visited = new bool[n];
    for(int i = 0; i < n; i++) Visited[i] = false;
    stack <ll> finishedvertices;
    for(ll i=0;i<n;i++)
    {
        if(!Visited[i])
        {
            dfs(edge,i,Visited,finishedvertices);
        }
    }
      for(int i = 0; i < n; i++) Visited[i] = false;
    while(finishedvertices.size()!=0)
    {
        ll i=finishedvertices.top();
        finishedvertices.pop();

        if(!Visited[i])
        {
			dfs2(edge,i,Visited);
        	count++;
        }
    }
    return count;
}
int main()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    ll n,m,a,b;
    cin>>n>>m;
    vector<ll>* edge=new vector<ll>[n];
    for(ll i=0;i<m;i++)
    {
        cin>>a>>b;
        edge[a-1].push_back(b-1);
    }

    cout<<getSCC(edge,n)<<endl;
    delete [] edge;
    }
}
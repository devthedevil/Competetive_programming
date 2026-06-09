/*
We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes).
 Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.

Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1).
 Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).

Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. 
The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.

Input Specification

The input contains several test cases, each of which corresponds to a directed graph G. Each test case starts with an integer number v, denoting the number of
 vertices of G=(V,E) where the vertices will be identified by the integer numbers in the set V={1,…,v}. You may assume that 1≤v≤5000. That is followed by a 
 non-negative integer e and, thereafter, e pairs of vertex identifiers v1,w1,…,ve,we with the meaning that (vi,wi)∈E. There are no edges other than specified by
  these pairs. The last test case is followed by a zero.

Output Specification

For each test case output the bottom of the specified graph on a single line. To this end, print the numbers of all nodes that are sinks in sorted order 
separated by a single space character. If the bottom is empty, print an empty line.

Sample Input

3 3
1 3 2 3 3 1
2 1
1 2
0

Sample Output

1 3
2


*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


void dfs(vector<ll> *edge,ll start,unordered_set<ll> &visited,stack <ll> &finishstack)
{
    visited.insert(start);
    for(ll i=0;i<edge[start].size();i++)
    {
        ll next=edge[start][i];
        if(visited.count(next)==0)
        {
            
            dfs(edge,next,visited,finishstack);
            
        }
    }
    finishstack.push(start);
}
void dfs2(vector<ll> *edgeT,ll start,unordered_set<ll> &visited,unordered_set<ll> *component)
{
     component->insert(start);
    visited.insert(start);
    for(ll i=0;i<edgeT[start].size();i++)
    {
        ll next=edgeT[start][i];
        if(visited.count(next)==0)
        {
        dfs2(edgeT,next,visited,component);
        }
    }
}
unordered_set<unordered_set<ll>*>* getSCC(vector<ll> *edge,vector<ll> *edgeT,ll n)
{
    unordered_set<ll> visited;
    stack <ll> finishedvertices;
    for(ll i=0;i<n;i++)
    {
        if(visited.count(i)==0)
        {
            dfs(edge,i,visited,finishedvertices);
        }
    }
    unordered_set<unordered_set<ll>*>* output=new unordered_set<unordered_set<ll>*>();
    visited.clear();
    while(finishedvertices.size()!=0)
    {
        ll i=finishedvertices.top();
        finishedvertices.pop();

        if(visited.count(i)!=0)
        continue;

        unordered_set<ll>* component=new unordered_set<ll>();
           
        dfs2(edgeT,i,visited,component);
        output->insert(component);
       // delete component;
    }
    return output;
}
int main()
{
    while(1)
    {
    ll n,m,a,b;
    cin>>a;
    if(a==0) break;
        n=a;
    cin>>m;
    ll **edges=new ll*[n];
    for(ll i=0;i<n;i++)
    {
        edges[i]=new ll[n];
        for(ll j=0;j<n;j++)
            edges[i][j]=0;
    }
    
    vector<ll>* edge=new vector<ll>[n];
    vector<ll>* edgeT=new vector<ll>[n];
    for(ll i=0;i<m;i++)
    {
        cin>>a>>b;
        edge[a-1].push_back(b-1);
        edges[a-1][b-1]=1;
        edgeT[b-1].push_back(a-1);
    }
    
        
    ll flag=0;
    unordered_set<unordered_set<ll>*>* component=getSCC(edge,edgeT,n);
    unordered_set<unordered_set<ll>*> :: iterator it;
    vector<ll> out;
    for(it=component->begin();it!=component->end();it++)
    {
        flag=0;
        unordered_set<ll>* set=*it;
        std::set<ll> ::iterator it1;
        std::set<ll> ordered(set->begin(), set->end());
        
        for(it1=ordered.begin();it1!=ordered.end();it1++)
        {
         //  cout<<*it1+1<<" ";
            for(ll i=0;i<n;i++)
            {
                if(edges[*it1][i]==1 && ordered.find(i)==ordered.end())
                {
                    flag=1;
                    break;
                }
            }

        }
        if(flag==0)
        {
        for(it1=ordered.begin();it1!=ordered.end();it1++)
                {
                    out.push_back(*it1+1);
                }                
        }
       
        delete set;
    }
    sort(out.begin(),out.end());
        for(ll i=0;i<out.size();i++)
            cout<<out[i]<<" ";
        cout<<endl;
     //  cout<<component->size()<<endl;
    delete [] edge;
    delete [] edgeT;
    delete component;
    }
    
}
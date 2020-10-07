/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -

v1 v2 w

where, v1 and v2 are the vertices of the edge which is included in MST and whose weight 
is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :

Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between 
vertex ei and vertex ej with weight wi (separated by space)

Output Format :

MST

Constraints :
2 <= V, E <= 10^5
Sample Input 1 :

4 4
0 1 3
0 3 5
1 2 1
2 3 8

Sample Output 1 :

0 1 3
1 2 1
0 3 5


*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int ,int> ipair ;
int main() 
{
    int v,e;
    cin>>v>>e;
    vector<ipair> adj[v];
    int src,des,weigh;
    for(int i=0;i<e;i++)
    {
        cin>>src>>des>>weigh;
        adj[src].push_back(make_pair(des,weigh));
        adj[des].push_back(make_pair(src,weigh));

    }
    vector<bool> visited(v,false);
    vector<int> weight(v,INT_MAX);
    vector<int> parent(v,-1);
    priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
    src=0;
    pq.push(make_pair(0,src));
    weight[src]=0;

    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        visited[u]=true;
        weigh=weight[u];
        vector<ipair>::iterator i;
        for( i=adj[u].begin();i!=adj[u].end();i++)
        {
            if(visited[(*i).first]==false && (*i).second!=0 && weight[(*i).first]>=(*i).second )
            {
                parent[(*i).first]=u;
                weight[(*i).first]=(*i).second;
            //    cout<<weight[(*i).second]<<" "<<(*i).first<<" "<<endl;
                pq.push(make_pair(weight[(*i).first],(*i).first));
            }
        }
    }
    for(int i=1;i<v;i++)
    {
        if(i<parent[i])
        cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        else
        {

        cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        
    }
}

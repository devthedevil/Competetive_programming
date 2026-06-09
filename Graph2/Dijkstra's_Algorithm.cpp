/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :

Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

Output Format :

In different lines, ith vertex number and its distance from source (separated by space)

Constraints :
2 <= V, E <= 10^5
Sample Input 1 :

4 4
0 1 3
0 3 5
1 2 1
2 3 8

Sample Output 1 :

0 0
1 3
2 4
3 5


*/
#include <iostream>
using namespace std;
#include<bits/stdc++.h>
typedef pair<int,int> ipair;

int main()
{
    int v,e;
    cin >> v >> e;
    vector<ipair> adj[v];
    int src,des,weigh;
    for(int i=0;i<e;i++)
    {
        cin>>src>>des>>weigh;
        adj[src].push_back(make_pair(des,weigh));
        adj[des].push_back(make_pair(src,weigh));
    }
    priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
    vector<bool> visited(v,false);
    vector<int> weight(v,INT_MAX);
    weight[0]=0;
    src=0;
    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        visited[u]=true;
        for(auto i:adj[u])
        {
            if(visited[i.first]==false && (i.second!=0) && weight[i.first]>i.second+weight[u])
            {
              
                weight[i.first]=i.second+weight[u];
                pq.push(make_pair(weight[i.first],i.first));
            }
        }
    }
    for(int i=0;i<v;i++)
        cout<<i<<" "<<weight[i]<<endl;
}

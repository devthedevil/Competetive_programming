/*
Given an undirected and connected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note : 1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Input Format :

Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.

Output Format :

BFS Traversal (separated by space)

Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:

4 4
0 1
0 3
1 2
2 3

Sample Output 1:

0 1 3 2

 
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,e;
    cin>>n>>e;
    int **edge=new int* [n];
    int* visited=new int[n];
      for(int i=0;i<n;i++)
      visited[i]=0;
    for(int i=0;i<n;i++)
    {
        edge[i]=new int [n];
        for(int j=0;j<n;j++)
        edge[i][j]=0;
    }
    for(int i=0;i<e;i++)
    {
        int s,f;
        cin>>s>>f;
        edge[s][f]=1;
        edge[f][s]=1;
    }

    queue <int> q;
    //bool visited[n];
    for(int i=0;i<n;i++)
    visited[i]=0;

    for(int i=0;i<n;i++)
    {
        if( visited[i]==0)
        {
        q.push(i);
        visited[i]=1;
        while(!q.empty())
        {
            a=q.front();
            q.pop();
            
            cout<<a<<" ";
            for(int j=0;j<n;j++)
            {
                if(edge[a][j]==1 && visited[j]==0)
                {
             //   cout<<j<<" j";
                visited[j]=1;
                q.push(j);
                }
            }
         //   cout<<endl;
        }
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     cout<<i<<" ";
    //     for(int j=0;j<n;j++)
    //         if(edge[i][j]==1)
    //             cout<<j<<" ";
    // cout<<endl;
    // }
    
}
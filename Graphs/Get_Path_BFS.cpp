/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :

Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)

Output Format :

Path from v1 to v2 in reverse order (separated by space)

Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :

4 4
0 1
0 3
1 2
2 3
1 3

Sample Output 1 :

3 0 1

*/
#include<bits/stdc++.h>
using namespace std;
void print(map <int,int> &fig,int d,int s)
{
    cout<<d<<" ";
    while(fig[d]!=s)
    {
        cout<<fig[d]<<" ";
        d=fig[d];
    }
    cout<<s;
    cout<<endl;
    return;
}
int main()
{
    int n,s,e,d,a;
    cin>>n>>e;
    int **edge=new int* [n];
    int *visited=new int[n];
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
        int c,b;
        cin>>c>>b;
        edge[c][b]=1;
        edge[b][c]=1;
    }
    cin>>s>>d;

    queue <int> q;
    //bool visited[n];
    for(int i=0;i<n;i++)
    visited[i]=0;

 map<int,int> fig;
        q.push(s);
        visited[s]=1;
        while(!q.empty())
        {
            
            a=q.front();
             q.pop();
            if(a==d)
            {
                print(fig,d,s);
                break;
                
            }
           
            
           // cout<<a<<" ";
            for(int j=0;j<n;j++)
            {
                if(edge[a][j]==1 && visited[j]==0)
                {
             //   cout<<j<<" j";
                fig[j]=a;
                visited[j]=1;
                q.push(j);
                
                }
            }
          
         //   cout<<endl;
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
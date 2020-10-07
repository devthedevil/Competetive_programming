/*
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :

Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', 
denoting that there exists an edge between Vertex 'a' and Vertex 'b'.

Output Format :

"true" or "false"

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

true

*/
#include<bits/stdc++.h>
using namespace std;

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


    queue <int> q;
    //bool visited[n];
    for(int i=0;i<n;i++)
    visited[i]=0;


        q.push(0);
        visited[0]=1;
        while(!q.empty())
        {
            
            a=q.front();
             q.pop();
         
           
            
           // cout<<a<<" ";
            for(int j=0;j<n;j++)
            {
                if(edge[a][j]==1 && visited[j]==0)
                {
             //   cout<<j<<" j";
                //fig[j]=a;
                visited[j]=1;
                q.push(j);
                
                }
            }
          
         //   cout<<endl;
         }
        int flag=0;
    int i;
for(i=0;i<n;i++)
{
    if(visited[i]==0)
    {
        cout<<"false"<<endl;
        break;
    }
    //exit (0);
    
}
    if(i==n)
    cout<<"true"<<endl;
    
    
}
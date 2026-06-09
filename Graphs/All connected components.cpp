/*
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :

Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.

Output Format :

Different components in new line

Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:

4 2
0 1
2 3

Sample Output 1:

0 1 
2 3 

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
        vector<int> vec;
        if( visited[i]==0)
        {
        q.push(i);
        visited[i]=1;
            vec.push_back(i);
        while(!q.empty())
        {
            a=q.front();
            q.pop();
            
          //  cout<<a<<" ";
            for(int j=0;j<n;j++)
            {
                if(edge[a][j]==1 && visited[j]==0)
                {
             //   cout<<j<<" j";
                visited[j]=1;
                q.push(j);
                    vec.push_back(j);
                }
            }

                
         //   cout<<endl;
        }
            sort(vec.begin(),vec.end());
            for(int k=0;k<vec.size();k++)
            cout<<vec[k]<<" ";
            cout<<endl;
            vec.resize(0);
            
        }
    }

    
}
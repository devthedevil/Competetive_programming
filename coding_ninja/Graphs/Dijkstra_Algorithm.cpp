#include<bits/stdc++.h>
using namespace std;
void dijktra(int **edge,int n)
{
    
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
        int c,b,w;
        cin>>c>>b>>w;
        edge[c][b]=w;
        edge[b][c]=w;
    }
    dijktra(edge,n);
}
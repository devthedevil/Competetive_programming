#include<bits/stdc++.h>
using namespace std;
void print(int **edge,int *visited,int n,int sv)
{
cout<<sv<<endl;
 visited[sv]=1;
for(int i=0;i<n;i++)
    if(edge[sv][i]==1 && visited[i]==0)
    print(edge,visited,n,i);
    

}
int main()
{
    int n,e;
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
    print(edge,visited,n,0);
    delete [] visited;
    for(int i=0;i<n;i++)
    delete [] edge[i];
    delete [] edge;
}
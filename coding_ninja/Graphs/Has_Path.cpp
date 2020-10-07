/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. 
Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :

Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)

Output Format :

true or false

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

true

*/
#include <iostream>
using namespace std;
bool dfs(int **edge,int* visited,int n,int s,int d)
{
    
    if(s==d )
    return true;
    else
    {
        visited[s]=1;
        for(int i=0;i<n;i++)
        { //cout<<i<<endl;
    //     cout<<edge[s][i]<<endl;
            if(visited[i]==0 && edge[s][i]==1)
            {
                //cout<<"s"<<endl;
                 visited[i]=1;   
                if( dfs(edge,visited,n,i,d))
                    return true;

            }
        }
      return false;
    }
}
int main() 
{
    int n, e, a , b,s,d;
    cin >> n >> e;
    int **edge=new int*[n];
    int *visited=new int[n];
    for(int i=0;i<n;i++)
    {
        edge[i]=new int[n];
        for(int j=0;j<n;j++)
            edge[i][j]=0;
    }
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        edge[b][a]=1;
        edge[a][b]=1;
        
       // cout<<edge[a][b]<<endl;
    }
    cin>>s>>d;
    for(int i=0;i<n;i++)
        visited[i]=0;
    if(dfs(edge,visited,n,s,d))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    
}

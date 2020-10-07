#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class vertex
{
    public:
    int visited;
    int parent;
    int weight;
};
int main() 
{
    int v,e;
    cin>>v>>e;
    int **edge=new int*[v];
    for(int i=0;i<v;i++)
    {
        edge[i]=new int[v];
        for(int j=0;j<v;j++)
        {
            edge[i][j]=-1;
        }
    }
    int src,des,weigh;
    for(int i=0;i<e;i++)
    {
        cin>>src>>des>>weigh;
        edge[src][des]=weigh;
        edge[des][src]=weigh;
    }
    vertex *V=new int[v];
    for(int i=0;i<v;i++)
    {
        V[i].visited=0;
        V[i].parent=-1;
        V[i].weight=INT_MAX;
    }
    V[0].weight=0;
    
    priority_queue(int,vector<int>,greater<int>) pq;
    for(int i=0;i<n;i++)
        pq.push(V[i].weight);
    for(int i=0;i<n;i++)
    {
        
    }
    for(int i=0;i<v;i++)
        delete [] edge[i];
    delete [] edge;
        
    
        

}

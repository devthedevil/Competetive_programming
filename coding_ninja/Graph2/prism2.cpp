#include <bits/stdc++.h>
using namespace std;
int getmin(bool *visited,int *weight,int n){
    int ans=-1;
    for(int i=0;i<n;i++){
       if(!visited[i]&&(ans==-1||weight[ans]>weight[i])){
           ans=i;
       }
    }
    return ans;
}
void prims(int **edges, int n){
    bool *visited=new bool[n]();
    int *parent=new int[n];
    int *weight=new int[n];
    for(int i=1;i<n;i++){
        weight[i]=INT_MAX;
    }
    parent[0]=-1;
    weight[0]=0;
    for(int i=0;i<(n-1);i++){
        int curmin=getmin(visited,weight,n);
        visited[curmin]=true;
        for(int j=0;j<n;j++){
            if(edges[curmin][j]!=0&&!visited[j]){
                if(weight[j]>edges[curmin][j]){
                    weight[j]=edges[curmin][j];
                    parent[j]=curmin;
                }
            }
        }
        // for(int i=1;i<n;i++){
        //     cout<<parent[i]<<" ";
        // }
        // cout<<'\n';
        // for(int i=1;i<n;i++){
        //     cout<<visited[i]<<" ";
        // }
        // cout<<'\n';
        // for(int i=1;i<n;i++){
        //     cout<<weight[i]<<" ";
        // }
        // cout<<'\n'<<'\n';
        
    }
    for(int i=1;i<n;i++){
        if(parent[i]<i){
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<'\n';
        }
        else{
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<'\n';
        }
    }
    delete[] parent;
    delete[] weight;
    delete[] visited;
}
int main()
{
  int n, e, tempX, tempY;
  cin >> n >> e;

  /*Write Your Code Here
  Complete the Rest of the Program
  You have to Print the output yourself*/
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n]();
    }
    for(int i=0;i<e;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edges[a][b]=edges[b][a]=w;
    }
    prims(edges,n);
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
    
  return 0;
}

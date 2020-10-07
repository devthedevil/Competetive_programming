/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), 
find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
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

*/
/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), 
find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
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

*/
#include<bits/stdc++.h>
using namespace std;
void print(vector <int> stack)
{
    //cout<<stack.size()<<endl;
    for(int i=stack.size()-1;i>=0;i--)
        cout<<stack[i]<<" ";
    cout<<endl;
}
void dfs(int **edge,int* visited,int n,int s,int d,vector<int> stack )
{
    //cout<<"start"<<endl;
    stack.push_back(s);
    //cout<<s<<"s"<<endl;
    if(s==d)
    {
     
        print(stack);
        return;
        
    }
    else
    {
        visited[s]=1;
        int flag=0;
        
       
        for(int i=0;i<n;i++)
        { //cout<<i<<"i"<<endl;
            
    //     cout<<edge[s][i]<<endl;
            if(visited[i]==0 && edge[s][i]==1)
            {
            //    cout<<"s"<<endl;
                 visited[i]=1;
               // stack.push_back(i);
                 dfs(edge,visited,n,i,d,stack);
                
                    flag=1;

            }
           
        }
         if(flag==1)
         {
                stack.pop_back();
           //  cout<<"pop"<<endl;
         }
      
    }
}
int main() 
{
    int n, e, a , b,s,d;
    cin >> n >> e;
    int **edge=new int*[n];
    int *visited=new int[n];
   //  vector<int> stack;
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
   // cout<<s<<" "<<d<<endl;
    for(int i=0;i<n;i++)
        visited[i]=0;
    vector<int> stack;
    dfs(edge,visited,n,s,d,stack);
     //   print(stack);

    
}

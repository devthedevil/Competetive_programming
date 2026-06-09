/*
You all must be familiar with the chess-board having 
8*8 squares of alternate black and white cells. Well, here 
we have for you a similar 
N*M size board with similar arrangement of black and white 
cells.
A few of these cells have Horses placed over them. 
Each horse is unique. Now these horses are not the 
usual horses which could jump to any of the 
8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can    
 go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, 
calculate answer. Sincethis answer may be quite large, calculate in modulo 
10^9+7

Input:

First line contains 
T which is the number of test cases.
T test cases follow first line of each containing three integers 
N, M and Q where 
N,M is the size of the board and 
Q is the number of horses on it.

Q lines follow each containing the 2 integers 
X and Y which are the coordinates of the Horses.

Output:

For each test case, output the number of photographs taken by photographer.

Constraints:

 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M

SAMPLE INPUT

2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4

SAMPLE OUTPUT

4
2


*/

#include <bits/stdc++.h>
using namespace std;
#define div 1000000007
void dfs(int v1,int v2,int **edge,bool **visited,int n,int m,vector<int> &answer,int count)
{
    visited[v1][v2]=true;
    answer[count]++;
    if(v1>1 && v2>0 && !visited[v1-2][v2-1] && edge[v1-2][v2-1]==1)
    {
        dfs(v1-2,v2-1,edge,visited,n,m,answer,count);
    }
    if(v1>1 && v2<m-1 && !visited[v1-2][v2+1] && edge[v1-2][v2+1]==1)
    {
        dfs(v1-2,v2+1,edge,visited,n,m,answer,count);
    }
    if(v1>0 && v2>1 && !visited[v1-1][v2-2] && edge[v1-1][v2-2]==1)
    {
        dfs(v1-1,v2-2,edge,visited,n,m,answer,count);
    }
    if(v1<n-1 && v2>1 && !visited[v1+1][v2-2] && edge[v1+1][v2-2]==1)
    {
        dfs(v1+1,v2-2,edge,visited,n,m,answer,count);
    }
    if(v1<n-2 && v2>0 && !visited[v1+2][v2-1] && edge[v1+2][v2-1]==1)
    {
        dfs(v1+2,v2-1,edge,visited,n,m,answer,count);
    }
    if(v1<n-2 && v2<m-1 && !visited[v1+2][v2+1] && edge[v1+2][v2+1]==1)
    {
        dfs(v1+2,v2+1,edge,visited,n,m,answer,count);
    }
    if(v1>0 && v2<m-2 && !visited[v1-1][v2+2] && edge[v1-1][v2+2]==1)
    {
        dfs(v1-1,v2+2,edge,visited,n,m,answer,count);
    }
    if(v1<n-1 && v2<m-2 && !visited[v1+1][v2+2] && edge[v1+1][v2+2]==1)
    {
        dfs(v1+1,v2+2,edge,visited,n,m,answer,count);
    }

    
}
vector<int> connectedcomponent(int **edge,int n,int m)
{
    bool** visited=new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new bool[m];
        for(int j=0;j<m;j++)
        visited[i][j]=false;

    }
    vector <int> answer;
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visited[i][j] && edge[i][j]==1)
            {
                answer.push_back(0);
                dfs(i,j,edge,visited,n,m,answer,count);
                count++;
            }
        }
    }
    delete [] visited;
    return answer;
}
int main()
{
    int n,m,e,a,b,t,q;
   
    cin>>t;
    while(t--)
    { long long int ans=1;
        cin>>n>>m>>q;
        int** edge=new int*[n];
        for(int i=0;i<n;i++)
        {
            edge[i]=new int[m];
            for(int j=0;j<m;j++)
            edge[i][j]=0;
        }
    for(int i=0;i<q;i++)
    {
        cin>>a>>b;
        edge[a-1][b-1]=1;
    }

    vector<int> output= connectedcomponent(edge,n,m);
    vector<int> ::iterator it;
    for(int k=0;k<output.size();k++)
    {
       long long int ansi=1;
       for(int i=output[k];i>0;i--)
        {
           ansi=ansi*i;
           ansi=ansi%div; 
        }
        ans=ans*ansi;
        ans%=div;
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++)
    delete [] edge[i];
    delete edge;
    
    }

}

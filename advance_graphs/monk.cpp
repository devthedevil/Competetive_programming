/*
MONK AND THE ISLAND

Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each 
other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach 
the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.

Input:

First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.

Output:

Print the answer to each test case in a new line.

Constraints:

1 ≤ T ≤ 10
1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ X, Y ≤ N

SAMPLE INPUT

2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2

SAMPLE OUTPUT

2
2


*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int bfs(vector<int> *edge,int n)
{
    map<int,int> level;
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    visited[i]=false;
    queue <int> q;
    level[0]=0;
    q.push(0);
    visited[0]=true;
    while(q.size()!=0)
    {
        int v=q.front();
        q.pop();
             //   cout<<v<<"v"<<endl;
        for(int j=0;j<edge[v].size();j++)
        {
            int x=edge[v][j];
                       // cout<<edge[v][j]<<" edge "<<visited[x]<<endl;
            
            if(!visited[x])
            {
    			level[x]=level[v]+1;
                q.push(x);
                visited[x]=true;
                if(x==n-1)
                return level[n-1];
            }

        }
    }
        
    
    return level[n-1];
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        ll m;
        cin>>n>>m;
        // int **edge =new int*[n];
        // for(int i=0;i<n;i++)
        // {
        //     edge[i]=new int[n];
        //     for(int j=0;j<n;j++)
        //     edge[i][j]=0;
        // }
        vector<int>* edge=new vector<int>[n];
        int a,b;
        for(ll i=0;i<m;i++)
        {
            cin>>a>>b;
            edge[a-1].push_back(b-1);
            edge[b-1].push_back(a-1);
        }
       cout<<bfs(edge,n)<<endl;
        // for(int i=0;i<n;i++)
        // delete [] edge[i];
        // delete [] edge;
    }
    
}
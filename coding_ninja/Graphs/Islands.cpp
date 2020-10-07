/*
An island is a small piece of land surrounded by water . 
A group of islands is said to be connected if we can reach from any given island to any
 other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M
  (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number
   of connected groups of islands.
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Input Format :

Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M

Output Return Format :

The count the number of connected groups of islands

Sample Input :

2 1
1
2

Sample Output :

1 


*/
#include<bits/stdc++.h>
using namespace std;
int solve(int n,int m,vector<int>u,vector<int>v)
{
	
    
  int a;
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
    for(int i=0;i<m;i++)
    {
        edge[u[i]-1][v[i]-1]=1;
        edge[v[i]-1][u[i]-1]=1;
    }

    queue<int> q;
    int count=0;


    for(int i=0;i<n;i++)
    {
        
        if( visited[i]==0)
        {
           // cout<<i<<" "<<count<<endl;
            count++;
            q.push(i);
            visited[i]=1;
                while(!q.empty())
                    {
                        a=q.front();
                        q.pop();
            
                             for(int j=0;j<n;j++)
                                {
                                    if(edge[a][j]==1 && visited[j]==0)
                                        {
                                            visited[j]=1;
                                            q.push(j);
                
                                        }
                                }

                
         
                        }
          
            
            }
    }
return count;
    

}











int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}
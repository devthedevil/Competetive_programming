/*
Largest Piece
Send Feedback
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . 
But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which
 consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake
, can you find the size of the biggest piece of '1's for Gary ?
Constraints :
1<=N<=50
Input Format :

Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake

Output Format :

Size of the biggest piece of '1's and no '0's

Sample Input :

2
11
01

Sample Output :

3


*/
#include<iostream>
#include<vector>
using namespace std;
#define NMAX 55
char cake[NMAX][NMAX];

int dfs(int n,char cake[][NMAX],int **visited,int max,int a,int b)
{
    if(visited[a][b]==0)
    {
        visited[a][b]==1;
        
        if(a>0)
        max=dfs(n,cake,visited,max+1,a-1,b);
        if(b>0)
        max=dfs(n,cake,visited,max+1,a,b-1);
        if(a+1<n)
        max=+dfs(n,cake,visited,max+1,a+1,b);
        if(b+1<n)
        max=+dfs(n,cake,visited,max+1,a,b+1);
        
        return max;
    }
    return 0;
    
}
int solve(int n,char cake[NMAX][NMAX])
{
    int max=0,maxi,m=0;
    int **visited=new int*[n];
    for(int i=0;i<n;i++)
    {
      visited[i]=new int[n];
        for(int j=0;j<n;j++)
            visited[i][j]=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
             maxi=dfs(n,cake,visited,max,i,j);
            if(maxi>m)
            m=maxi;
            max=0;
        }
    }
    
    return m; 
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}
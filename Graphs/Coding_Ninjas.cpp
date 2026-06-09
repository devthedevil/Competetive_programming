/*
 Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :

Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on

Assume input to be 0-indexed based
Output Format :

Return 1 if there is a path which makes the sentence “CODINGNINJA” else return 0.

Constraints :
1 <= N <= 100
1 <= M <= 100
Sample Input :

2 11
CXDXNXNXNXA
XOXIXGXIXJX

Sample Output :

1


 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 102
bool dfs(int N,int M,char Graph[][102],bool** visited,string s,int i,int j,int k)
{
      bool ans = 0;
    if(s[k]=='\0')
    return 1;
    else
    {
        
        if((i-1)>=0 && (j-1)>=0 && Graph[i-1][j-1]== s[k] && !visited[i-1][j-1]) 
        {    
            visited[i-1][j-1]=true;
           ans |=  dfs(N,M,Graph,visited,s,i-1,j-1,k+1);
            visited[i-1][j-1]=false;
        }
        if( (i-1)>=0 && Graph[i-1][j]==s[k] && !visited[i-1][j] )
        {
            visited[i-1][j]=true;
          ans |=   dfs(N,M,Graph,visited,s,i-1,j,k+1);
            visited[i-1][j]=false;
        }
        if(  (i-1)>=0 && (j+1)<M  && Graph[i-1][j+1]==s[k]  && !visited[i-1][j+1])
        {
            visited[i-1][j+1]=true;
          ans |=   dfs(N,M,Graph,visited,s,i-1,j+1,k+1);
            visited[i-1][j+1]=false;
        }
        if(  (j-1)>=0 && Graph[i][j-1]==s[k] && !visited[i][j-1])
        {
            visited[i][j-1]=true;
           ans |=  dfs(N,M,Graph,visited,s,i,j-1,k+1);
            visited[i][j-1]=false;
        }
        if( (j+1)<M && Graph[i][j+1]==s[k] && !visited[i][j+1])
        {
            visited[i][j+1]=true;
          ans |=   dfs(N,M,Graph,visited,s,i,j+1,k+1);
            visited[i][j+1]=false;
        }
        if( (i+1)<N && (j-1)>=0 && Graph[i+1][j-1]==s[k] && !visited[i+1][j-1])
        {
            visited[i+1][j-1]=true;
        ans |=     dfs(N,M,Graph,visited,s,i+1,j-1,k+1);
            visited[i+1][j-1]=false;
        }
        if( (i+1)<N && Graph[i+1][j]==s[k]  && !visited[i+1][j])
        {
            visited[i+1][j]=true;
         ans |=    dfs(N,M,Graph,visited,s,i+1,j,k+1);
            visited[i+1][j]=false;
        }
        if( (i+1)<N && (j+1)<M  && Graph[i+1][j+1]==s[k] && !visited[i+1][j+1] )
        {
            visited[i+1][j+1]=true;
          ans |=   dfs(N,M,Graph,visited,s,i+1,j+1,k+1);
            visited[i+1][j+1]=false;
        }
    }
    
    return ans;
}
int solve(char Graph[][MAXN],int N, int M)
{
    int k=1;
    string s="CODINGNINJA";
    bool** visited=new bool*[N];
    for(int i=0;i<N;i++)
    { 
        visited[i]=new bool[M];
            
        for(int j=0;j<M;j++)
        visited[i][j]=false;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(Graph[i][j]==s[0] && visited[i][j]==false)
            {
                visited[i][j]=true;
                if(dfs(N,M,Graph,visited,s,i,j,k))
                
                return 1;
            }
        }
    }
    return 0;
    
}
int main()
{
	int N,M,i;
	char Graph[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>Graph[i];
	}
	cout<<solve(Graph,N,M)<<endl;
}



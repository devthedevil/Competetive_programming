/*
Gary has a board of size NxM. Each cell in the board is a coloured dot. 
There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z).
 Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that 
 contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent.
 Cells x and y are called adjacent if they share an edge.

Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Assume input to be 0-indexed based.
Input Format :

Line 1 : Two integers N and M, the number of rows and columns of the board
Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.

Output Format :

Return 1 if there is a cycle else return 0

Constraints :
2 ≤ N, M ≤ 50
Sample Input :

3 4
AAAA
ABCA
AAAA

Sample Output :

1


*/
#include<bits/stdc++.h>
using namespace std;
#define MAXN 51
int dfs( char board[][MAXN] , int n , int m , int a , int b , int svx , int svy , int count , int **visited )
{

    
        int ans=0;
        if(a>0 && board[a][b]==board[a-1][b] && visited[a][b]==0)
        {  //  count++;
             visited[a][b]=1;
            ans|=dfs(board,n,m,a-1,b,svx,svy,count+1,visited);
             visited[a][b]=0;
        }
        if(b>0 && board[a][b]==board[a][b-1] && visited[a][b]==0)
        {   // count++;
             visited[a][b]=1;
            ans|=dfs(board,n,m,a,b-1,svx,svy,count+1,visited);
             visited[a][b]=0;
        }
        if(a<n-1 && board[a][b]==board[a+1][b] && visited[a][b]==0)
        {   // count++;
             visited[a][b]=1;
            ans|=dfs(board,n,m,a+1,b,svx,svy,count+1,visited);
             visited[a][b]=0;
        }
        if(b<m-1 && board[a][b]==board[a][b+1] && visited[a][b]==0)
        {   // count++;
             visited[a][b]=1;
           ans|= dfs(board,n,m,a,b+1,svx,svy,count+1,visited);
             visited[a][b]=0;
        }
    
        if(svx==a && svy==b && count>3)
        return 1;
        
        return ans;
        
        
    
}

int solve(char board[][MAXN],int n, int m)
{
    int **visited=new int*[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new int[m];
        for(int j=0;j<m;j++)
            visited[i][j]=0;
    }
   int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j]==0)
            {
               count=0;
               int k=dfs(board,n,m,i,j,i,j,count,visited);
                if(k==1)
                return 1;
            }
        }
    }
    return 0;
    
}

int main()
{
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}


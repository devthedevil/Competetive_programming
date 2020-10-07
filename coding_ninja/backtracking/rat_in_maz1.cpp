#include<iostream>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
int board[20][20];
void maz(int maze[][20],int n,int row,int col)
{
    if(row==n-1 && col==n-1)
    {
        board[row][col]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
        board[row][col]=0;
        return;
    }
    else if(row<0 || col<0 || row>=n || col>=n || board[row][col]==1 || maze[row][col]==0)
        return;
    else
    {
            board[row][col]=1;
            maz(maze, n, row-1, col);
            maz(maze, n, row+1, col);
            maz(maze, n, row, col-1);
            maz(maze, n, row, col+1);
            board[row][col]=0;
            
    }

    
    

}
void ratInAMaze(int maze[][20], int n)
{
    memset(board,0,20*20*sizeof(int));
    maz(maze,n,0,0);
}
#include<iostream>
using namespace std;
#include "Solution.h"

int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}



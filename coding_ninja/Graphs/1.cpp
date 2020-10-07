int dfs( char board[][MAXN] , int n , int m , int a , int b , int svx , int svy , int count , int **visited )
{

    
        int ans =0 ;    
        if(a>0 && board[a][b]==board[a-1][b] && visited[a][b]==0)
        {    //count++;
             visited[a][b]=1;
             ans |= dfs(board,n,m,a-1,b,svx,svy,count+1,visited);
             visited[a][b]=0;
        }
        if(b>0 && board[a][b]==board[a][b-1] && visited[a][b]==0)
        {    //count++;
             visited[a][b]=1;
             ans|= dfs(board,n,m,a,b-1,svx,svy,count+1,visited);
             visited[a][b]=0;
        }
        if(a<n-1 && board[a][b]==board[a+1][b] && visited[a][b]==0)
        {    //count++;
             visited[a][b]=1;
             ans|=dfs(board,n,m,a+1,b,svx,svy,count+1,visited);
             visited[a][b]=0;
        }
        if(b<m-1 && board[a][b]==board[a][b+1] && visited[a][b]==0)
        {    //count++;
             visited[a][b]=1;
             ans|=dfs(board,n,m,a,b+1,svx,svy,count+1,visited);
             visited[a][b]=0;
        }
    
        if(svx==a && svy==b && count>4)
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
                // cout<<i<<" "<<j<<" "<<k<<endl;
            }
        }
    }
    return 0;
    
}
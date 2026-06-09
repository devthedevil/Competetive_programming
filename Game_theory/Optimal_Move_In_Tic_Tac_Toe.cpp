/*
 Optimal Move In Tic Tac Toe
Send Feedback
Given a state of 3*3 Tic Tac Toe Board and two players 'x' and 'o', find the best optimal move possible for player 'x' specifying row and column. Also calculate the score by using the corresponding evaluation function.
Assume that there are 2 possible ways for 'x' to win the game from a give board state.
Move A : 'x' can win in 2 move
Move B : 'x' can win in 4 moves
The evaluation function may return a value of +10 for both moves A and B. Even though the move A is better because it ensures a faster victory, but we may choose B sometimes. To overcome this problem we subtract the depth value from the evaluated score. This means that in case of a victory it will choose the victory which takes least number of moves and in case of a loss it will try to prolong the game and play as many moves as possible. So the new evaluated value will be
Move A will have a value of +10 – 2 = 8
Move B will have a value of +10 – 4 = 6
Now since move A has a higher score compared to move B our AI will choose move A over move B. The same thing must be applied to the minimizer. Instead of subtracting the depth we add the depth value as the minimizer always tries to get, as negative a value as possible. Pseudocode implementation is as follows.

if maximizer has won:
    return WIN_SCORE – depth

else if minimizer has won:
    return LOOSE_SCORE + depth 

Input Format

 Integer 'n'(Number of given states of board)
 For each state we will have three values
 row number , column number , player name('x' or 'o')

Output Format

 (Evaluated Score) row: (Row Number) col: (Column Number)

Sample Input 1

5
0 0 x
0 1 o
0 2 x
1 0 o
1 2 x

Sample Output 1

10 row: 1 col: 1


*/

#include<bits/stdc++.h>
using namespace std;

struct Move
{
    // public:
    int row,col,val;
};
char player='x',opponent='o';

bool isleft(char **board)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            if(board[i][j]=='_')
            return true;
    }
    return false;
}
int evaluate(char **board)
{
    for(int row=0;row<3;row++)
    {
        if(board[row][0]==board[row][1] && 
        board[row][1]==board[row][2])
        {
            if(board[row][0]==player)
            return 10;
            else if (board[row][0]==opponent)
            return -10;
        }
    }
    for(int col=0;col<3;col++)
    {
        if(board[0][col]==board[1][col] &&
         board[1][col]==board[2][col])
        {
            if(board[0][col]==player)
            return 10;
            else if (board[0][col]==opponent)
            return -10;
        }
    }
    if(board[0][0]==board[1][1]
     && board[1][1]==board[2][2])
    {
        if(board[0][0]==player)
        return 10;
        else if (board[0][0]==opponent)
        return -10;
    }
    if(board[0][2]==board[1][1] &&
     board[1][1]==board[2][0])
    {
        if(board[0][2]==player)
        return 10;
        else if (board[0][2]==opponent)
        return -10;
    }
    return 0;
}
void print(char **board)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
int minimax(char **board,int depth,bool ismax)
{
   
    int score= evaluate(board);
    if(score==10 || score==-10)
    return score;
    if(!isleft(board))
    return 0;
    int best=ismax?-1000:1000;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]=='_')
            {
    			// cout<<" before "<<endl;
    			// print(board);
    			// cout<<best<<" best "<<ismax<<" ismax "<<endl;
    			// cout<<i<<" i "<<j<<" j "<<endl;
    			// cout<<endl;

                
                board[i][j]=ismax?player:opponent;
                // this is correct
                // best=ismax?max(best-depth,minimax(board,depth+1,!ismax)):
                // min(best+depth,minimax(board,depth+1,!ismax));


                best=ismax?max(best,minimax(board,depth+1,!ismax)):
                min(best,minimax(board,depth+1,!ismax));
                board[i][j]='_';


    			// cout<<" after "<<endl;
    			// print(board);
    			// cout<<best<<" best "<<ismax<<" ismax "<<endl;
    			// cout<<i<<" i "<<j<<" j "<<endl;
    			// cout<<endl;

            }
        }
    }
    return best;
}
Move findamove(char **board)
{
    Move m;
    m.row=-1;
    m.col=-1;
    m.val=INT_MIN;
    int best;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]=='_')
            {
                board[i][j]=player;
                best=minimax(board,0,false);
                if(best>m.val)
                {
                    m.val=best;
                    m.row=i;
                    m.col=j;
                }
                board[i][j]='_';
            }
        }
    }
    return m;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char **board=new char*[3];
    for(int i=0;i<3;i++)
    {
        board[i]=new char[3];
        for(int j=0;j<3;j++)
        board[i][j]='_';
    }
    int n,a,b;
    char play;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>play;
        board[a][b]=play;
    }
    // print(board);
    // cout<<endl;
    
        Move m=findamove(board);
        cout<<m.val<<" row: "<<m.row<<" col: "<<m.col<<endl;
    
    
    

}
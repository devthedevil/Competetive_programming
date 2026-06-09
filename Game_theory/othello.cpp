#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int **makeamove(int **board,int i,int j,int player,int ischeck);
vector<pair<int,int>*>* possiblemove(int **board,int player)
{
    vector<pair<int,int>*>* out=new vector<pair<int,int>*>();
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(board[i][j]==0)
            {
                if(makeamove(board,i,j,player,true))
                {
                    pair<int,int>* p=new pair<int,int>(i,j);
                    out->push_back(p);
                }
            }
        }
    }
    return out;

}

// int** makeamove(int** board, int x, int y, int player,int isCheck) {

// 	int** newBoard;

// 	if(isCheck){
// 		newBoard = board;
// 	}else{
// 		newBoard = new int*[4];
// 		for (int i = 0; i < 4; i++) {
// 			newBoard[i] = new int[4];
// 			for (int j = 0; j < 4; j++) {
// 				newBoard[i][j] = board[i][j];
// 			}
// 		}
// 	}

// 	int xDir[] = {-1,-1,0,1,1,1,0,-1};
// 	int yDir[] = {0,1,1,1,0,-1,-1,-1};
// 	if(x < 0 || x >= 4 || y < 0 || y >= 4 || board[x][y] != 0){
// 		return NULL;
// 	}
// 	bool movePossible = false;
// 	for(int i = 0; i < 8; i++){
// 		int xStep = xDir[i];
// 		int yStep = yDir[i];
// 		int currentX = x + xStep;
// 		int currentY = y + yStep;
// 		int count = 0; 
// 		while(currentX >= 0 && currentX < 4 && currentY >= 0 && currentY < 4){

// 			if(newBoard[currentX][currentY] == 0){
// 				break;
// 			}else if(newBoard[currentX][currentY] != player){
// 				currentX += xStep;
// 				currentY += yStep;
// 				count++;
// 			}else{
// 				if(count > 0){
// 					movePossible = true;
// 					if(isCheck){
// 						return newBoard;
// 					}
// 					int convertX = currentX - xStep;
// 					int convertY = currentY - yStep;
// 					while(convertX != x || convertY != y){
// 						newBoard[convertX][convertY] = player;
// 						convertX = convertX - xStep;
// 						convertY = convertY - yStep;
// 					}
// 					newBoard[x][y] = player;
// 				}	
// 				break;
// 			}
// 		}
// 	}
// 	if(movePossible){
// 		return newBoard;
// 	}else{
// 		return NULL;
// 	}
// }

int **makeamove(int **board,int x,int y,int player,int ischeck)
{
    int **newboard;
    if(ischeck){
		newboard = board;
	}else{
		newboard = new int*[4];
		for (int i = 0; i < 4; i++) {
			newboard[i] = new int[4];
			for (int j = 0; j < 4; j++) {
				newboard[i][j] = board[i][j];
			}
		}
	}
   

    int xdir[]={-1,-1,-1,0,0,1,1,1};
    int ydir[]={-1,0,1,1,-1,1,-1,0};
     if(x<0 || x>3 || y<0 || y>3 || board[x][y]!=0)
    return NULL;
    

    bool possiblemove=0;
    for(int i=0;i<8;i++)
    {
        int xstep=xdir[i];
        int ystep=ydir[i];
        int currentx=x+xstep;
        int currenty=y+ystep;
        int count=0;
        // while(currentx >= 0 && currentx < 4 && currenty >= 0 && currenty < 4)
        while(currentx<4 &&  currentx>-1 &&  currenty>-1 &&  currenty<4) 
        {
            if(newboard[currentx][currenty]==0)
            break;
            else if(newboard[currentx][currenty]!=player)
            {
                currentx+=xstep;
                currenty+=ystep;
                count++;
            }
            else
            {
                if(count>0)
                {
                    possiblemove=1;
                    if(ischeck)
                    return newboard;
                    int convertx=currentx-xstep;
                    int converty=currenty-ystep;
                    while(convertx!=x || converty!=y)
                    {
                        newboard[convertx][converty]=player;
                        convertx-=xstep;
                        converty-=ystep;
                        // count--;
                    }
                    newboard[x][y]=player;
                }
                break;
            }
        }
    }
    if(possiblemove)
    return newboard;
    else
    return NULL;
    
    

}

int evaluateboard(int **board,bool &completed)
{
    if(possiblemove(board,1)->size()!=0 ||possiblemove(board,2)->size()!=0  )
    {
        completed=0;
        return 0;
    }
    // 1 is maximizer
    // 2 is maximizer
    completed=1;
    int count[3]={};
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        count[board[i][j]]++;
    }
    return count[1]-count[2];
    
}
void printboard(int **board)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
int findnextstep(int **board,bool maximizerturn,int &x,int &y)
{
    //check if done with play 
    // if yes return score of evaluate function
    bool completed;
    int score=evaluateboard(board,completed);
    printboard(board);
    if(completed)
    {
        return score;
    }
    // find all possible moves
    int player=maximizerturn?1:2;
    vector<pair<int,int>*>* option= possiblemove(board, player);
    
    if(option->size()==0)
    {
        x=-1;
        y=-1;
        int dummyX,dummyY;
        return findnextstep(board, !maximizerturn,dummyX,dummyY);
    }
    int best=maximizerturn?INT_MIN:INT_MAX;
    // for each move
    for(int i=0;i<option->size();i++)
    {
        // make the move
        int currentmovex=option->at(i)->first;
        int currentmovey=option->at(i)->second;
        int **newboard=makeamove(board,currentmovex,currentmovey,player,false);
        // make recursive call
        int dummyX,dummyY;
        int score=findnextstep(newboard,!maximizerturn,dummyX,dummyY);

        // update the best(will be min/max depending upon whose turn is)
        if(maximizerturn)
        {
            best=max(best,score);
        }
        else
        {
            best=min(best,score);
        }
        if(best==score)
        {
            x=currentmovex;
            y=currentmovey;
        }
        // undo the move.we have to maintain a copy of the board for this.
        for(int i=0;i<4;i++)
        delete [] newboard[i];
        delete [] newboard;
    
    }
    //update x and y and return best score
    return best;


}
int main()
{
    int **a=new int*[4];
    for(int i=0;i<4;i++)
    {
        a[i]=new int[4];
        for(int j=0;j<4;j++)
        a[i][j]=0;
    }
    a[1][1]=1;
    a[2][2]=1;
    a[1][2]=2;
    a[2][1]=2;
    int x,y;
    cout<<findnextstep(a,true,x,y)<<endl;
    cout<<x<<" "<<y<<endl;

}

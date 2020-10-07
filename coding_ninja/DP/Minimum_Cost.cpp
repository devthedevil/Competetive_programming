#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int min_cost(int **input,int si,int sj,int ei,int ej)
{
    if(si==ei && sj==ej)
    return input[ei][ej];
    if(si>ei || sj>ej)
    return INT_MAX;

    int opt1=min_cost(input,si+1,sj,ei,ej);
    int opt2=min_cost(input,si+1,sj+1,ei,ej);
    int opt3=min_cost(input,si,sj+1,ei,ej);
    return input[si][sj]+ min(opt1,min(opt2,opt3));
}
int min_cost_r(int **input,int si,int sj,int ei,int ej,int **output)
{
    if(si==ei && sj==ej)
    return input[ei][ej];
    if(si>ei || sj>ej)
    return INT_MAX;
    if(output[si][sj]>-1)
    return output[si][sj];

    int opt1=min_cost(input,si+1,sj,ei,ej);
    int opt2=min_cost(input,si+1,sj+1,ei,ej);
    int opt3=min_cost(input,si,sj+1,ei,ej);
    output[si][sj]=input[si][sj]+ min(opt1,min(opt2,opt3));
    return input[si][sj]+ min(opt1,min(opt2,opt3));
}
int min_cost2(int **input,int m,int n)
{
    int **dp = new int*[m];
    for(int i=0;i<m;i++)
    dp[i]=new int[n];
    dp[m-1][n-1]=input[m-1][n-1];
    for(int i=m-2;i>=0;i--)
    dp[i][n-1]=dp[i+1][n-1]+input[i][n-1];
    for(int i=n-2;i>=0;i--)
    dp[m-1][i]=dp[m-1][i+1]+input[m-1][i];

    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            dp[i][j]=input[i][j]+min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
        }
    }
    return dp[0][0];
    
}
int main() {
	int **input = new int*[3];
    int **output = new int*[3];
    for(int i=0;i<3;i++)
    {
        output[i]=new int[3];
        for(int j=0;j<3;j++)
        output[i][j]=-1;
    }
	input[0] = new int[3];
	input[1] = new int[3];
	input[2] = new int[3];
	input[0][0] = 4;
	input[0][1] = 3;
	input[0][2] = 2;
	input[1][0] = 1;
	input[1][1] = 8;
	input[1][2] = 3;
	input[2][0] = 1;
	input[2][1] = 1;
	input[2][2] = 8;

	cout << min_cost(input, 0,0,2,2) << endl;
    cout << min_cost_r(input, 0,0,2,2,output) << endl;
	cout << min_cost2(input,3,3) << endl;
	delete [] input[0];
	delete [] input[1];
}
/*
Maximum Square Matrix With All Zeros
Send Feedback
Given a n*m matrix which contains only 0s and 1s, 
find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
Input format :

Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).

Output Format:

Line 1 : Size of maximum square sub-matrix

Sample Input :

3 3
1 1 0
1 1 1
1 1 1

Sample Output :

1


*/
#include<iostream>
#include"solution.h"
using namespace std;
#include <bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    
    int **mat=new int*[row];
    for(int i=0;i<row;i++)
    {
        mat[i]=new int[col];
        for(int j=0;j<col;j++)
            mat[i][j]=0;
    }
    for(int i=0;i<row;i++)
        mat[i][0]= (arr[i][0]==0)?1:0;
     for(int i=0;i<col;i++)
        mat[0][i]= (arr[0][i]==0)?1:0;
    // cout<<mat[1][0]<<endl;
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            int ans=min(mat[i-1][j-1],min(mat[i][j-1],mat[i-1][j]))+1;
            mat[i][j]=(arr[i][j]==0)?ans:0;
            // cout<<ans<<"ans "<<endl;
            // cout<<mat[i][j]<<" "<<i<<" i "<<j<<" j "<<endl;
        }
    }
    int max=INT_MIN;
        for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            // int ans=min(arr[i-1][j-1],min(arr[i][j-1],arr[i-1][j]))+1;
            max=(mat[i][j]>max)?mat[i][j]:max;
        }
    }
    return max;
    
    
}
int main()
 {
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int kadene(int** arr,int n,int index)
{
    int max_so_far=0,max_end_here=0;
    for(int i=0;i<n;i++)
    {
        max_end_here+=arr[i][index];
        if(max_end_here<0)
        max_end_here=0;
        if(max_so_far < max_end_here)
        max_so_far=max_end_here;
    }
    return max_so_far;
}
int max_sum_rec(int **in,int n,int m)
{
    int **sum=new int*[n];
    int max=INT_MIN;
    int pos;
    for(int i=0;i<n;i++)
    {
        sum[i]=new int[m];
    }
    for(int i=0;i<m;i++)
    {
        for(int k=0;k<n;k++)
        sum[k][i]=in[k][i];
        pos=kadene(sum,n,i);
        if(pos>max)
        max=pos;

        for(int j=i+1;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                sum[k][j]=sum[k][j-1]+in[k][j];
            }
            // sum[k][i]=in[k][i];
            pos=kadene(sum,n,i);
            if(pos>max)
            max=pos;
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int **in=new int*[n];
    for(int i=0;i<n;i++)
    {
        in[i]=new int[m];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>in[i][j];
        }
    }
    cout<<max_sum_rec(in,n,m)<<endl;
    
}
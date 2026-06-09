#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int coin_change_recur(int n,int *d,int numd)
{
    if(n==0)
    return 1;
    if(n<0)
    return 0;
    if(numd==0)
    return 0;
    int first=coin_change_recur(n-d[0],d,numd);
    int second=coin_change_recur(n,d+1,numd-1);
    return first+second;
}
int coin_change_dp(int n,int *d,int numd,int **output)
{
    // cout<<n<<endl;
    if(n==0)
    return 1;
    if(n<0)
    return 0;
    if(numd==0)
    return 0;
    if(output[n][numd]>-1)
    return output[n][numd];
    int first=coin_change_dp(n-d[0],d,numd,output);
    int second=coin_change_dp(n,d+1,numd-1,output);
    output[n][numd]=first+second;

    return first+second;
}
int main()
{
    int d[2]={1,2};
    int n=4;
    int numd=sizeof(d)/sizeof(d[0]);
    // cout<<numd<<endl;
    //allocate a array of size n+1*numd+1
    int **output=new int*[n+1];
    for (int i=0;i<n+1;i++)
    {
        output[i]=new int [numd+1];
        for(int j=0;j<numd+1;j++)
        output[i][j]=-1;
    }
    // cout<<output[2][numd]<<endl;

    cout<<coin_change_dp(4,d,2,output)<<endl;
}
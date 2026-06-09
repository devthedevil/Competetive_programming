/*
Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.
He gives him an array of N natural numbers and asks him to solve the following queries:-

Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.

Input:

First line of the input contains the number N. Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y. 

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.

Constraints:

1<=N,Q<=10^5

1<=l<=r<=N 

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9

Note:-
indexing starts from 1.
Sample Input

6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6

Sample Output

2
2
4


*/
#include<bits/stdc++.h>
using namespace std;
void update(int *arr,int *tree,int start,int end,int treenode,int index,int value )
{
    if(start==end)
    {
        if(value%2==0)
        tree[treenode]=1;
        else
        tree[treenode]=0;
        arr[index]=value;
        return;
    }
    int mid=(start+end)/2;
    if(index>mid)
    {
        update(arr,tree,mid+1,end,2*treenode+1,index,value);
    }
    else
    {
        update(arr,tree,start,mid,2*treenode,index,value);
    }
    tree[treenode]=tree[2*treenode]+tree[2*treenode+1];
}
int query(int *tree,int start,int end,int treenode,int left,int right)
{
    if(end<left || right<start)
    return 0;
    if(start>=left && end<=right)
    return tree[treenode];
    int mid=(start+end)/2;
    int q1=query(tree,start,mid,2*treenode,left,right);
    int q2=query(tree,mid+1,end,2*treenode+1,left,right);
    return (q1+q2);
}
void buildtree(int *arr,int *tree,int start,int end,int treenode)
{
    if(start==end)
    {
        if(arr[start]%2==0)
        tree[treenode]=1;
        else
        tree[treenode]=0;
        return;
    }
    else
    {
        int mid=(start+end)/2;
        buildtree(arr,tree,start,mid,2*treenode);
        buildtree(arr,tree,mid+1,end,2*treenode+1);
        tree[treenode]=(tree[2*treenode]+tree[2*treenode+1]);
        
    }
}
int main()
{
    int n,q;
    cin>>n;
    //vector<int> arr(n);
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int c;
    int a,b,ans;
    cin>>q;
    //vector<int> tree(2*n);
    int *tree=new int[4*n];
    buildtree(arr,tree,0,n-1,1);
    //   for(int i=1;i<4*n;i++)
    //   cout<<tree[i]<<" "<<endl;
    // cout<<endl;
    for(int i=0;i<q;i++)
    {    
        cin>>c>>a>>b;
        if(c==1)
        {
            ans=query(tree,0,n-1,1,a-1,b-1);
            cout<<ans<<endl;
        }
        else if(c==0)
        {
            update(arr,tree,0,n-1,1,a-1,b);
        }
        else if(c==2)
        {
            ans=query(tree,0,n-1,1,a-1,b-1);
            cout<<(b-a+1)-ans<<endl;
        }
    }
    delete [] tree;
    delete [] arr;
    
}
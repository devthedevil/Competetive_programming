/*
Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.
Input:

First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.

Output:

For each type 1 query, print the minimum element in the sub-array A[l:r].

Contraints:

1≤N,Q,y≤10^5
1≤l,r,x≤N

Sample Input :

5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5

Sample Output :

1
1
2
1


*/
#include<bits/stdc++.h>
using namespace std;
void update(int *arr,int *tree,int start,int end,int treenode,int index,int value )
{
    if(start==end)
    {
        tree[treenode]=value;
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
    tree[treenode]=min(tree[2*treenode],tree[2*treenode+1]);
}
int query(int *tree,int start,int end,int treenode,int left,int right)
{
    if(end<left || right<start)
    return INT_MAX;
    if(start>=left && end<=right)
    return tree[treenode];
    int mid=(start+end)/2;
    int q1=query(tree,start,mid,2*treenode,left,right);
    int q2=query(tree,mid+1,end,2*treenode+1,left,right);
    return min(q1,q2);
}
void buildtree(int *arr,int *tree,int start,int end,int treenode)
{
    if(start==end)
    {
        tree[treenode]=arr[start];
        return;
    }
    else
    {
        int mid=(start+end)/2;
        buildtree(arr,tree,start,mid,2*treenode);
        buildtree(arr,tree,mid+1,end,2*treenode+1);
        tree[treenode]=min(tree[2*treenode],tree[2*treenode+1]);
        
    }
}
int main()
{
    int n,q;
    cin>>n>>q;
    //vector<int> arr(n);
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    char c;
    int a,b,ans;
    //vector<int> tree(2*n);
    int *tree=new int[4*n];
    buildtree(arr,tree,0,n-1,1);
    // for(int i=1;i<2*n;i++)
    // cout<<tree[i]<<endl;
    for(int i=0;i<q;i++)
    {    
        cin>>c>>a>>b;
        //cout<<c<<" "<<a<<" "<<b<<endl;
        
        
        if(c=='q')
        {
            ans=query(tree,0,n-1,1,a-1,b-1);
            cout<<ans<<endl;
        }
        else if(c=='u')
        {
            update(arr,tree,0,n-1,1,a-1,b);
        }
    }
    delete [] tree;
    delete [] arr;
    
}
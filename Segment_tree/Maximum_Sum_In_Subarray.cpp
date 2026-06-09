/*
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.
Input

The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.

Output

Your program should output the results of the M queries, one 
query per line.

Sample Input:

3 
-1 2 3 
1
1 2

Sample Output:

2


*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int sum;
    int msum;
    int bpsum;
    int bssum;
};
int maximum(int a1,int a2,int a3,int a4,int a5)
{
    int b1=max(a1,a2);
    int b2=max(a3,b1);
    int b3=max(a4,b2);
    return max(b3,a5);
}
void buildtree(int *arr,node *tree,int start,int end,int treenode)
{
    if(start==end)
    {
       // cout<<start<<"start"<<treenode<<endl;
        tree[treenode].sum=arr[start];
        tree[treenode].msum=arr[start];
        tree[treenode].bpsum=arr[start];
        tree[treenode].bssum=arr[start];
        return;
        
    }
    int mid=(start+end)/2;
    buildtree(arr,tree,start,mid,2*treenode);
    buildtree(arr,tree,mid+1,end,2*treenode+1);
    tree[treenode].sum=tree[2*treenode].sum+tree[2*treenode+1].sum;
    tree[treenode].bpsum=max(tree[2*treenode].bpsum,tree[2*treenode].sum+tree[2*treenode+1].bpsum);
    tree[treenode].bssum=max(tree[2*treenode+1].bssum,tree[2*treenode+1].sum+tree[2*treenode].bssum);
    node l=tree[2*treenode];
    node r=tree[2*treenode+1];
    tree[treenode].msum=maximum(l.msum,r.msum,l.sum+r.bpsum,r.sum+l.bssum,l.bssum+r.bpsum);
}
node query(node *tree,int start,int end,int treenode,int left,int right )
{
    node d;
    d.sum=-15008;
    d.msum=-15008;
    d.bpsum=-15008;
    d.bssum=-15008;
    
    if(end<left || start>right)
    return d;
    if(start>=left && end<=right)
    return tree[treenode];
    int mid=(start+end)/2;
    node d1=query(tree,start,mid,2*treenode,left,right);
    node d2=query(tree,mid+1,end,2*treenode+1,left,right);
    d.sum=d1.sum+d2.sum;
    d.bpsum=max(d1.bpsum,d1.sum+d2.bpsum);
    d.bssum=max(d2.bssum,d2.sum+d1.bssum);
    node l=d1;
    node r=d2;
    d.msum=maximum(l.msum,r.msum,l.sum+r.bpsum,r.sum+l.bssum,l.bssum+r.bpsum);
    return d;
}
int main() 
{
    int n,q,left,right;
    node ans;
    cin>>n;
    int *arr=new int[n];
    node *tree=new node[4*n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        //     for(int i=0;i<n;i++)
        // cout<<arr[i]<<" ";
        // cout<<endl;
    cin>>q;
    buildtree(arr,tree,0,n-1,1);
        // for(int i=1;i<4*n;i++)
        // cout<<tree[i].msum<<" ";
        // cout<<endl;
    while(q--)
    {
        
        cin>>left>>right;
        ans=query(tree,0,n-1,1,left-1,right-1);
        cout<<ans.msum<<endl;
        
    }
    delete [] arr;
    delete [] tree;
}
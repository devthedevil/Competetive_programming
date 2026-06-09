/*
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.

U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.

This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.

Q x y, 1 ≤ x < y ≤ N.

You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input

The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5,
 representing the number of operations. Next Q lines contain the operations.

Output

 Output the maximum sum mentioned above, in a separate line, for each Query.

Input:

5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5

Output:

7
9
11
12


*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll max;
    ll smax;
};
void update(ll *arr,node *tree,ll start,ll end,ll treenode,ll index,ll value )
{
    if(start==end)
    {
        tree[treenode].max=value;
        tree[treenode].smax=INT_MIN;
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
    node left=tree[2*treenode];
    node right=tree[2*treenode+1];
    tree[treenode].max=max(tree[2*treenode].max,tree[2*treenode+1].max);
    tree[treenode].smax=max(min(left.max,right.max),max(left.smax,right.smax)); 
    return;

}
node query(node *tree,ll start,ll end,ll treenode,ll left,ll right)
{
    node d;
    d.max=INT_MIN;
    d.smax=INT_MIN;
    if(end<left || right<start)
    return d;
    if(start>=left && end<=right)
    return tree[treenode];
    ll mid=(start+end)/2;
    node q1=query(tree,start,mid,2*treenode,left,right);
    node q2=query(tree,mid+1,end,2*treenode+1,left,right);
    d.max=max(q1.max,q2.max);
    d.smax=max(min(q1.max,q2.max),max(q1.smax,q2.smax));
    return d;
}
void buildtree(ll *arr, node *tree,ll treenode,ll start,ll end)
{
    if(start==end)
    {
    tree[treenode].max=arr[start];
    tree[treenode].smax=INT_MIN;
    return;
    }
    ll mid=(start+end)/2;
    buildtree(arr,tree,2*treenode,start,mid);
    buildtree(arr,tree,2*treenode+1,mid+1,end);
    node left=tree[2*treenode];
    node right=tree[2*treenode+1];
    tree[treenode].max=max(left.max,right.max);
    tree[treenode].smax=max(min(left.max,right.max),max(left.smax,right.smax));
    return;


}
int main()
{
    ll n,q;
    ll a,b;
    char c;
    cin>>n;
    
    ll *arr=new ll[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
     node *tree=new node[3*n];
     cin>>q;
     buildtree(arr,tree,1,0,n-1);
//     for(ll i=0;i<q;i++)
//     {
//         cout<<tree<<" ";
//     }
//     cout<<endl;
    
    for(ll i=0;i<q;i++)
    {    
        cin>>c>>a>>b;
        
        if(c=='Q')
        {
            node ans=query(tree,0,n-1,1,a-1,b-1);
            cout<<(ans.max+ans.smax)<<endl;
        }
        else if(c=='U')
        {   
            update(arr,tree,0,n-1,1,a-1,b);
        }
    }
    delete [] tree;
    delete [] arr;
}
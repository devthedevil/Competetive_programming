/*
Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. 
Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose 
her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior 
having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A
 value and same minimum B value, she chooses the one with lower index in line.
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
Input:

First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.

Output:

For each Li and Ri, print the index of the warrior that Queen Vasya should choose.

Constraints:
1≤ N,Q ≤10^6
1≤ Ai,Bi ≤10^9
1≤Li≤Ri
Sample Input

5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5

Sample Output

2
2
4
5


*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll a;
    ll b;
};
struct Tree
{
    ll a;
    ll b;
    ll index;
};
void update(node *arr,Tree *tree,ll start,ll end,ll treenode,ll index)
{
    if(start==end)
    {
        tree[treenode].a=INT_MIN;
        tree[treenode].b=INT_MAX;
        tree[treenode].index=INT_MAX;
        arr[index].a=INT_MIN;
        arr[index].b=INT_MAX;
        return;
    }
    ll mid=(start+end)/2;
    if(index>mid)
    {
        update(arr,tree,mid+1,end,2*treenode+1,index);
    }
    else
    {
        update(arr,tree,start,mid,2*treenode,index);
    }
    Tree left=tree[2*treenode];
    Tree right=tree[2*treenode+1];
    if(left.a>right.a)
    {
        tree[treenode].index=left.index;
        tree[treenode].a=left.a;
        tree[treenode].b=left.b;
        return;
        
    }
    if(left.a==right.a)
    {
        if(left.b<right.b)
        {
            tree[treenode].index=left.index;
            tree[treenode].a=left.a;
            tree[treenode].b=left.b;
            return;
        }
        if(left.b==right.b)
        {
            if(left.index<right.index)
            {
                tree[treenode].index=left.index;
                tree[treenode].a=left.a;
                tree[treenode].b=left.b;
                return;
            }
            if(left.index>right.index)
            {
                tree[treenode].index=right.index;
                tree[treenode].a=right.a;
                tree[treenode].b=right.b;
                return;
            }
            
        }
        if(left.b>right.b)
        {
            tree[treenode].index=right.index;
            tree[treenode].a=right.a;
            tree[treenode].b=right.b;
            return;
        }
        
        
    }
    if(left.a<right.a)
    {
        tree[treenode].index=right.index;
        tree[treenode].a=right.a;
        tree[treenode].b=right.b;
        return;
        
    }
    
   



}
Tree query(Tree *tree,ll start,ll end,ll treenode,ll left,ll right)
{
    Tree d;
    d.a=INT_MIN;
    d.b=INT_MAX;
    d.index=INT_MAX;
    if(end<left || right<start)
    return d;
    if(start>=left && end<=right)
    return tree[treenode];
    ll mid=(start+end)/2;
    Tree l=query(tree,start,mid,2*treenode,left,right);
    Tree r=query(tree,mid+1,end,2*treenode+1,left,right);
    // Tree left=tree[2*treenode];
    // Tree right=tree[2*treenode+1];
    if(l.a>r.a)
    {
        d.index=l.index;
        d.a=l.a;
        d.b=l.b;
        return d;
        
    }
    if(l.a==r.a)
    {
        if(l.b<r.b)
        {
            d.index=l.index;
            d.a=l.a;
            d.b=l.b;
            return d;
        }
        if(l.b==r.b)
        {
            if(l.index<r.index)
            {
                d.index=l.index;
                d.a=l.a;
                d.b=l.b;
                return d;
            }
            if(l.index>r.index)
            {
                d.index=r.index;
                d.a=r.a;
                d.b=r.b;
                return d;
            }
            
        }
        if(l.b>r.b)
        {
            d.index=r.index;
            d.a=r.a;
            d.b=r.b;
            return d;
        }
        
        
    }
    if(l.a<r.a)
    {
        d.index=r.index;
        d.a=r.a;
        d.b=r.b;
        return d;
        
    }
    
 
    
}
void buildtree(node *arr, Tree *tree,ll treenode,ll start,ll end)
{
    if(start==end)
    {
    tree[treenode].index=start;
    tree[treenode].a=arr[start].a;
    tree[treenode].b=arr[start].b;
        
    return;
    }
    ll mid=(start+end)/2;
    buildtree(arr,tree,2*treenode,start,mid);
    buildtree(arr,tree,2*treenode+1,mid+1,end);
    Tree left=tree[2*treenode];
    Tree right=tree[2*treenode+1];
    if(left.a>right.a)
    {
        tree[treenode].index=left.index;
        tree[treenode].a=left.a;
        tree[treenode].b=left.b;
        return;
        
    }
    if(left.a==right.a)
    {
        if(left.b<right.b)
        {
            tree[treenode].index=left.index;
            tree[treenode].a=left.a;
            tree[treenode].b=left.b;
            return;
        }
        if(left.b==right.b)
        {
            if(left.index<right.index)
            {
                tree[treenode].index=left.index;
                tree[treenode].a=left.a;
                tree[treenode].b=left.b;
                return;
            }
            if(left.index>right.index)
            {
                tree[treenode].index=right.index;
                tree[treenode].a=right.a;
                tree[treenode].b=right.b;
                return;
            }
            
        }
        if(left.b>right.b)
        {
            tree[treenode].index=right.index;
            tree[treenode].a=right.a;
            tree[treenode].b=right.b;
            return;
        }
        
        
    }
    if(left.a<right.a)
    {
        tree[treenode].index=right.index;
        tree[treenode].a=right.a;
        tree[treenode].b=right.b;
        return;
        
    }
    
   


}
int main()
{
    ll n,q;
    ll a,b;
    cin>>n;
    
    node *arr=new node[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i].a;
    }
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i].b;
    }
     Tree *tree=new Tree[3*n];
     cin>>q;
     buildtree(arr,tree,1,0,n-1);
    // for(ll i=1;i<3*n;i++)
    // {
    //     cout<<tree[i].a<<" "<<tree[i].b<<" "<<tree[i].index;
    //     cout<<endl;
    // }
    // cout<<endl;
    
    for(ll i=0;i<q;i++)
    {    
        cin>>a>>b;
        
        
           Tree ans=query(tree,0,n-1,1,a-1,b-1);
         //  update(arr,tree,0,n-1,1,ans.index);
          cout<<ans.index+1<<endl;
           
        
        
    }
    delete [] tree;
    delete [] arr;
}
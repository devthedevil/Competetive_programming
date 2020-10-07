/*
Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)),
 and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
The sum of squares over a range with range updates of 2 types:
1) increment in a range
2) set all numbers the same in a range.
Input

There will be T (T <= 25) test cases in the input file. First line of the input contains two positive integers, N (N <= 100,000) and Q (Q <= 100,000). 
The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:

2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).

1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).

0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).

Output

For each test case output the “Case <caseno>:” in the first line and from the second line output the sum of squares for each operation of type 2. 
Intermediate overflow will not occur with proper use of 64-bit signed integer.

Input:

2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
1 1
1
2 1 1

Output:

Case 1:
30
7
13
Case 2:
1


*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Lazy
{
    ll type;
    ll val;
};
struct Tree
{
    ll ssum;
    ll sum;
};
void buildtree(ll *arr,Tree *tree,ll start,ll end,ll treenode)
{
    if(start==end)
    {
        tree[treenode].ssum=arr[start]*arr[start];
        tree[treenode].sum=arr[start];
        return;
    }
    ll mid=(start+end)/2;
    buildtree(arr,tree,start,mid,2*treenode);
    buildtree(arr,tree,mid+1,end,2*treenode+1);
    tree[treenode].sum=tree[2*treenode].sum+tree[2*treenode+1].sum;
    tree[treenode].ssum=tree[2*treenode].ssum+tree[2*treenode+1].ssum;

}
void update(ll *arr,Tree *tree,Lazy *lazy,ll low,ll high,ll startR,ll endR,ll treenode,ll operation,ll value)
{
    if(low>high)
    return;
    if(lazy[treenode].type!=2)
    {
        
        if(lazy[treenode].type==1 )
        {
            tree[treenode].sum+=(endR-startR+1)*lazy[treenode].val;
            tree[treenode].ssum+=(endR-startR+1)*lazy[treenode].val*lazy[treenode].val+2*lazy[2*treenode].val*tree[treenode].sum;
            
            if(low!=high)
            {
                lazy[2*treenode].val+=value;
                lazy[2*treenode+1].val+=value;
                lazy[2*treenode].type=lazy[2*treenode].type==0 ? 0 : 1;
                lazy[2*treenode+1].type=lazy[2*treenode+1].type==0 ? 0 : 1;
            }
        }
        if(lazy[treenode].type==0)
        {
            tree[treenode].ssum=(endR-startR+1)*lazy[treenode].val*lazy[treenode].val;
            tree[treenode].sum=(endR-startR+1)*lazy[treenode].val;

            if(low!=high)
            {
                lazy[2*treenode].val=value;
                lazy[2*treenode+1].val=value;
                lazy[2*treenode].type=0;
                lazy[2*treenode+1].type=0;

            }
        }
            lazy[treenode].val=0;
            lazy[treenode].type=2;
    }
        if(low>endR || startR>high)
        return;
        if(startR<=low && endR>=high)
        {

            if(operation==1 )
            {
            tree[treenode].ssum+=(endR-startR+1)*value*value+2*value*tree[treenode].sum;
            tree[treenode].sum+=(endR-startR+1)*value;
                if(low!=high)
                {
                    lazy[2*treenode].type=lazy[2*treenode].type==0 ? 0: 1;
                    lazy[2*treenode+1].type=lazy[2*treenode+1].type==0 ? 0: 1;
                    lazy[2*treenode].val+=value;
                    lazy[2*treenode+1].val+=value;
                }
            }
            if(operation==0)
            {
            tree[treenode].ssum=(endR-startR+1)*value*value;
            tree[treenode].sum=(endR-startR+1)*value;
                if(low!=high)
                {
                    lazy[2*treenode].type=0;
                    lazy[2*treenode+1].type=0;
                    lazy[2*treenode].val=value;
                    lazy[2*treenode+1].val=value;
                }
            }
            return;
        }
        ll mid=(low+high)/2;
        update(arr,tree,lazy,low, mid, startR, endR,2*treenode, operation,value);
        update(arr,tree,lazy,mid+1, high, startR, endR,2*treenode+1, operation,value);
        tree[treenode].ssum=tree[2*treenode].ssum+tree[2*treenode+1].ssum;
        tree[treenode].sum=tree[2*treenode].sum+tree[2*treenode+1].sum;
        
}
Tree query(Lazy *lazy,Tree *tree,ll start,ll end,ll treenode,ll left,ll right)
{
    Tree t;
    t.ssum=0;
    t.sum=0;
    if(start>end)
    return t;

    if(lazy[treenode].type != 2)
    {
        if(lazy[treenode].type==1 )
        {
            tree[treenode].sum+=(right-left+1)*lazy[treenode].val;
            tree[treenode].ssum+=(right-left+1)*lazy[treenode].val*lazy[treenode].val+2*lazy[2*treenode].val*tree[treenode].sum;
            
            if(start!=end)
            {
                lazy[2*treenode].type=lazy[2*treenode].type==0 ? 0 : 1;
                lazy[2*treenode].val+=lazy[treenode].val;
                lazy[2*treenode+1].type=lazy[2*treenode].type==0 ? 0 : 1;
                lazy[2*treenode+1].val+=lazy[treenode].val;
            }
        }
        else if(lazy[treenode].type==0)
        {
            tree[treenode].ssum=(right-left+1)*lazy[treenode].val*lazy[treenode].val;
            tree[treenode].sum=(right-left+1)*lazy[treenode].val;

            if(start!=end)
            {
                lazy[2*treenode].val=lazy[treenode].val;
                lazy[2*treenode+1].val=lazy[treenode].val;
                lazy[2*treenode].type=0;
                lazy[2*treenode+1].type=0;

            }
        }
            lazy[treenode].val=0;
            lazy[treenode].type=2;
    }
    if(start>right || left>end)
    return t;
    if(start>=left && end<=right)
    return tree[treenode];
    ll mid=(start+end)/2;
    Tree t1,t2;
    t1=query(lazy,tree,start,mid,2*treenode,left,right);
    t2=query(lazy,tree,mid+1,end,2*treenode+1,left,right);
    t.ssum=t1.ssum+t2.ssum;
    t.sum=t1.sum+t2.sum;
    return t;

}
int main() 
{
    ll t;
    cin>>t;
    ll cas=1;
    while(t--)
    {
        
        
        ll n,q;
        cin>>n>>q;
        ll *arr=new ll[n];
        Tree *tree=new Tree[4*n];
        Lazy *lazy=new Lazy[4*n];
        cout<<"Case "<<cas<<":"<<endl;
        cas++;
        for(int i = 0; i < 4*n; i++)
        {
            tree[i].ssum = 0;
            tree[i].sum = 0;
            lazy[i].val = 0;
            lazy[i].type = 2;
        }
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        buildtree(arr,tree,0,n-1,1);
        ll op,l,r,value;
        while(q--)
        {
            cin>>op;
            if(op==2)
            {
                cin>>l>>r;
                Tree t=query(lazy,tree,0,n-1,1,l-1,r-1);
                cout<<t.ssum<<endl;
            }
            else
            {
                cin>>l>>r>>value;
                update(arr,tree,lazy,0,n-1,l-1,r-1,1,op,value);
            }
        }
        delete[] arr;
		delete[] tree;
		delete[] lazy;

    }

}
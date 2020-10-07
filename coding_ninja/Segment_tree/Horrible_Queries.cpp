#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void buildtree(vector<ll> arr,vector<ll>tree,ll start,ll end,ll treenode)
{
   
    if(start==end)
    {
        tree[treenode]=arr[start];
        return;
    }
    
        ll mid=(start+end)/2;
        buildtree(arr,tree,start,mid,2*treenode);
        buildtree(arr,tree,mid+1,end,2*treenode+1);
        tree[treenode]=(tree[2*treenode]+tree[2*treenode+1]);
}
void updatesegmenttreelazy(vector<ll>tree,vector<ll> lazy,ll low,ll high,ll startR,ll endR,ll currpos,ll inc)
{
    if(low>high)
    return;
    if(lazy[currpos]!=0)
    {
    tree[currpos]+=lazy[currpos];
        if(low!=high)
        {
            lazy[2*currpos]+=lazy[currpos];
            lazy[2*currpos+1]+=lazy[currpos];
            
        }
    lazy[currpos]=0;
    }
    //completely outside
    if(startR>high || low>endR )
    return;
    //completely inside
    if(startR<=low && high<=endR)
    {
        tree[currpos]+=inc;
        if(low!=high)
        {
            lazy[2*currpos]+=inc;
            lazy[2*currpos+1]+=inc;
            
        }
        return ;
    }
    //partial overlap
    ll mid=(high+low)/2;
    updatesegmenttreelazy(tree,lazy,low,mid,startR,endR,2*currpos,inc);
    updatesegmenttreelazy(tree,lazy,mid+1,high,startR,endR,2*currpos+1,inc);
    tree[currpos]=(tree[2*currpos]+tree[2*currpos+1]);

}
ll query(vector<ll> lazy,vector<ll> tree,ll start,ll end,ll treenode,ll left,ll right)
{

    if(start>end)
    return 0;

    if(lazy[treenode]!= 0)
    {
        
            tree[treenode]+=lazy[treenode];
         
            if(start!=end)
            {
                lazy[2*treenode]+=lazy[treenode];
                lazy[2*treenode+1]+=lazy[treenode];
            }
               lazy[treenode]=0;
            
    }
    if(start>right || left>end)
    return 0;
    if(start>=left && end<=right)
    return tree[treenode];
    ll mid=(start+end)/2;
    ll t1,t2,t;
    t1=query(lazy,tree,start,mid,2*treenode,left,right);
    t2=query(lazy,tree,mid+1,end,2*treenode+1,left,right);
    t=t1+t2;
    return t;

}
int main()
{
    ll t,n,q,c;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        vector<ll> arr(n,0);
        vector<ll> tree(4*n,0);
        vector<ll> lazy(4*n,0);
        buildtree(arr,tree,0,n-1,1);
        while(q--)
        {
            cin>>c;
            ll p,q,v;
            if(c==0)
            {
                cin>>p>>q>>v;
                updatesegmenttreelazy(tree,lazy,0,n-1,p-1,q-1,1,v);
            }
            else
            {
                cin>>p>>q; 
                ll ans=query(lazy,tree,0,n-1,1,p-1,q-1); 
                cout<<ans<<endl;
            }
        }
    }
}
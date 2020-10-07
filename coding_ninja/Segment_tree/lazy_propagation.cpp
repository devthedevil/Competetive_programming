#include<bits/stdc++.h>
using namespace std;
void buildtree(int *arr,int *tree,int start,int end,int treenode)
{
   
    if(start==end)
    {
        tree[treenode]=arr[start];
        return;
    }
    
        int mid=(start+end)/2;
        buildtree(arr,tree,start,mid,2*treenode);
        buildtree(arr,tree,mid+1,end,2*treenode+1);
        tree[treenode]=min(tree[2*treenode],tree[2*treenode+1]);
    
    


}
void updatesegmenttreelazy(int *tree,int *lazy,int low,int high,int startR,int endR,int currpos,int inc)
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
    int mid=(high+low)/2;
    updatesegmenttreelazy(tree,lazy,low,mid,startR,endR,2*currpos,inc);
    updatesegmenttreelazy(tree,lazy,mid+1,high,startR,endR,2*currpos+1,inc);
    tree[currpos]=min(tree[2*currpos],tree[2*currpos+1]);

}
int main()
{
    int arr[]={1,3,-2,4};
    int *tree=new int[12]();
    int *lazy=new int[12]();
    buildtree(arr,tree,0,3,1);
    updatesegmenttreelazy(tree,lazy,0,3,0,3,1,3);
    updatesegmenttreelazy(tree,lazy,0,3,0,1,1,2);
    cout<<"segment tree"<<endl;
    for(int i=1;i<12;i++)
    {
        cout<<tree[i]<<endl;
    }
    cout<<"lazy tree"<<endl;
    for(int i=1;i<12;i++)
    {
        cout<<lazy[i]<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
int my_buildtree(int *arr,int *tree,int start,int end,int treenode)
{
    int mid=(start+end)/2;
    if(start<end)
    {
        tree[treenode]=my_buildtree(arr,tree,start,mid,2*treenode)+my_buildtree(arr,tree,mid+1,end,2*treenode+1);
        return tree[treenode];
    }
    else
    {
        tree[treenode]=arr[start];
        return arr[start];
    }
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
        tree[treenode]=tree[2*treenode]+tree[2*treenode+1];
    }
    


}
void updatetree(int* arr,int *tree,int start,int end,int treenode,int index,int value)
{
    if(start==end)
    {
        tree[treenode]=value;
        arr[index]=value;
        return;
    }
    int mid=(start+end)/2;
    if(mid<index)
    {
        updatetree(arr,tree,mid+1,end,2*treenode+1,index,value);
    }
    else
    {
    updatetree(arr,tree,start,mid,2*treenode,index,value);
    }
    tree[treenode]=tree[2*treenode]+tree[2*treenode+1];
    

}
int query(int* tree,int start,int end,int treenode,int left,int right)
{
    // completely outside
    if(end<left || start>right)
    {
       // cout<<0<<"completely outside"<<endl;
        return 0;
    }
    //completely inside
    if(start>=left && end<=right )
    {
     //   cout<< tree[treenode]<<"completely inside"<<endl;
        return tree[treenode];
    }
    //partially inside and partially outside
    int mid=(start+end)/2;
    int q1=query(tree,start,mid,2*treenode,left,right);
    int q2=query(tree,mid+1,end,2*treenode+1,left,right);
   // cout<<q1+q2<<"partially inside and partially outside"<<endl;
    return (q1+q2);

}
int main()
{
    int arr[]={1,2,3,4,5};
    int* tree=new int[10];

    buildtree(arr,tree,0,4,1);
   updatetree(arr,tree,0,4,1,2,10);
    // for(int i=1;i<10;i++)
    // cout<<tree[i]<<endl;
    // cout<<endl;
    // for(int i=0;i<5;i++)
    // cout<<arr[i]<<endl;
    int ans=query(tree,0,4,1,2,4);
    cout<<ans;

}
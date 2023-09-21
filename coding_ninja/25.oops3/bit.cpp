#include<bits/stdc++.h>
using namespace std;
void update(int index,int value,int *BIT,int n)
{
    for(;index<=n;index+=index&-(index))
    {
        BIT[index]+=value;
        // cout<<index<<" index "<<BIT[index]<<" BIT[index] ";
    }

}
int query(int index,int *BIT)
{
    int sum=0;
    for(;index>0;index-=index&(-index))
    {
        // cout<<index<<" index ";
        sum+=BIT[index];
        // cout<<sum<<" sum "<<BIT[index]<<" BIT[index] ";
    }
    // cout<<endl;
    return sum;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int [n+1]();
    int *BIT=new int [n+1]();
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        update(i,arr[i],BIT,n);
    }
    cout<<"sum of first 5 element " <<query(6,BIT)<<endl; 
    cout<<"sum of elements from 2 index to 6 index "<<query(6,BIT)-query(1,BIT)<<endl;
}
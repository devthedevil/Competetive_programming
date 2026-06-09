/*
Given a sequence A1 , A2 , A3 .. AN of length N . Find total number of wave subsequences having length greater than 1.
Wave subsequence of sequence A1 , A2 , A3 .. AN is defined as a set of integers i1 , i2 .. ik such that Ai1 < Ai2 > Ai3 < Ai4 .... 
or Ai1 > Ai2 < Ai3 > Ai4 .... and i1 < i2 < ...< ik.Two subsequences i1 , i2 .. ik and j1 , j2 .. jm are considered different if k != m or
 there exists some index l such that il ! = jl
INPUT

First line of input consists of integer N denoting total length of sequence.Next line consists of N integers A1 , A2 , A3 .. AN .

OUTPUT

Output total number of wave subsequences of given sequence . Since answer can be large, output it modulo 10^9+7

CONSTRAINTS

1 ≤ N ≤ 10^5

1 ≤ Ai ≤ 10^5

SAMPLE INPUT

5
1 3 5 4 2

SAMPLE OUTPUT

17

Explanation

All the possible sequences are: [ 1 3 ] , [1 5 ] , [ 1 4 ] , [1 2 ] , [1 3 2] , [1 4 2 ] , [1 5 2] , [1 5 4] , [3 5] ,
 [3 4] , [3 2] , [3 5 2] , [3 4 2] , [3 5 4] , [5 4] , [5 2 ] , [4 2] . Note that value in the bracket are the values from the 
 original sequence whose positions are maintained.


*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rem 1000000007

void update(ll index,ll s_index,ll value,ll **bit)
{
    for(;index<=100000;index+=index&(-index))
    {
        bit[index][s_index]+=value;
    }
}
ll query(ll index,ll s_index,ll **bit)
{
    ll sum=0;
    for(;index>0;index-=(index)&(-index))
    {
        // cout<<index<<" index "<<s_index<<" s_index"<<endl;
        // cout<<bit[index][s_index]<<" bit "<<endl;
        sum+=bit[index][s_index];
    }
    return sum;
}
int main()
{
    ll **bit=new ll*[100001];
    for(ll i=0;i<=100000;i++)
    {
        bit[i]=new ll[3];
        bit[i][0]=0;
        bit[i][1]=0;
        bit[i][2]=0;
    }
    ll n,a,b;
    cin>>n;
    ll *arr=new ll[n];
    for(ll i=0;i<n;i++)
    cin>>arr[i];
    ll *ans=new ll[n]();
    ll max=arr[0];

    update(arr[0],2,1,bit);
    for(ll i=1;i<n;i++)
    {
        

        a=query(arr[i]-1,0,bit)+query(arr[i]-1,2,bit);
        a%=rem;
        b=query(max,1,bit)-query(arr[i],1,bit)+query(max,2,bit)-query(arr[i],2,bit);
        b%=rem;
        // b=(b+rem)%rem;
        // cout<<query(max,2,bit)<<" "<<query(arr[i],2,bit)<<" max "<<max<<" arr[i] "<<arr[i]<<endl;
        update(arr[i],0,b,bit);
        update(arr[i],1,a,bit);
        update(arr[i],2,1,bit);
        if(max<arr[i])
        max=arr[i];
        ans[i]=ans[i-1]+a+b;
        ans[i]%=rem;
        // cout<<query(arr[i]-1,2,bit)<<endl;
        // cout<<i<<" i "<<a<<" a "<<b<<" b "<<endl;
        
    }
    cout<<(ans[n-1]%rem)<<endl;




}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll num_codes(ll *n,ll size)
{
    if(size==0 || size==1)
    return 1;
    ll out=num_codes(n,size-1);
    if(n[size-2]*10+n[size-1]<=26)
    out+=num_codes(n,size-2);
    return out;
}
ll num_codes2(ll *n,ll size,ll *arr)
{
    if(arr[size]>0)
    return arr[size];
    if(size==0 || size==1)
    return 1;
    ll out=num_codes(n,size-1);
    if(n[size-2]*10+n[size-1]<=26)
    out+=num_codes(n,size-2);
    arr[size]=out;
    return out;
}
ll num_codes3(ll *n,ll size)
{
    ll *arr=new ll[size+1]();
    arr[0]=1; 
    arr[1]=1;
    for(ll i=2;i<size;i++)
    {
        arr[i]=arr[i-1];
        if(n[i-2]*10+n[i-1]<=26)
        arr[i]+=arr[i-2];
    }
    ll out=arr[size];
    delete [] arr;
    return out;
}
int main()
{
    while(1)
    {
        string s;
    cin>>s;
    if(s=="0")
    break;
    ll size=s.length();
    // cin>>size;
    ll *n=new ll[size];
    for(ll i=0;i<size;i++)
    n[i]=s[i]='0';
    cout<<num_codes3(n,size)<<endl;
    }
}
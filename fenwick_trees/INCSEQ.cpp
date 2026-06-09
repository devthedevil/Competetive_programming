/*
Given a sequence of N (1 ≤ N ≤ 10,000) integers S1, ..., SN (0 ≤ Si < 100,000), 
compute the number of increasing subsequences of S with length K (1 ≤ K ≤ 50 and K ≤ N); that is,
 the number of K-tuples i1, ..., iK such that 1 ≤ i1 < ... < iK ≤ N and Si1 < ... < SiK.
Input

The first line contains the two integers N and K. The following N lines contain the integers of the sequence in order.

Output

Print a single integer representing the number of increasing subsequences of S of length K, modulo 5,000,000.

Sample Input

4 3
1
2
2
10

Output:

2


*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rem 5000000
void update(ll index,ll s_index,ll value,ll **bit,ll max)
{
    for(;s_index<=max;s_index+=s_index&(-s_index))
    {
        bit[index][s_index]+=value;
    }
}
ll query(ll index,ll s_index,ll **bit)
{
    ll sum=0;
    for(;s_index>0;s_index-=(s_index)&(-s_index))
    {
        sum+=bit[index][s_index];
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll **bit=new ll*[k+1];

    ll *arr=new ll[n];
    ll max=INT_MIN;
    for(ll i=0;i<n;i++)
    {    
        cin>>arr[i];
    	arr[i]++;
        if(max<arr[i])
        max=arr[i];
	}
    for(ll i=0;i<=k;i++)
    {
        bit[i]=new ll[max+1];
        for(ll j=0;j<=max;j++)
        bit[i][j]=0;
    }
    ll *n_sub=new ll[n]();
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ll a=0;
        for(ll j=1;j<=k;j++)
        {
            
            if(j==1)
            {
                a=1;
            }
            else
            {
                a=query(j-1,arr[i]-1,bit);
            }
            update(j,arr[i],a%rem,bit,max);

        }
    }
    ans=(ans+query(k,max,bit))%rem;
    cout<<ans%rem<<endl;
    for(ll j=0;j<=k;j++)
    delete [] bit[j];
    delete [] bit;
}
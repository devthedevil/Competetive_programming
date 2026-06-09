/*
Given a sequence of n numbers a1, a2, ..., an and a number of k- queries. A k-query is a triple (i, j, k) 
(1 ≤ i ≤ j ≤ n). For each k-query (i, j, k), you have to return the number of elements greater than k in the subsequence ai, ai+1, ..., aj.
Input Format

Line 1: n (1 ≤ n ≤ 30000).

Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^9).

Line 3: q (1 ≤ q ≤ 200000), the number of k- queries.

In the next q lines, each line contains 3 numbers i, j, k representing a k-query (1 ≤ i ≤ j ≤ n, 1 ≤ k ≤ 10^9).

Output Format

For each k-query (i, j, k), print the number of elements greater than k in the subsequence ai, ai+1, ..., aj in a single line.

Sample Input

5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2 

Sample Output

2
0
3 


*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class event
{
    public:
    ll value;
    ll left;
    ll right;
    ll index;
};
bool com(event e1,event e2)
{
    if(e1.value==e2.value)
    return e1.left>e2.left;

    return e1.value>e2.value;   
}
void update(ll index,ll *BIT,ll n)
{
    for(;index<=n;index+=index&-(index))
    {
        BIT[index]++;
    }

}
ll query(ll index,ll *BIT)
{
    ll sum=0;
    for(;index>0;index-=index&(-index))
    {
        sum+=BIT[index];
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n,k,q,j;
    cin>>n;
    ll *arr=new ll [n]();
    for(ll l=0;l<n;l++)
    {
        cin>>arr[l];
    }
    cin>>q;
    event* e=new event[q+n];
    for(int l=0;l<q;l++)
    {
    cin>>e[l].left>>e[l].right>>e[l].value;
    e[l].index=l;
    }
    for(ll i=0;i<n;i++)
    {
        e[q+i].left=-1;
        e[q+i].right=i+1;
        e[q+i].value=arr[i];
        e[q+i].index=-1;
    }
    sort(e,e+q+n,com);
    ll *ans=new ll [q]();
    ll *BIT=new ll [n+1]();
    for(ll i=0;i<(q+n);i++)
    {
        if(e[i].left==-1)
        {
            update(e[i].right,BIT,n);
        }
        else
        {
            // cout<<query(e[i].right,BIT)<<endl;
            ans[e[i].index]=query(e[i].right,BIT)-query(e[i].left-1,BIT);
        }
        
    }
    // for(i=0;i<n;i++)
    //     cout<<BIT[i]<<endl;
    for(ll i=0;i<q;i++)
    cout<<ans[i]<<endl;

}
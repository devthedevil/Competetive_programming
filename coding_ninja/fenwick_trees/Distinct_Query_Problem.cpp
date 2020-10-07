/*
Given a sequence of n numbers a1, a2, ..., an and a number of d-queries. A d-query is a pair (i, j) 
(1 ≤ i ≤ j ≤ n). For each d-query (i, j), you have to return the number of distinct elements in the subsequence ai, ai+1, ..., aj.
Input

Line 1: n (1 ≤ n ≤ 30000).
Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^6).
Line 3: q (1 ≤ q ≤ 200000), the number of d-queries.
In the next q lines, each line contains 2 numbers i, j representing a d-query (1 ≤ i ≤ j ≤ n).

Output

For each d-query (i, j), print the number of distinct elements in the subsequence ai, ai+1, ..., aj in a single line.

Sample Input

5
1 1 2 1 3
3
1 5
2 4
3 5

Sample Output

3
2
3 


*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class event
{
    public:
    int first,second,index;
};
bool com(event a,event b)
{
    return a.second<b.second;
}
void update(ll index,ll value,ll n,ll *BIT)
{
    for(;index<=n;index+=index&(-index))
    BIT[index]+=value;    
}
ll value(ll index,ll *BIT)
{
    ll sum=0;
    for(;index>0;index-=index&(-index))
    sum+=BIT[index];
    return sum;
}

int main()
{
    ll n;
    cin>>n;
    ll *arr=new ll [n+1];
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    ll q;
    cin>>q;
    event *query=new event[q];
    for(ll i=0;i<q;i++)
    {
        cin>>query[i].first>>query[i].second;
        query[i].index=i;
    }
    sort(query,query+q,com);
    ll *last=new ll[1000001];
    for(ll i=0;i<=1000000;i++)
        last[i]=-1;
    ll *BIT=new ll [n+1]();
    ll *ans=new ll [q]();
    ll k=0;
    ll total=0;
    for(ll i=1;i<=n;i++)
    {
        if(last[arr[i]]!=-1)
        {
            update(last[arr[i]],-1,n,BIT);
        }
        else
        {
            total++;
            
        }
        update(i,1,n,BIT);
        last[arr[i]]=i;
        while(k<q && query[k].second==i)
        {
            ans[query[k].index]=total - value(query[k].first-1,BIT);
            k++;
        }
    }
    for(ll i=0;i<q;i++)
    cout<<ans[i]<<endl;
}

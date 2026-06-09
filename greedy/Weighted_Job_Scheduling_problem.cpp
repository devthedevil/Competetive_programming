/*
 Weighted Job Scheduling
Send Feedback
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input

The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, 
finish time and the profit associated with the ith job. 

Output

Output one integer, the maximum profit that can be achieved.

Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input

4
3 10 20
1 2 50
6 19 100
2 100 200

Sample Output

250


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
class job
{
    public:
    ll st,ft,pro;
};
bool com(job a,job b)
{
    return a.ft<b.ft;
}
void bsearch(ll s,ll e,job a,job *arr, ll &index)
{
    if(s<0)
        return ;
    if(s>e)
        return ;
    ll mid=(s+e)/2;
    if(arr[mid].ft<=a.st)
    {
        index=mid;
        return bsearch(mid+1,e,a,arr,index);
    }
    else
        return bsearch(s,mid-1,a,arr,index);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    job *arr =new job[n];
    for(ll i=0;i<n;i++)
    cin>>arr[i].st>>arr[i].ft>>arr[i].pro;
    sort(arr,arr+n,com);
    vector<ll> dp(n,0);
    dp[0]=arr[0].pro;
    for(ll i=1;i<n;i++)
    {
        ll including=arr[i].pro;
         // cout<<including<<" incl 1"<<endl;
        ll lindex=-1;
        // for(ll j=i-1;j>=0;j--)
        // {
        //     if(arr[j].ft<=arr[i].st)
        //     {lindex=j;break;}
        // }
        bsearch(0,i-1,arr[i],arr,lindex);
        // cout<<lindex<<" lindex "<<endl;
        if (lindex!=-1)
        including+=dp[lindex];
         // cout<<including<<" incl 2"<<endl;
        dp[i]=max(dp[i-1],including);
        // cout<<dp[i]<<endl;
        // cout<<including<<" incl 3"<<endl;
        // cout<<endl;
    }
    cout<<dp[n-1]<<endl;
    
}

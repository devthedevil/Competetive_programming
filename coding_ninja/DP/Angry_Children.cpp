/*
 Angry Children
Send Feedback
Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies and would like to distribute one packet to each 
of the K children in the village (each packet may contain different number of candies). To avoid a fight between the children, he would like to pick K 
out of N packets such that the unfairness is minimized.
Suppose the K packets have (x1, x2, x3,....xk) candies in them, where xi denotes the number of candies in the ith packet, then we define unfairness as

unfairness=0;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
    unfairness+=abs(xi-xj)

abs(x) denotes absolute value of x.
Input Format

The first line contains an integer N.
The second line contains an integer K.
N lines follow each integer containing the candy in the ith packet.

Output Format

A single integer which will be minimum unfairness.

Constraints

2<=N<=10^5

2<=K<=N

0<= number of candies in each packet <=10^9

Sample Input

7
3
10
100
300
200
1000
20
30

Sample Output

40

Explanation

Bill Gates will choose packets having 10, 20 and 30 candies.So unfairness will be |10-20| + |20-30| + |10-30| = 40. We can verify that it 
will be minimum in this way.


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int main()
{
    ll n,k;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    ll *arr=new ll[n];
    
    for(ll i=0;i<n;i++)
    cin>>arr[i];
    sort(arr,arr+n);
    ll cost[n],sum[k];
    cost[0]=0;
    cost[1]=arr[1]-arr[0];
    sum[0]=arr[0];
    for(ll i=1;i<k-1;i++)
    sum[i]=arr[i]+sum[i-1];
    for(ll i=2;i<k;i++)
    {
        cost[i]=cost[i-1]+i*arr[i]-sum[i-1];
        // cout<<cost[i]<<" "<<sum[i-1]<<endl;
    }
    ll ans=cost[k-1];
// cout<<endl;
    for(ll i=k;i<n;i++)
    {
        sum[i-1]=sum[i-2]-arr[i-k]+arr[i-1];
        cost[i]=cost[i-1]-2*sum[i-1]+(k-1)*(arr[i-k]+arr[i]);
        if(cost[i]<ans)
        ans=cost[i];

    }
    cout<<ans<<endl;   
}

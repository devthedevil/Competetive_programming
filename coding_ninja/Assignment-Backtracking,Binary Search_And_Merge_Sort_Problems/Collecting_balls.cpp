/*
There are ‘n’ number of balls in a container. Mr. Sharma and Singh want to take balls out from the 
container. At each step, Mr. Sharma took ‘k’ balls out of the box and Mr. Singh took one-tenth of the 
remaining balls. Suppose there are 29 balls at the moment and k=4. Then, Mr. Sharma will take 4 balls and Mr. Singh will take 2 balls (29-4 = 25; 25/10 = 2). 
If there are less than ‘k’ balls remaining at some moment, then Mr. Sharma will take all the balls which will get the container empty. The process will 
last until the container becomes empty. Your task is to choose minimal ‘k’ for Mr. Sharma such that Mr. Sharma will take at least half of the balls from 
the container.
Input Format:

The Only line of input contains a single integer ‘n’.
Output Format:

Print a single integer denoting the minimal value of ‘k’.

Constraints:

1 <= n <= 10^18
Time Limit: 1 second

Sample Input:

68

Sample Output:

3

Explanation:

68-3 = 65; 65/10 = 6; 65-6 = 59
59-3 = 56; 56/10 = 5; 56-5 = 51
51-3 = 48; 48/10 = 4; 48-4 = 44
44-3 = 41; 41/10 = 4; 41-4 = 37
…..
…..
…..
6-3 = 3; 3/10 = 0; 3-0 = 3
3-3 = 0; 0/10 = 0; 0-0 = 0


*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool check(ll n,ll k)
{
    if(k==0)
        return false;
    ll sum=0;
    ll money;
    if(n%2==0)
        money=n/2;
    else
        money=n/2+1;
    while ((n>0))
    {
        sum+=min(n,k);
        n-=k;
        n=n-(n/10);
    }
    if(sum>=money) 
    return true; 
    else
    return false;

    
}
void b_search(ll &ans,ll n,ll start,ll end)
{
    if(start>end)
    return ;
    else
    {
       ll mid=(start+end)/2;
       if(check(n,mid))
       {
           ans=mid;
           b_search(ans,n,start,mid-1);
       }
       else
       {
           b_search(ans,n,mid+1,end);
       }
       


    }
    
    

}
int main()
{
	ll n;
    cin>>n;
    ll ans;
    b_search(ans,n,0,n);
    cout<<ans<<endl;
}

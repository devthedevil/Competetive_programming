/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. 
The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each 
other once put into a stall. To prevent the cows from hurting each other,
 FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible.
  What is the largest minimum distance?
*/
#include<bits/stdc++.h>
using namespace std;
bool arrange(long long *stall ,long long d,long long  n,long long cow)
{
    long long last_stall=stall[0];
    long long count=1;
    for(long long i=1;i<n;i++)
    {
        
        if(stall[i]-last_stall>=d)
        {
            count++;
            last_stall=stall[i];
            
        }
        if(count==cow)
        {
            return true;
        }
    }
    return false;
        
}
long long find(long long *stall,long long n,long long cow)
{
    long long ans;
    long long d=stall[n-1]-stall[0];
    long long start=0;
    long long end=d;
    
        while(start<=end)
        {
            long long mid=start+(end-start)/2;
            if(arrange(stall,mid,n,cow))
            {   
                ans=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
    return ans;
    
}
int main() 
{
    long long t,n,cow,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>cow;
        long long stall[n];
        for(i=0;i<n;i++)
        {
            cin>>stall[i];
        }
        sort(stall,stall+n);
        cout<<find(stall,n,cow)<<endl;
     
    }
}

	
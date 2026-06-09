/*
 Sehwag And ETF
Send Feedback
Sehwag has been solving a lot of mathematical problems recently. He was learning ETF (Euler Totient Function)
 and found the topic quite interesting. So, he tried solving a question on ETF. He will be given two numbers L and R. He has to find the probability that the ETF of a number in the range [L, R] is divisible by a number K.
Input:

The first line contains the number of test cases i.e. T.
The next T lines will contain three integers L, R and K.

Output:

Print the answer in a new line after rounding off the first 6 digits after the decimal place.

Constraints:

1 <= T <= 10
1 <= L <= R <= 10^12
0 <= R - L <= 10^5
1 <= K <= 10^6

Sample Input:

3
1 4 2
2 5 2
3 10 4

Sample Output:

0.500000
0.750000
0.375000


*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lim 1000001
#define ll long long int
vector<ll> seive()
{
    bool isprime[lim];
    memset(isprime,1,sizeof(isprime));
    isprime[0]=isprime[1]=0;
    for(ll i=2;i<lim;i++)
    {
        if(isprime[i])
        {
            for(ll j=i*i;j<lim;j+=i)
            isprime[j]=0;
            
        }
    }
    vector<ll> v;
    v.push_back(2);
    for(ll i=3;i<lim;i+=2)
    if(isprime[i])
    v.push_back(i);
    return v;
}
double solve(vector<ll> s,ll k,ll l,ll r)
{
    if(k==1)
        return 1;
    ll phi[r-l+1];
    ll d[r-l+1];
    ll in=l,num;
    
    // for(ll i=0;i<100;i++)
    //     cout<<s[i]<<" ";
    // cout<<endl;
    for(ll i=0;i<(r-l+1);i++)
    {
        phi[i]=in;
        d[i]=in++;
    }
    
    
    for(ll i=0;s[i]*s[i]<=r;i++)
    {
        ll curr=(l/s[i])*s[i];
        if(curr<l)
        curr+=s[i];
        if(curr==s[i])
        curr+=s[i];
        for(ll j=curr;j<=r;j+=s[i])
        {
            phi[j-l]=(phi[j-l]*(s[i]-1))/s[i];
            while(d[j-l]%s[i]==0)
            d[j-l]=d[j-l]/s[i];
        }
    }
    // for(ll i=l;i<=r;i++)
//     {
        
// 	cout<<phi[i-l]<<" ";
        
//     }
//     cout<<endl;
    for(ll i=l;i<=r;i++)
    {
        if(d[i-l]!=1)
        phi[i-l]=(phi[i-l]*(d[i-l]-1))/d[i-l];
	// cout<<phi[i-l]<<" ";
        
    }
    // cout<<endl;
	// for(ll i=0;i<(r-l+1);i++)
	// cout<<arr[i]<<" ";
	// cout<<endl;
    double count=0;
    for(ll i=0;i<(r-l+1);i++)
    {
        if(phi[i]%k==0)
        count++;
    }
    double ret=count/(r-l+1);
    // return r-l+1;
    return ret;
}
int main()
{
    ll t,l,r,k;
    vector<ll> s=seive();
    cin>>t;
    while(t--)
    {

        cin>>l>>r>>k;
        cout<<fixed;
        cout<<setprecision(6);
        cout<<solve(s,k,l,r)<<endl;
    }
}
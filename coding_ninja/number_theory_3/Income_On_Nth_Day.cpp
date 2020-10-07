/*
 Income On Nth Day
Send Feedback
Daulat Ram is an affluent business man. After demonetization, IT raid was held at his accommodation in which all his money was seized. He is very eager to gain his money back, he started investing in certain ventures and earned out of them. On the first day, his income was Rs. X, followed by Rs. Y on the second day. Daulat Ram observed his growth as a function and wanted to calculate his income on the Nth day.
The function he found out was FN = FN-1 + FN-2 + FN-1×FN-2
Given his income on day 0 and day 1, calculate his income on the Nth day (yeah Its that simple).
Input:

The first line of input consists of a single integer T denoting number of test cases.

Each of the next T lines consists of three integers F0, F1 and N respectively.

Output:

For each test case, print a single integer FN, as the output can be large, calculate the answer modulo 10^9+7.

CONSTRAINTS:

1 ≤ T ≤ 10^5

0 ≤ F0, F1, N ≤ 10^9

Sample Input :

2
0 1 2
1 2 4

Sample Output:

1
107

Explanation

In the second test case his income on day 0 is 1 and the income on day 1 is 2. We need to calculate his income on day 4.

F0=1

F1=2

F2=1 + 2 + 1×2 = 5

F3=2 + 5 + 2×5 = 17

F4=5 + 17 + 5×17 = 107


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define mod1 1000000006
ll modexp(ll a,ll b,ll c)
{
    if(a==0)
    return 0;

    ll ans=1;
    while (b!=0)
    {
        if( b&1 == 1 )
        {
            ans=((ans%c)*(a%c))%c;
        }
        a=((a%c)*(a%c))%c;
        b/=2;
    }
    
    return ans;
}
void multiply(ll a[][2],ll m[][2])
{
    ll fv=(a[0][0]%mod1)*(m[0][0]%mod1)+(a[0][1]%mod1)*(m[1][0]%mod1);
    ll sv=(a[0][0]%mod1)*(m[0][1]%mod1)+(a[0][1]%mod1)*(m[1][1]%mod1);
    ll tv=(a[1][0]%mod1)*(m[0][0]%mod1)+(a[1][1]%mod1)*(m[1][0]%mod1);
    ll lv=(a[1][0]%mod1)*(m[0][1]%mod1)+(a[1][1]%mod1)*(m[1][1]%mod1);

    a[0][0]=fv%mod1; //first value
    a[0][1]=sv%mod1; //second value
    a[1][0]=tv%mod1; //third value
    a[1][1]=lv%mod1; //fourth value
}
void power(ll a[][2],ll n)
{
    if(n==0 || n==1)
    return;

    power(a,n/2);
    //multiplying a^n/2 with a^n/2
    multiply(a,a);
    if(n%2!=0)
    {
        ll m[2][2]={{1,1},{1,0}};
        multiply(a,m);
    }

}
ll fib(ll n)
{
    if(n==0 || n==1)
    return n;
    ll A[2][2]={{1,1},{1,0}};
    power(A,n-1);
    return A[0][0]%mod;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,k,f0,f1,a,b;
    cin>>t;
    while(t--)
    {
        cin>>f0>>f1>>n;
        if(n==0)
        cout<<f0<<endl;
        else if(n==1)
        cout<<f1<<endl;
        else
        {
            
        
        
        a=f0+1;
        b=f1+1;
        ll ft=modexp(a,fib(n-1)%mod1,mod)%mod;
        ll st=modexp(b,fib(n)%mod1,mod)%mod;
        ll gn=(ft*st)%mod;
        cout<<(gn-1)<<endl;
        }

    }

}

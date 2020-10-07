#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
bool check(ll n)
{
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,k,count=0;
    scanf("%lld",&n);
    for(ll i=2;i<=n;i++)
    {
        if(check(i))
        count++;

    }
    cout<<count<<endl;
    
        // for(ll i=0;i<n;i++)


}

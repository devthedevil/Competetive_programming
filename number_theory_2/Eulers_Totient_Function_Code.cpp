#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
void eulerphi(ll n)
{
    ll phi[n+1];
    for(ll i=0;i<=n;i++)
    phi[i]=i;
    for(ll i=2;i<=n;i++)
    {
        if(phi[i]==i)
        {
            phi[i]=i-1;
            for(ll j=2*i;j<=n;j+=i)
            {
                phi[j]=(phi[j]*(i-1))/i;
                // phi[j]/=i;
            }
        }
        // cout<<"a"<<endl;
    }
    for(ll i=1;i<=n;i++)
    cout<<" Eulers_Totient_PHI_for "<<i<<" is " <<phi[i]<<endl;
    // cout<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    eulerphi(n);
    

}

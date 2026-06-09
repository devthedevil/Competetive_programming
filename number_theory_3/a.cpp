#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	// Write your code here
   ll m=1000001;
    //sieve of prime
    vector<bool> sieve(m,true);
    sieve[0]=sieve[1]=false;
    for(ll i=2;i*i<m;i++)
    {
        if(sieve[i])
        {
            for(ll j=i*i;j<m;j+=i)
                sieve[j]=false;
        }
    }
    
    vector<ll> primes;
    primes.push_back(2);
    for(ll i=3;i<m;i+=2)
    {
        if(sieve[i])
            primes.push_back(i);
    }
    
    
    
    int t;
    cin>>t;
    while(t--)
    {
        ll l,r,k;
        cin>>l>>r>>k;
        vector<ll> phi(r-l+1,0);
        vector<ll> d(r-l+1,0);
        for(ll i=0,x=l;i<=(r-l);i++)
        {
            d[i]=x;
            phi[i]=x++;
        }
        for(ll i=0;i<primes.size();i++)
        {
            ll p=primes[i];
            ll base=(l/p)*p;
            if(base<l)
                base+=p;
            for(ll j=base;j<=r;j+=p)
            {
                phi[j-l]=(phi[j-l]*(p-1))/p;
                while(d[j-l]%p==0)
                    d[j-l]/=p;
            }
            
        }
        float count=0;
        for(ll i=0;i<=r-l;i++)
        {
            // cout<<phi[i]<<' ';
            if(d[i]>1)
            {
                phi[i]=(phi[i]*(d[i]-1))/d[i];
            }
            if(phi[i]%k==0)
                count++;
        }
        // cout<<endl;
        float ans=(count)/(r-l+1);
        cout<<fixed<<setprecision(6)<<ans<<endl;
        
    }
}
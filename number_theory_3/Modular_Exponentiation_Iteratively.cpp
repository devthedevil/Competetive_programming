#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll modexp(int a,int b,int c)
{
    if(a==0)
    return 0;

    ll ans=1;
    while (b!=0)
    {
        if( b&1 == 1 )
        {
            //  cout<<ans<<" ans "<<b<<" b "<<a<<" a before"<<endl;
            ans=(ans*a)%c;
            
            
        }
        a=(a*a)%c;
        b/=2;
        // cout<<ans<<" ans "<<b<<" b "<<a<<" a after"<<endl;
    }
    
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a=2;
    int b=7;
    int c=5;
    cout<<modexp(a,b,c)<<endl;

}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
class Triplet
{
    public:
    ll x,y,gcd;
};
Triplet extentedEuclid(ll a,ll b)
{
    //assumption a>b
    //base case
    if(b==0)
    {
        Triplet answer;
        answer.x=1;
        answer.y=0;
        answer.gcd=a;
        return answer;
    }
// Extented Euclid algo 
  Triplet smallans=extentedEuclid(b,a%b);
  Triplet ans;
  ans.gcd=smallans.gcd;
  ans.x=smallans.y;
  ans.y=smallans.x-(a/b)*smallans.y;
  return ans;
}
ll MMinverse(ll a,ll m)
{
    Triplet ans;
    ans=extentedEuclid(a,m);
    return ans.x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,k;
    ll a=5,m=17;
    
    ll ans=MMinverse(a,m);
    // cout<<ans.x<<" "<<ans.y<<" "<<ans.gcd<<endl;
    cout<<"Multiplicative Modulo inverse "<<ans<<endl;

}

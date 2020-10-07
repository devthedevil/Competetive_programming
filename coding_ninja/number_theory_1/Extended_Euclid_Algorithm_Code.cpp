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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,k;
    ll a=15,b=10;
    Triplet ans;
    ans=extentedEuclid(a,b);
    cout<<ans.x<<" "<<ans.y<<" "<<ans.gcd<<endl;

}

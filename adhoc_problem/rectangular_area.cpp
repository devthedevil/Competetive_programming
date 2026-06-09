#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin>>n;
    ll *height=new ll[5000000+2]();
    ll max_x=0;
    for(ll i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        height[x/2]=y;
        if(x/2>max_x)
        max_x=x/2;
    }
    ll area=0;
    for(ll i=max_x;i>0;i--)
    {
        if(height[i]<height[i+1])
        height[i]=height[i+1];
        area+=height[i];

    }
    cout<<2*area<<endl;
}
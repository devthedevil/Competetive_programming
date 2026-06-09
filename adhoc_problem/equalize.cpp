#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,cost=0;
    cin>>n;
    string s, t;
    cin>>s>>t;
    for(ll i=0;i<n;)
    {
        if(s[i]!=t[i])
        {
            if(i+1<n && s[i]!=s[i+1] && t[i+1]!=s[i+1])
            {
                swap(s[i],s[i+1]);
                cost++;
                i+=2;
            }
            else
            {
                s[i]=t[i];
                cost++;
                i++;
            }
            

        }
        else
        {
            i++;
        }
        
    }
    cout<<cost<<endl;
}
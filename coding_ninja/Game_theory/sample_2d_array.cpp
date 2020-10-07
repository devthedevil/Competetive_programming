#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,k,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ll **mat=new ll*[n];
        for(ll i=0;i<n;i++)
        {
            mat[i]=new ll[m];
            for(ll j=0;j<m;j++)
            cin>>mat[i][j];
        }

        
        for(ll i=0;i<n;i++)
        delete [] mat[i];
        delete [] mat;

    }

}

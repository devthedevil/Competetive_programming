//assuming graph is connected.
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool bipartite(vector<ll> *edge,ll n)
{
    if(n==0)
    return true;

    unordered_set<ll> set[2];
    vector<ll> pending;
    pending.push_back(0);
    set[0].insert(0);
    while(pending.size()>0)
    {
        ll curr=pending.back();
        pending.pop_back();
        ll currentset=set[0].count(curr)>0 ? 0 : 1;
        for(ll i=0;i<edge[curr].size();i++)
        {
            int neigh=edge[curr][i];
            if(set[0].count(neigh)==0 && set[1].count(neigh)==0)
            {
            set[1-currentset].insert(neigh);
            pending.push_back(neigh);
            }
            else if(set[currentset].count(neigh)>0)
            {
                cout<<curr<<" "<<neigh<<endl;
                return false;
            }
        }
    }
    return true;
}
int main()
{
    while(1)
    {
        ll n,m,a,b;
        cin>>n;
        if(n==0)
        break;
        cin>>m;
        vector<ll>* edge=new vector<ll>[n];
        for(ll i=0;i<m;i++)
        {
            cin>>a>>b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        // bool ans=true;
        bool ans=bipartite(edge,n);
        delete [] edge;
        if(ans)
        {
            cout<<"BICOLOURABLE"<<endl;
        }
        else
        {
            cout<<"NOT BICOLOURABLE"<<endl;
        }
        



    }
}
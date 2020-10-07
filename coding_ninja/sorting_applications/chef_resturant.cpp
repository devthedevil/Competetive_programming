/*
Chef is a cook and he has recently opened a restaurant.

The restaurant is open during N
time intervals [L1,R1),[L2,R2),…,[LN,RN). No two of these intervals overlap — formally, for each valid i, j such that i≠j, either Ri<Lj or Rj<Li

.

M
people (numbered 1 through M) are planning to eat at the restaurant; let's denote the time when the i-th person arrives by Pi

. If the restaurant is open at that time, this person does not have to wait, but if it is closed, this person will wait until it is open.
 Note that if this person arrives at an exact time when the restaurant is closing, they have to wait for the next opening time.

For each person, calculate how long they have to wait (possibly 0
time), or determine that they will wait forever for the restaurant to open.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,start,end;
        cin>>n>>m;
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++)
        {
            cin>>start>>end;
            vec.push_back(make_pair(start,end));
        }
        sort(vec.begin(),vec.end());
        while(m--)
        {
            int curr;
            cin>>curr;
            int pos=lower_bound(vec.begin(),vec.end(),make_pair(curr,0))-vec.begin();
            if(pos==0)
            {
                cout<<vec[0].first-curr<<endl;
            }
            else
            {
                int ans=-1;
                if(pos<vec.size())
                {
                    if(vec[pos-1].second>curr)
                    cout<<0<<endl;
                
                    else
                    cout<<vec[pos].first-curr<<endl;
                }
                else
                {
                    cout<<ans<<endl;
                }
                
                


            }
            
            
            
            
        }
    }
}
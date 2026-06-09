/*
This problem was asked in LinkedIn, Google and Facebook.
Given a list of non-overlapping intervals sorted by their start time, insert a given interval at the correct position and merge all necessary intervals to produce a list that has only mutually exclusive intervals.
Example 1:
Input: Intervals=[[1,3], [5,7], [8,12]],
New Interval=[4,6]
Output: [[1,3], [4,7], [8,12]]
Explanation: After insertion, since [4,6] overlaps with [5,7], we merged them into one [4,7].
Example 2:
Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,10]
Output: [[1,3], [4,12]]
Explanation: After insertion, since [4,10] overlaps with [5,7] & [8,12], we merged them into [4,12].
Example 3:
Input: Intervals=[[2,3],[5,7]], New Interval=[1,4]
Output: [[1,4], [5,7]]
Explanation: After insertion, since [1,4] overlaps with [2,3], we merged them into one [1,4].
*/
#include <bits/stdc++.h>
using namespace std;
bool overlap(pair<int,int> t1,pair<int,int> t2)
{
    if(t1.first>t2.first) swap(t1,t2);
    return (t1.second>t2.first);

}
int main()
{
    int n,start,end;
    cin>>n;
    vector<pair<int,int>> in;
    for(int i=0;i<n;++i)
    {
        cin>>start>>end;
       in.push_back(make_pair(start,end));
    }
    cin>>start>>end;
    pair <int,int> given=make_pair(start,end);
    vector<pair<int,int>> ret;
    for(int i=0;i<n;i++)
    {
        if(overlap(given,in[i]))
        {
            int st=min(in[i].first,given.first);
            int ft=max(in[i].second,given.second);
            given=make_pair(st,ft);
           // cout<<given.first<<" "<<given.second<<" i"<<i<<endl;

        }
        else
        {
            if(given.first<in[i].first)
            {
              //  cout<<in[i].first<<" "<<in[i].second<<endl;
                ret.push_back(given);
                given=in[i];

            }
            else
            {
             ret.push_back(in[i]);   
            }
            
        }
        

    }
    ret.push_back(given);
    vector<pair<int,int>> :: iterator it;
    for(it=ret.begin();it!=ret.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
}
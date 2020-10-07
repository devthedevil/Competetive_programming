/*
Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.

Also he believes that there are M good pairs of integers (ai , bi). Kevin can perform following operation with his permutation:

Swap Px and Py only if (x, y) is a good pair.
Help him and tell if Kevin can obtain permutation Q using such operations.

Input format:

The first line of input will contain an integer T, denoting the number of test cases.

Each test case starts with two space-separated integers N and M. The next line contains N space-separated integers Pi.
 The next line contains N space-separated integers Qi. Each of the next M lines contains two space-separated integers ai and bi.

Output format:

For every test case output "YES" (without quotes) if Kevin can obtain permutation Q and "NO" otherwise.

Constraints:

1 ≤ T ≤ 10
2 ≤ N ≤ 100000
1 ≤ M ≤ 100000
1 ≤ Pi, Qi ≤ N. Pi and Qi are all distinct.
1 ≤ ai < bi ≤ N

SAMPLE INPUT

2
4 1
1 3 2 4
1 4 2 3
3 4
4 1
1 3 2 4
1 4 2 3
2 4

SAMPLE OUTPUT

NO 
YES


*/
#include <bits/stdc++.h>
using namespace std;
void dfs(unordered_set <int> *component,int n,vector<int> *edge,bool *visited)
{
    visited[n]=true;
    component->insert(n);
    for(int i=0;i<edge[n].size();i++ )
    {
        int next=edge[n][i];
        if(!visited[next])
        {
            dfs(component,next,edge,visited);
        }
    }
}
unordered_set< unordered_set <int>* >* connectedcomponent(vector<int>* edge,int n)
{
    bool* visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    unordered_set< unordered_set <int>* >* output=new unordered_set< unordered_set <int>* >();
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            unordered_set<int>* component=new unordered_set<int>();
            dfs(component,i,edge,visited);
            output->insert(component);
        }
    }
    delete [] visited;
    return output;
}
int main()
{
	int t;
    cin>>t;
    while(t--)
    {
    int n,e,a,b;
    cin>>n>>e;
    vector<int>* edge=new vector<int>[n];
    int *p=new int[n+1];
    int *q=new int[n+1];
    for(int i=1;i<=n;i++)
        cin>>p[i];
    
    for(int i=1;i<=n;i++)
        cin>>q[i];
    
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }
    unordered_set< unordered_set <int>* >* output= connectedcomponent(edge,n);
    unordered_set< unordered_set <int>* > ::iterator it;
    int flag=0,flaga=0;
    for(it=output->begin();it!=output->end();it++)
    {
        unordered_set<int>* component=*it;
        unordered_set<int>::iterator it1;
        for(it1=component->begin();it1!=component->end();it1++)
        {
            int num=q[*it1+1];
          //  cout<<*it1+1<<" *it1+1"<<endl;
            if(num!=p[*it1+1])
            {
                flag=0;
                unordered_set<int>::iterator it2=component->begin();
                
                while(it2!=component->end())
                {
                    if(num==p[*it2+1])
                    {flag=1; break;}
                  //  cout<<num<<" "<<p[*it2+1]<<endl;
                   // cout<<*it2+1<<" *it2+1"<<endl;
                    it2++;
                }
                if(flag==0 && flaga==0)
                {
                    //cout<<"NO"<<" "<< *it1+1<<endl;
                     cout<<"NO"<<endl;
                    flaga=1;
                }
            }
            

        }
        delete component;
    }
        if(flaga==0)
        cout<<"YES"<<endl;
delete [] p;
delete [] q;
delete [] edge;
delete output;
    }



}
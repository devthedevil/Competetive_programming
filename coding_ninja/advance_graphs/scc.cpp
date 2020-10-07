#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> *edge,int start,unordered_set<int> &visited,stack <int> &finishstack)
{
    visited.insert(start);
    for(int i=0;i<edge[start].size();i++)
    {
        int next=edge[start][i];
        if(visited.count(next)==0)
        {
            
            dfs(edge,next,visited,finishstack);
            
        }
    }
    finishstack.push(start);
}
void dfs2(vector<int> *edgeT,int start,unordered_set<int> &visited,unordered_set<int> *component)
{
     component->insert(start);
    visited.insert(start);
    for(int i=0;i<edgeT[start].size();i++)
    {
        int next=edgeT[start][i];
        if(visited.count(next)==0)
        {
        dfs2(edgeT,next,visited,component);
        }
    }
}
unordered_set<unordered_set<int>*>* getSCC(vector<int> *edge,vector<int> *edgeT,int n)
{
    unordered_set<int> visited;
    stack <int> finishedvertices;
    for(int i=0;i<n;i++)
    {
        if(visited.count(i)==0)
        {
            dfs(edge,i,visited,finishedvertices);
        }
    }
    unordered_set<unordered_set<int>*>* output=new unordered_set<unordered_set<int>*>();
    visited.clear();
    while(finishedvertices.size()!=0)
    {
        int i=finishedvertices.top();
        finishedvertices.pop();

        if(visited.count(i)!=0)
        continue;

        unordered_set<int>* component=new unordered_set<int>();
           
        dfs2(edgeT,i,visited,component);
        output->insert(component);
       // delete component;
    }
    return output;
}
int main()
{
    int n,a,b;
    cin>>n;
    vector<int>* edge=new vector<int>[n];
    vector<int>* edgeT=new vector<int>[n];
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        edge[a-1].push_back(b-1);
        edgeT[b-1].push_back(a-1);
    }
    unordered_set<unordered_set<int>*>* component=getSCC(edge,edgeT,n);
    unordered_set<unordered_set<int>*> :: iterator it;
    for(it=component->begin();it!=component->end();it++)
    {
        unordered_set<int>* set=*it;
        unordered_set<int> ::iterator it1;
        for(it1=set->begin();it1!=set->end();it1++)
        {
            cout<<*it1+1<<" ";
        }
        cout<<endl;
        delete set;
    } 
    delete [] edge;
    delete [] edgeT;
    delete component;

}
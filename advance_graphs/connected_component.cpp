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
    int n,e,a,b;
    cin>>n;
    vector<int>* edge=new vector<int>[n];
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }
    unordered_set< unordered_set <int>* >* output= connectedcomponent(edge,n);
    unordered_set< unordered_set <int>* > ::iterator it;
    for(it=output->begin();it!=output->end();it++)
    {
        unordered_set<int>* component=*it;
        unordered_set<int>::iterator it1;
        for(it1=component->begin();it1!=component->end();it1++)
        {
            cout<<*it1+1<<" ";
        }
        cout<<endl;
        delete component;
    }
delete [] edge;
delete output;


}
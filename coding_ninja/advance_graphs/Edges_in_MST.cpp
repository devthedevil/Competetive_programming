/*
Edges in MST

You are given a connected weighted undirected graph without any loops and multiple edges.

Let us remind you that a graph's spanning tree is defined as an acyclic connected subgraph of the given graph 
that includes all of the graph's vertexes. The weight of a tree is defined as the sum of weights of the edges that
 the given tree contains. The minimum spanning tree (MST) of a graph is defined as the graph's spanning tree having 
 the minimum possible weight. For any connected graph obviously exists the minimum spanning tree, but in the general case, 
 a graph's minimum spanning tree is not unique.

Your task is to determine the following for each edge of the given graph: whether it is either included in any MST, or 
included at least in one MST, or not included in any MST.

Input

The first line contains two integers n and m (2 ≤ n ≤ 105, ) — the number of the graph's vertexes and edges, correspondingly.
 Then follow m lines, each of them contains three integers — the description of the graph's edges as "ai bi wi" (1 ≤ ai, bi ≤ n, 1 ≤ wi ≤ 106, ai ≠ bi),
  where ai and bi are the numbers of vertexes connected by the i-th edge, wi is the edge's weight. It is guaranteed that the graph is connected and doesn't
   contain loops or multiple edges.

Output

Print m lines — the answers for all edges. If the i-th edge is included in any MST, print "any"; if the i-th edge is included at least in 
one MST, print "at least one"; if the i-th edge isn't included in any MST, print "none". Print the answers for the edges in the order in which
 the edges are specified in the input.

Sample input 1

4 5
1 2 101
1 3 100
2 3 2
2 4 2
3 4 1

sample output 1

none
any
at least one
at least one
any

Sample input 2

3 3
1 2 1
2 3 1
1 3 2

sample output 2

any
any
none

sample input 3

3 3
1 2 1
2 3 1
1 3 1

sample output 3

at least one
at least one
at least one

Note

In the second sample the MST is unique for the given graph: it contains two first edges.

In the third sample any two edges form the MST for the given graph. That means that each edge is included at least in one MST.


*/
#include <bits/stdc++.h>
using namespace std;
class Edge
{
    public:
    int src;
    int des;
    int weight;
    int weight_count;
};
bool com(Edge e1,Edge e2)
{
    return e1.weight<e2.weight;
}
int getparent(int i,int *parent)
{
    if(i==parent[i])
    return i;
    
    return getparent(parent[i],parent);
}
bool bridge(vector<int> *adj,Edge* edge,int weigh,int *low,int *disc,bool *visited,int *par,int n,int u,int index)
{
    
   
    int static time =0;
    visited[u]=true;
    low[u]=disc[u]=++time;
    
    vector<int> ::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
        int v=*it;
        if(!visited[v])
        {
            par[v]=u;
            bridge(adj,edge,weigh,low,disc,visited,par,n,v,index);
            
            low[u]=min(low[u],low[v]);

            if(low[v]>disc[u])
            {
            	if( (edge[index].src==u && edge[index].des==v) || (edge[index].src==v && edge[index].des==u) )
                 	return true;
            }    
               
            

        }
        else if (v!=par[u])
        low[u]=min(low[u],disc[v]);

    }
    return false;
}
void check(map<pair<int,int>,string> &m, vector<int> *adj,Edge* edge,int weigh,int equal,int index,int e,int n)
{
    //inserting all the equal edges into the adjacency list without changing it. 
    for(int k=index;k<(index+equal);k++)
    {
        if(edge[k].weight==weigh)
        {
            adj[edge[k].src].push_back(edge[k].des);
        	adj[edge[k].des].push_back(edge[k].src);
        }
    }
    for(int k=index;k<(index+equal);k++)
    {
            int low[n],disc[n],par[n];
    		for(int i=0;i<n;i++)
        		par[i]=i;
   	 		bool visited[n]={false};
    	if(bridge(adj,edge,weigh,low,disc,visited,par,n,edge[k].src,k)==true)
        {
        	   m[{edge[k].src,edge[k].des}]="any";
        }
        else
        {
        	m[{edge[k].src,edge[k].des}]="at least one";
        }
    }
}
void kruskal(vector<int> *adj,map<pair<int,int>,string> &m,Edge* edge,int n,int e)
{
    sort(edge,edge+e,com);
    int count=0;
    int i=0;
    int last;
    int* parent=new int [n];
    for(int i=0;i<n;i++)
    parent[i]=i;
    Edge* output=new Edge[n-1];
    while(count<(n))
    {
        	if(getparent(edge[i].src,parent)!=getparent(edge[i].des,parent))
        	{
                //if the edge is not making a cycle and  it is unique.
                if(edge[i].weight_count==1)
                {
            	    parent[getparent(edge[i].src,parent)]=getparent(edge[i].des,parent);
            	    adj[edge[i].src].push_back(edge[i].des);
        		    adj[edge[i].des].push_back(edge[i].src);
            		
                    m[{edge[i].src,edge[i].des}]="any";
                    i++;
                    count++;
                }

                //if the edge is not making a cycle and  it is not unique.
                else //if(edge[i].weight_count>1)
                {
                    int index_sameweigh=i;
                    int weigh=edge[i].weight;
                    int equal=edge[i].weight_count;
                    vector<int> *adj1=new vector<int>[n];
                    for(int i=0;i<n;i++)
                    {
                        for(int j=0;j<adj[i].size();j++)
                        adj1[i].push_back(adj[i][j]);
                    }
                   check(m,adj1,edge,weigh,equal,i,e,n);
                    for(int k=index_sameweigh;k<(index_sameweigh+equal);k++)
                    {
                        //if the edge is not making a cycle and  it is not unique and it is a bridge.
                        if(m[{edge[k].src,edge[k].des}]=="any")
                        {
                            parent[getparent(edge[k].src,parent)]=getparent(edge[k].des,parent);
                            adj[edge[k].src].push_back(edge[k].des);
                            adj[edge[k].des].push_back(edge[k].src);
                            i++;
                            
                            count++;
                            
                            
                        }
                        //if the edge is not making a cycle and  it is not unique and it is not a bridge.
                        if(m[{edge[k].src,edge[k].des}]=="at least one" )//&& flag==0)
                        {
                            parent[getparent(edge[k].src,parent)]=getparent(edge[k].des,parent);
                            adj[edge[k].src].push_back(edge[k].des);
                            adj[edge[k].des].push_back(edge[k].src);
                            
                            i++;
                            
                            count++;
                            
                        }
                    
                    }
                    delete [] adj1;
                
                }
                
    		}
            //if edge is making a cycle.
        	else
        	{
            	m[{edge[i].src,edge[i].des}]="none";
                count++;
                i++;
            
            }
        	
    }  
    //rest is not in mst
    for(int j=i;j<e;j++)
        m[{edge[j].src,edge[j].des}]="none";
}

int main()
{
    int n, e,source,destination,w;
    cin >> n >> e;
    Edge* edge=new Edge[e];
    vector<int> *adj=new vector<int>[n];
    for(int i=0;i<e;i++)
    {
        cin>>source>>destination>>w;
        edge[i].src=source-1;
        edge[i].des=destination-1;
        edge[i].weight=w;
    }
    int count=0;
    for(int i=0;i<e;i++)
    {
        count =0;
        int x=edge[i].weight;
        for(int j=0;j<e;j++)
        {
            if(x==edge[j].weight)
                count++;
        }
        edge[i].weight_count=count;
    }
    pair<int,int> arr[e];
    for(int i=0;i<e;i++)
    {
        arr[i].first=edge[i].src;
        arr[i].second=edge[i].des;
    }
    map<pair<int,int>,string> m;

		 kruskal(adj,m,edge,n,e);
		
		for(int i=0;i<e;i++)
		{
		cout<<m[{arr[i].first,arr[i].second}]<<endl;
		}
}
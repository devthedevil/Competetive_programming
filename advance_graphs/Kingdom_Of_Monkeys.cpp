/*
This is the story in Zimbo, the kingdom officially made for monkeys. Our Code Monk visited Zimbo and declared open a challenge in the kingdom, 
thus spoke to all the monkeys :

You all have to make teams and go on a hunt for Bananas. The team that returns with the highest number of Bananas will be rewarded with as
 many gold coins as the number of Bananas with them. May the force be with you!
Given there are N monkeys in the kingdom. Each monkey who wants to team up with another monkey has to perform a ritual. Given total M 
rituals are performed. Each ritual teams up two monkeys. If Monkeys A and B teamed up and Monkeys B and C teamed up, then Monkeys A and C are also in the same team.

You are given an array A where Ai is the number of bananas i'th monkey gathers.

Find out the number of gold coins that our Monk should set aside for the prize.

Input:

First line contains an integer T. T test cases follow. First line of each test case contains two space-separated N and M. M lines follow. Each of the M lines contains two integers Xi and Yi, the indexes of monkeys that perform the i'th ritual. Last line of the testcase contains N space-separated integer constituting the array A.

Output:

Print the answer to each test case in a new line.

Constraints:

1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
0 ≤ M ≤ 10^5
0 ≤ Ai ≤ 10^12

SAMPLE INPUT

1
4 3
1 2
2 3
3 1
1 2 3 5

SAMPLE OUTPUT

6

Explanation

Monkeys 1,2 ,3 are in the same team. They gather 1+2+3=6 bananas.
Monkey 4 is a team. It gathers 5 bananas.
Therefore, number of gold coins (highest number of bananas by a team) = 6.


*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
    	int n,a,b,m;
    	cin>>n>>m;
        ll ans,max=INT_MIN;
    	vector<int>* edge=new vector<int>[n];
    	for(int i=0;i<m;i++)
    	{
        	cin>>a>>b;
        	edge[a-1].push_back(b-1);
        	edge[b-1].push_back(a-1);
    	}
    	ll *arr=new ll[n];
    	for(ll i=0;i<n;i++)
    		cin>>arr[i];
    	unordered_set< unordered_set <int>* >* output= connectedcomponent(edge,n);
    	unordered_set< unordered_set <int>* > ::iterator it;
    	for(it=output->begin();it!=output->end();it++)
    	{
        	ans=0;
        	unordered_set<int>* component=*it;
        	unordered_set<int>::iterator it1;
        for(it1=component->begin();it1!=component->end();it1++)
        {
            ans+=arr[*it1];
        }
      	if(max<ans)
          max=ans;
        delete component;
    	}
    cout<<max<<endl;
	delete [] edge;
	delete output;
    }


}
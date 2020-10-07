/*
 Strange order
Send Feedback
Given an integer n . Initially you have permutation p of size n : p[i] = i . To build new array a from p following steps are done while permutation p is not empty:
Choose maximum existing element in p and define it as x ; Choose all such y in p that gcd ( x , y ) ≠ 1 ; Add all chosen numbers into array a in decreasing order and remove them from permutation. Your task is to find a after p became empty.
Note: gcd ( a , b ) is the greatest common divisor of integers a and b .
Input format

Input contains single integer n ( 1 ≤ n ≤ 2 * 10^6) — the size of permutation p p.

Output format

Print n integers — array a .

Sample Input:

5

Sample Output:

5 4 2 3 1

Explanation

It's needed 4 iterations to create array a:
Add 5
Add 4 and 2
Add 3
Add 1


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    
    ll *lcd=new ll[n+1];
    bool visited[n+1];
    memset(visited,0,sizeof(visited));
    for(ll i=0;i<=n;i++)
    {
        lcd[i]=i;
    }
    for(ll i=2;i*i<=n;i++)
    {
        if(lcd[i]==i)
        {
            for(ll j=i*i;j<=n;j+=i)
            {
                if(lcd[j]>i)
                {
                    lcd[j]=i;
                }
            }
        }
    }
    for(ll i=n;i>0;i--)
    {
        if(!visited[i])
        {

            vector<ll> s;
            s.push_back(i);
            visited[i]=1;
            
            ll x=i;
            ll j=lcd[i];
            while(x!=1)
            {
                ll k=j;
                    while((i-k)>0)
                    {
                        if(!visited[i-k])
                        {s.push_back(i-k);
                        visited[i-k]=1;}
                        k+=j;
                    }
                    while(x%j==0)
                    {
                        x/=j;
                    }
                    j=lcd[x];
                
            }
            sort(s.begin(),s.end());
            for(auto it=s.rbegin();it!=s.rend();it++)
            {
                cout<<*it<<" ";
            }
            s.clear();
        }
    }
    cout<<endl;
}
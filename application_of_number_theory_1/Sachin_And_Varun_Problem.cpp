/*
 Sachin And Varun Problem
Send Feedback
Varun and you are talking about a movie that you have recently watched while Sachin is busy teaching Number Theory. 
Sadly, Sachin caught Varun talking to you and asked him to answer his question in order to save himself from punishment. 
The question says:
Given two weights of a and b units, in how many different ways you can achieve a weight of d units using only the given
 weights? Any of the given weights can be used any number of times (including 0 number of times).
Since Varun is not able to answer the question, he asked you to help him otherwise he will get punished.
Note: Two ways are considered different if either the number of times a is used or number of times b is used is different
in the two ways.
Input Format:

The first line of input consists of an integer 
T denoting the number of test cases.
Each test case consists of only one line containing three space separated integers a, b and d.

Output Format:

For each test case, print the answer in a separate line.

Constraints:

1 ≤T≤ 10^5

1 ≤ a < b ≤ 10^9

0≤d≤10^9

Sample Input 1

4
2 3 7
4 10 6
6 14 0
2 3 6

Sample Output 1

1
0
1
2

Explanation

Test case 1: 7 can only be achieved by using 2 two times and 3 one time.

Test case 2: 6 can't be achieved by using 4 and 10 .So, 0ways are there.


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
class Triplet
{
    public:
    ll x,y,gcd;
};
Triplet extentedEuclid(ll a,ll b)
{
    //assumption a>b
    //base case
    if(b==0)
    {
        Triplet answer;
        answer.x=1;
        answer.y=0;
        answer.gcd=a;
        return answer;
    }
// Extented Euclid algo 
  Triplet smallans=extentedEuclid(b,a%b);
  Triplet ans;
  ans.gcd=smallans.gcd;
  ans.x=smallans.y;
  ans.y=smallans.x-(a/b)*smallans.y;
  return ans;
}
ll MMinverse(ll a,ll m)
{
    ll ans;
    ans=extentedEuclid(a,m).x;
    return (ans%m+m)%m;
}
ll gcd(ll a,ll b)
{
    if(a<b)
    return gcd(b,a);
    if(b==0)
    return a;
    return gcd(b,a%b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,k;
    ll a,b,d;
    cin>>t;
    while(t--)
    {
    	cin>>a>>b>>d;
    	ll g=gcd(a,b);
    if(d%g)
    {
        cout<<0<<endl;
        continue;
    }
    if(d==0)
    {
        cout<<1<<endl;
        continue;
    }
    a/=g; b/=g; d/=g;
    ll y1;
    y1=((d%a)*MMinverse(b,a))%a;
    ll firstvaue=d/b;
    if(d < y1*b)
    {
        cout<<0<<endl;
        continue;
    }
    else
    {
        n=((d/b)-y1)/a;
        cout<<n+1<<endl;
    }

    
    }

}
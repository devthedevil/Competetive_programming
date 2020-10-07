/*
 Calculate Grundy Number
Send Feedback
Calculate the Grundy Number for the given 'n' in the game.
The game starts with a number- ‘n’ and the player to move divides the number-
 ‘n’ with 2, 3 or 6 and then takes the floor. If the integer becomes 0, it is removed.
  The last player to move wins. Which player wins the game?
Input Format

An Integer 'n'

Output Format

Grundy Number(n)

Sample Input 1 -

10

Sample Output 1-

0


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll mex(ll a,ll b,ll c)
{
    ll ans=min(a,min(b,c));
    if(ans>0)
    return 0;
    ll maxi=max(a,max(b,c));
    for( ll i=1;i<maxi;i++)
    {
        if(i!=a && i!=b && i!=c)
        return i;
    }
    return (maxi+1);
}
ll g(ll n)
{
    if(n==0)
    return 0;
    return mex(g(n/2),g(n/3),g(n/6));

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,k;
    cin>>n;
    cout<<g(n)<<endl;
        // for(ll i=0;i<n;i++)

    

}

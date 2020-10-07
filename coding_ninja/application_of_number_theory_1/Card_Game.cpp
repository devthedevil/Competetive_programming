/*
 Card Game
Send Feedback
Vova again tries to play some computer card game.
The rules of deck creation in this game are simple. Vova is given an existing deck of n cards and a magic number k. The order of the cards in the deck is fixed. Each card has a number written on it; number ai is written on the i-th card in the deck.
After receiving the deck and the magic number, Vova removes x (possibly x = 0) cards from the top of the deck, y (possibly y = 0) cards from the bottom of the deck, and the rest of the deck is his new deck (Vova has to leave at least one card in the deck after removing cards). So Vova's new deck actually contains cards x + 1, x + 2, ... n - y - 1, n - y from the original deck.
Vova's new deck is considered valid iff the product of all numbers written on the cards in his new deck is divisible by k. So Vova received a deck (possibly not a valid one) and a number k, and now he wonders, how many ways are there to choose x and y so the deck he will get after removing x cards from the top and y cards from the bottom is valid?
Input

The first line contains two integers n and k (1 ≤ n ≤ 100 000, 1 ≤ k ≤ 10^9).

The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 10^9) — the numbers written on the cards.

Output

Print the number of ways to choose x and y so the resulting deck is valid.

Sample Input 1

3 4
6 2 8

Sample Output 1

4

Sample Input 2

3 6
9 1 14

Sample Output 2

1


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ipair pair<ll,ll> 
#define MOD 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k, count=0;;
    
    cin>>n>>k;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++)
    cin>>arr[i];
    ll x=k;
    vector<ipair> ori;
    
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            ll flag=0;
            while(x%i==0)
            {
                x/=i;
                flag++;
            }
             ori.push_back({i,flag});
        }
        
    }
    if(x!=1)
    {
        ori.push_back({x,1});
    }
    vector<ipair> copy=ori;

    for(ll i=0;i<copy.size();i++)
    copy[i].second=0;

    
    int i,j=0;
    for(i=0;i<n;i++)
    {
        for(ll z=0;z<ori.size();z++)
        {
            if(arr[i]%ori[z].first==0)
            {
                x=arr[i];
                ll flag=0;
                while(x%ori[z].first==0)
                {

                    x/=ori[z].first;
                    flag++;
                }
                copy[z].second+=flag;
            }
        }
        while(j<=i)
        {
            ll z=0;
            for(z=0;z<ori.size();z++)
            {
                if(ori[z].second>copy[z].second)
                break;
                
            }
            if(z!=ori.size())
            break;
            count+=n-i;
            for(z=0;z<ori.size();z++)
            {
                if(arr[j]%ori[z].first==0)
                {
                    x=arr[j];
                    ll flag=0;
                    while(x%ori[z].first==0)
                    {

                        x/=ori[z].first;
                        flag++;
                    }
                    copy[z].second-=flag;
                }
            }
            j++;
            
        }
    }
    cout<<count;
    

    

}

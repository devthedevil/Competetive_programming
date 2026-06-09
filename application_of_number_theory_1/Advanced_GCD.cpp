/*
 Advanced GCD
Send Feedback
Varun explained its friend Sanchit the algorithm of Euclides to calculate the GCD of two numbers. Then Sanchit implements the algorithm

int gcd(int a, int b)
{

    if (b==0)
    return a;
    else
    return gcd(b,a%b);
}

and challenges to Varun to calculate gcd of two integers, one is a little integer and other integer has 250 digits.
Your task is to help Varun an efficient code for the challenge of Sanchit.
Input

The first line of the input file contains a number representing the number of lines to follow. Each line consists of two number A and B (0 <= A <= 40000 and A <= B < 10^250).

Output

Print for each pair (A,B) in the input one integer representing the GCD of A and B..

Sample Input:

2
2 6
10 11

Sample Output:

2
1

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
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
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        ll a,n=0;
        cin>>a>>s;
        if(a==0)
        {
            cout<<s<<endl;
            continue;
        }
        for(ll i=0;i<s.length();i++)
        {
            n=n*10+(s[i]-48);
            n=n%a;
        }
        cout<<gcd(a,n)<<endl;
    }

}
/*
 Cubic Square
Send Feedback
Varun is learning method of successive squaring so that he can calculate a^b mod m quickly. To give himself practice he wrote many tuples of a, b and m and went to school thinking that he will do it after school.
After school he found that tuples he wrote are modified by his little sister. His sister converted each b into base 3. Varun wrote everything in base 10.
Help Varun to do his excercise.
Input

First line of input contains a number T, number of test cases. Then T test cases follows each containing three numbers a (<=10^9), b and m (<=10^5) (a in base 10, b in base 3 and m in base 10). Number of digits in b will be less than 250.

Output

Output a number for each test case a^b mod m in base 10.

Sample Input:

2
2 10 10
3 21101 19

Sample Output:

8
3


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll modexp(ll a,string b,ll c)
{
    if(a==0)
    return 0;

    ll ans=1;
    ll i=b.length()-1;
    // cout<<b[1]<<endl;
    while (i>=0)
    {
        //   cout<<ans<<" ans "<<b[i]<<" str[i] "<<a<<"  a before"<<endl;
        if( b[i] == '1' )
        {
           
            ans=(ans*a)%c;
            // cout<<ans<<endl;
            
            
        }
        else if(b[i]=='2')
        {
            ans=( ((ans*a)%c) *a )%c;
        }
        
        a=((a*a)%c*a)%c;
        i--;
        // cout<<ans<<" ans "<<b[i]<<" str[i] "<<a<<" a after"<<endl;
    }
    
    return ans%c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,a,c;
    string b;
    cin>>t;
    while(t--)
    {
        cin>>a;
        cin>>b;
        cin>>c;
        // cout<<a<<" "<<b <<" b "<<c<<" c "<<endl;
        cout<<modexp(a,b,c)<<endl;
    }

}
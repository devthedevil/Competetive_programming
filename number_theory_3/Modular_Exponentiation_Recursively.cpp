#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int modexp(int a,int b,int c)
{
    if(a==0)
    return 0;
    if(b==0)
    return 1;
    long ans;
    if(b%2==0)
    {
        // b is even
        long small_ans=modexp(a,b/2,c);
        ans=(small_ans*small_ans)%c;
        
    }
    else
    {
        // b is odd
        int small_ans=modexp(a,b-1,c);
        ans=a%c;
        ans=(ans*small_ans)%c;
        
    }
    return int((ans+c)%c);
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a=2;
    int b=5;
    int c=5;
    cout<<modexp(a,b,c)<<endl;

}

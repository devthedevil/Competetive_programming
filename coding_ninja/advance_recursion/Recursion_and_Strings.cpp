//given a character array find its length and remove all x in the given string
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void removeX(char s[])
{
    if(s[0]=='\0')
    return;

    if(s[0]!='x')
    removeX(s+1);
    else
    {
        ll i=1;
        for(;s[i]!='\0';i++)
        {
            s[i-1]=s[i];
        }
        s[i-1]=s[i];
        removeX(s);
    }
    
}
ll length(char s[])
{
    if(s[0]=='\0')
    return 0;
    ll small_str=length(s+1);
    return 1+small_str;
}
int main()
{
    char str[100];
    cin>>str;

    cout<<length(str)<<endl;
    removeX(str);
    cout<<str<<endl;
    cout<<length(str)<<endl;
}
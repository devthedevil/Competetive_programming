/*
 Counting Strings
Send Feedback
Given a string 's' consisting of upper case alphabets, i.e. from 'A' to 'Z'. Your task is to find how many strings 't'
 with length equal to that of 's', also consisting of upper case alphabets are there satisfying the following conditions:

-> String 't' is lexicographical larger than string 's'.
-> When you write both 's' and 't' in the reverse order, 't' is still lexicographical larger than 's'.nm

Find out number of such strings 't'. As the answer could be very large, take modulo 10^9 + 7.

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define MAXN 112345
int countStrings(char* s) 
{
    ll n=strlen(s);
    ll f[MAXN][2][2];
    f[n][1][1]=1;
    for(ll pos=n-1;pos>=0;pos--)
        for(ll ok1=0;ok1<2;ok1++)
            for(ll ok2=0;ok2<2;ok2++)
                f[pos][ok1][ok2]=0;
    for(ll pos=n-1;pos>=0;pos--)
        for(ll ok1=0;ok1<2;ok1++)
            for(ll ok2=0;ok2<2;ok2++)
                {
                    for(char c= ok1==0 ?s[pos]:'A';c<='Z';c++)
                    {
                        ll nextok2=ok2;
                        if( c!=s[pos] )
                        nextok2=c>s[pos];
                        f[pos][ok1][ok2]=(f[pos][ok1][ok2]+f[pos+1][ok1 || c>s[pos]][nextok2])%MOD;


                    }
                }

    return f[0][0][0];

}


int main(){
	char s[100005];
    cin>>s;
    int ans = countStrings(s);
    cout<<ans<<endl;
}
//let s is 0-indexed
// for (int i = N - 1; i > 0; i--)
//     for (int ok1 = 0; ok1 <= 1; ok1++)
//         for (int ok2 = 0; ok2 <= 1; ok2++) 
//         {
//             //make sure that T is always lexicographically larger than S in original order
//             for (char c = ok1 == 0 ? s[i] : 'A'; c <= 'Z'; c++) 
//             {
//                 int nextOk2 = ok2;
//                 if (c != s[pos]) 
//                 {
//                     //if we put a character c > s[pos] in position pos of T then T became lexicographically larger than S in reversed order
//                     nextOk2 = c > s[pos];
//                 }

//                 f[pos][ok1][ok2] = (f[pos][ok1][ok2] + f[pos + 1][ok1 || c > s[pos]][nextOk2]) % MOD;
//             }
//         }
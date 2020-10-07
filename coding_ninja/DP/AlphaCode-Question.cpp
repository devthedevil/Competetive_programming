/*
AlphaCode-Question
Send Feedback
Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:

Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you 
would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings
 and with that many you would find at least two different ones that would make sense.”

Alice: “How many different decodings?”

Bob: “Jillions!”

For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings
 there can be for a given string using her code.
Input

Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits representing a valid 
encryption (for example, no line will begin with a 0). There will be no spaces between the digits. An input line of ‘0’ will 
terminate the input and should not be processed.

Output

For each input set, output the number of possible decodings for the input string. Print your answer taking modulo "10^9+7"

Sample Input:

25114
1111111111
3333333333
0

Sample Output:

6
89
1


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll num_codes(ll *n,ll size)
{
    if(size==0 || size==1)
    return 1;
    ll out=num_codes(n,size-1);
    if(n[size-2]*10+n[size-1]<=26)
    out+=num_codes(n,size-2);
    return out;
}
ll num_codes2(ll *n,ll size,ll *arr)
{
    if(arr[size]>0)
    return arr[size];
    if(size==0 || size==1)
    return 1;
    ll out=num_codes(n,size-1);
    if(n[size-2]*10+n[size-1]<=26)
    out+=num_codes(n,size-2);
    arr[size]=out;
    return out;
}
ll num_codes3(ll *n,ll size)
{
    ll *arr=new ll[size+1]();
    arr[0]=1;
    arr[1]=1;
    
    for(ll i=2;i<=size;i++)
    {
        // cout<<n[i-2]<<" n[i-2]"<<endl;
        if(n[i-1]!=0)
        arr[i]=arr[i-1];
        if(n[i-2]*10+n[i-1]<=26 && n[i-2]!=0)
        arr[i]=(arr[i]%mod+arr[i-2]%mod)%mod;
        // cout<<arr[i]<<" arr "<<i<<"  i "<<endl;
        // arr[i]%=mod;
    }
    ll out=arr[size];
    delete [] arr;
    return out%mod;
}
int main()
{
    while(1)
    {
        string s;
    cin>>s;
    if(s=="0")
    break;
    ll size=s.length();
    // cin>>size;
    ll *n=new ll[size+1];
    for(ll i=0;i<size;i++)
    n[i]=s[i]-'0';
    cout<<num_codes3(n,size)<<endl;
    }
}
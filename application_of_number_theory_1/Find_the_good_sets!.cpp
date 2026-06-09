/*
 Find the good sets!
Send Feedback
You are given array a consisting of n distinct integers. A set s of numbers is called good if you can rearrange the
 elements in such a way that each element divides the next element in the order, i.e. 'si' divides 'si + 1', such 
 that i < |s|, where |s| denotes size of set |s|.
Find out number of distinct good sets that you can create using the values of the array. You can use one value only 
once in a particular set; ie. a set cannot have duplicate values. Two sets are said to be different from each other
 if there exists an element in one set, which does not exist in the other.
As the answer could be large, print your answer modulo 10^9 + 7.
Input

First line of the input contains an integer T denoting the number of test cases. T test cases follow.

First line of each test case contains an integer n denoting number of elements in array a.

Next line contains n space separated integers denoting the elements of array a.

Output

For each test case, output a single line containing the corresponding answer.

Constraints

1 ≤ T ≤ 3

1 ≤ n ≤ 7.5 * 10^5

1 ≤ ai ≤ 7.5 * 10^5

All the elements of array a are distinct.

Example
Input

2
2
1 2
3
6 2 3

Output:

3
5

Explanation

Test case 1. There are three sets which are good {1}, {2}, {1, 2}.

Test case 2. There are five sets which are good {6}, {2}, {3}, {6 2}, {6, 3}.


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll *arr=new ll[1000001];
    ll n,t,num;
    cin>>t;
    while(t--)
    {
        arr[1000001]={0};
        cin>>n;
        ll *input=new ll[n];
        for(ll i=0;i<n;i++)
        {
            cin>>input[i];
            arr[input[i]]=1;
        }
        sort(input,input+n);
        for(ll i=0;i<n;i++)
        {
            num=input[i];
            while(num<=input[n-1])
            {
                num+=input[i];
                if(num<=1000000 && arr[num]>0)
                {
                    // cout<<num<<" num "<<endl;
                    arr[num]+=arr[input[i]];
                }
            }
        }
        ll ans=0;
        // cout<<input[n-1]<<" last "<<endl;
        for(ll i=0;i<n;i++)
        {
            // cout<<arr[input[i]]<<endl;
            ans+=arr[input[i]];
            ans%=MOD;
        }
        cout<<ans<<endl;
        



    }



}
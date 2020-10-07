/*
Largest Bitonic Subarray
Send Feedback
You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
Input Format:

Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 

Output Format:

Length of Largest Bitonic subsequence

Input Constraints:

1<= N <= 100000

Sample Input 1:

6
15 20 20 6 4 2

Sample Output 1:

5

Sample Output 1 Explanation:

Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.

Sample Input 2:

2
1 5

Sample Output 2:

2

Sample Input 3:

2
5 1

Sample Output 3:

2


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 	
	int longestBitonicSubarray(int *input, int n) {
		
	/* Don't write main().
     	* the input is already passed as function argument.
     	* Taking input and printing output is handled automatically.
     	*/
         
    	int inc[n];
        inc[0]=1;
        for (int i=1;i<n;i++)
        {
            inc[i]=1;
            for(int j=i-1;j>=0;j--)
            {
             if(input[i]<=input[j])
                 continue;
                int pos=inc[j]+1;
                if(pos>inc[i])
                 inc[i]=pos;
            // cout<<input[i-1]<<" "<<input[i]<<endl;
            }
        }
        int dec[n];
        dec[n-1]=1;
        for (int i=n-2;i>=0;i--)
        {
            dec[i]=1;
            for(int j=i+1;j<n;j++)
            {
            if(input[i]<=input[j])
                continue;
            int posans=dec[j]+1;
            if(posans>dec[i])
                dec[i]=posans;
            }
        }
     	int max=inc[0]+dec[0]-1;
        // for (int i=0;i<n;i++)
        // {
        //     cout<<inc[i]<<" ";
        // }
        // cout<<endl;
        // for (int i=0;i<n;i++)
        // {
        //     cout<<dec[i]<<" ";
        // }
        // cout<<endl;
        
        for (int i=1;i<n;i++)
            if(max<inc[i]+dec[i]-1)
                max=inc[i]+dec[i]-1;
        return max;
     	
 	}


int main()
{
    ll n,a;
    cin>>n;
    vector<ll> input;
    for (int i=0;i<n;i++)
    {
        cin>>a;
        input.push_back(a);
    }
    
    ll ans=lis(input);
    cout<<ans<<endl;

}
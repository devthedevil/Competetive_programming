/*
 Number of APs
Send Feedback
Given an array of n positive integers. The task is to count the number of Arithmetic Progression subsequences
 in the array. As the answer could be very large, output it modulo 100001.
Note: Empty sequence or single element sequence is Arithmetic Progression.
Input Format:

First Line: N (the size of the array)
Second Line: Elements of the array separated by spaces.

Output:

 Print total number of subsequences

Input Constraints:

1 <= arr[i] <= 1000
1 <= sizeof(arr) <= 1000

Sample Input 1 :

3
1 2 3

Sample output:

8

Sample Output Explanation:

Total subsequence are: {}, { 1 }, { 2 }, { 3 }, { 1, 2 }, { 2, 3 }, { 1, 3 }, { 1, 2, 3 }

Sample Input 2:

7
1 2 3 4 5 9 10

Sample Output:

37


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 100001
#define MAX 1001
int numofAP(int *arr, int n){
    /*
    Return all possible AP subsequences formed from the given integer array. You donot need to take input or print anything.
    Just return the ans.
    */
    int ans=n+1;
    int minarr=INT_MAX;
    int maxarr=INT_MIN;
    for(ll i=0;i<n;i++)
    {
        minarr=min(minarr,arr[i]);
        maxarr=max(maxarr,arr[i]);
    }
    // cout<<maxarr<<endl;
    // cout<<minarr<<endl;
    int *dp=new int[n+1];
    int sum[MAX];
    for(int d=(minarr-maxarr);d<=(maxarr-minarr);d++)
    {
        memset(sum,0,sizeof sum);
        for(int i=0;i<n;i++)
        {
            dp[i]=1;
            if(arr[i]-d>0 && arr[i]-d<=1000)
                dp[i]+=sum[arr[i]-d];
            
            ans=(ans%mod+(dp[i]-1)%mod)%mod;
            // cout<<ans<<" ans "<<endl;
            // cout<<dp[i]<<" dp "<<i<<" i "<<endl;
            sum[arr[i]]+=dp[i];
        }
    }
    return ans;

}


int main(){

    int N;
    cin >> N;

    int *arr = new int[N+1];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << numofAP(arr, N) << endl;

    return 0;
}

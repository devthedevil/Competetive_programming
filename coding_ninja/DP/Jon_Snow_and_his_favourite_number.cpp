/*
 Jon Snow and his favourite number
Send Feedback
Jon Snow now has to fight with White Walkers. He has n rangers, each of which has his own strength. 
Also Jon Snow has his favourite number x. Each ranger can fight with a white walker only if the strength 
of the white walker equals his strength. He however thinks that his rangers are weak and need to improve. 
Jon now thinks that if he takes the bitwise XOR of strengths of some of rangers with his favourite number x,
 he might get soldiers of high strength. So, he decided to do the following operation k times:

Arrange all the rangers in a straight line in the order of increasing strengths.
Take the bitwise XOR of the strength of each alternate ranger with x and update it's strength.

Suppose, Jon has 5 rangers with strengths [9, 7, 11, 15, 5] and he performs the operation 1 time with x = 2.
 He first arranges them in the order of their strengths, [5, 7, 9, 11, 15]. Then he does the following:

The strength of first ranger is updated to 5 xor 2, i.e. 7.
The strength of second ranger remains the same, i.e. 7.
The strength of third ranger is updated to 9 xor 2, i.e. 11.
The strength of fourth ranger remains the same, i.e. 11.
The strength of fifth ranger is updated to 15 xor 2, i.e. 13.

The new strengths of the 5 rangers are [7, 7, 11, 11, 13]
Now, Jon wants to know the maximum and minimum strength of the rangers after performing the above operations k times.
 He wants your help for this task. Can you help him?
Input

First line consists of three integers n, k, x (1 ≤ n ≤ 10^5, 0 ≤ k ≤ 10^5, 0 ≤ x ≤ 10^3) — number of rangers Jon has,
 the number of times Jon will carry out the operation and Jon's favourite number respectively.

Second line consists of n integers representing the strengths of the rangers a1, a2, ..., an (0 ≤ ai ≤ 10^3).

Output

Output two integers, the maximum and the minimum strength of the rangers after performing the operation k times.

Sample Input

5 1 2
9 7 11 15 5

Sample Output

13 7


*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int main()
{
    
ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k,x;
    cin>>n>>k>>x;
    ll *a=new ll[n];
    for(ll i=0;i<n;i++)
    cin>>a[i];
    map<ll, ll> m1,m2;
    for(ll j=0;j<1024;j++)
    {
        m1[j]=0;
        m2[j]=0;
    }
    for(ll i=0;i<n;i++)
    {  m1[a[i]]++;
     // cout<<a[i]<<" "<<m1[a[i]]<<endl;
    }
        
    ll min,max;
    bool even=true,flag=true;
    // k=k%2;
//     min=INT_MAX;
//     max=INT_MIN;
//     flag=true;
//     for(ll j=0;j<1024;j++)
//     {
//         if(m1[j]!=0 && flag)
//         {
//                 min=j;
//                 flag=false;
//         }
//         if(m1[j]!=0)
//             max=j;
//             // if(m2[j]!=0)
//                 // cout<<i<<" i "<<j<<" j"<<m2[j]<<" m2[j] "<<endl;
            
//     }  
    if(k%2==0)
        k=2;
    else
        k=1;
    for(ll i=0;i<k;i++)
    {
        even=true;
        for(ll j=0;j<1024;j++)
        {
            if(m1[j]!=0)
            {
            	ll xr=j^x;
                // cout<<j<<" j "<<xr<<" xr "<<endl;
            	if(m1[j]%2==0)
            	{
                
                	m2[j]+=m1[j]/2;
                	m2[xr]+=m1[j]/2;
            	}
            	else
            	{
                	if(even)
                	{
                    	m2[j]+=m1[j]/2;
                    	m2[xr]+=m1[j]/2+1;
                    	even=false;
                        // cout<<m2[j]<<" m2[j] "<<m2[xr]<<" m2[xr] "<<endl;
                        
                	}
                	else
                	{
                    	m2[j]+=m1[j]/2+1;
                    	m2[xr]+=m1[j]/2;
                    	even=true;
                        // cout<<m2[j]<<" m2[j] "<<m2[xr]<<" m2[xr] "<<endl;
                	}
            	}
            }
        }
        min=INT_MAX;
        max=INT_MIN;
        flag=true;
        for(ll j=0;j<1024;j++)
        {
            if(m2[j]!=0 && flag)
            {
                min=j;
                flag=false;
            }
            if(m2[j]!=0)
                max=j;
            // if(m2[j]!=0)
                // cout<<i<<" i "<<j<<" j"<<m2[j]<<" m2[j] "<<endl;
            
                m1[j]=m2[j];
                m2[j]=0;
        }    
        // cout<<endl;
    }
    cout<<max<<" "<<min<<endl;
}
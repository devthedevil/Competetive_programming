/*
In this problem, you have to maintain a dynamic set of numbers which support the two fundamental operations

INSERT(S,x): if x is not in S, insert x into S
DELETE(S,x): if x is in S, delete x from S

and the two type of queries

K-TH(S) : return the k-th smallest element of S
COUNT(S,x): return the number of elements of S smaller than x

Input Format

Line 1: Q (1 ≤ Q ≤ 200000), the number of operations
In the next Q lines, the first token of each line is a character I, D, K or C meaning that the corresponding operation is 
INSERT, DELETE, K-TH or COUNT, respectively, following by a whitespace and an integer which is the parameter for that operation.

If the parameter is a value x, it is guaranteed that ≤ |x| ≤ 10^9. If the parameter is an index k, it is guaranteed that 1 ≤ k ≤ 10^9.`

Output

For each query, print the corresponding result in a single line. In particular, for the queries K-TH, if k is larger than the number 
of elements in S, print the word 'invalid'.

Input Format

8
I -1
I -1
I 2
C 0
K 2
D -1
K 1
K 2

Output Format

1
2
2
invalid


*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void update(ll index,ll value,ll *bit)
{
    for(;index<=200000;index+=index&(-index))
    {
        bit[index]+=value;
    }
}
ll query(ll index,ll *bit)
{
    ll sum=0;
    for(;index>0;index-=(index)&(-index))
    {
        sum+=bit[index];
    }
    return sum;
}
void bs(ll start,ll end,ll k,ll *bit,vector<ll> &array)
{
    // ll mid=(start+end)/2;
    
    // if(query(mid,bit)==k )
    // {
    //     while(query(mid,bit)!=k+1 )
    //         mid++;
    //     cout<<array[mid]<<endl;
        
    // 	return ;
    // }
    // else
    // {
    //     if(query(mid,bit)<k)
    //     {
    //         bs(mid+1,end,k,bit,array);
            
    //     }
    //     else if(query(mid,bit)>k)
    //     {
    //           bs(start,mid-1,k,bit,array);
    //     }
    // }
    
    ll mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(query(mid,bit)==k &&query(mid-1,bit)!=k)
        {
            
            break;
        }
        else if(query(mid,bit)<k )
        {
           start=mid+1;
        }
        else
        {
             end=mid-1;
        }
        
    }
    cout<<array[mid]<<endl;
    
    

}

int main()
{
    ll q;
    cin>>q;
    ll *bit=new ll[200000]();
    char c;
    pair<char, ll> data[q];
    map<ll,ll> arr;
    map<ll,ll> mapping;
    for(ll i=0;i<q;i++)
    {
        cin>>data[i].first>>data[i].second;
        if(data[i].first=='I')
        arr[data[i].second]=data[i].second;
    }
    map<ll,ll>:: iterator it;
    ll i=1;
    vector<ll> array;
    array.push_back(0);
    for(it=arr.begin();it!=arr.end();it++)
    {
        mapping[(*it).second]=i;
        array.push_back((*it).second);
        i++;
    }
    ll size_of_arr=i;
    ll count=0;
    ll max=INT_MIN;
    for(ll i=0;i<q;i++)
    {
        if(data[i].first=='I')
        {
            if(query(mapping[data[i].second],bit)==query(mapping[data[i].second]-1,bit))
            {
                update(mapping[data[i].second],1,bit);count++;
            }
        }
        if(data[i].first=='D')
        {
            if(query(mapping[data[i].second],bit)!=query(mapping[data[i].second]-1,bit))
            {
                update(mapping[data[i].second],-1,bit);count--;
                
            }
            
        }
        if(data[i].first=='K')
        {
            if(data[i].second>count)
            cout<<"invalid"<<endl;
            else
            {
            	bs(1,size_of_arr,data[i].second,bit,array);
            }
        }
        if(data[i].first=='C')
        {
            std::vector<ll>::iterator low;
            low = std::lower_bound(array.begin(), array.end(), data[i].second);
            
            ll index=(low - array.begin());
            index--;
            cout<<query(mapping[array[index]],bit)<<endl;
            
            
        }
        
    
    }
}
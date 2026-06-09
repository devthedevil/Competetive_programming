/*
Given two lists of intervals, find the intersection of these two lists. Each list consists of disjoint intervals sorted on their start time.
Example 1:
Input: arr1=[[1, 3], [5, 6], [7, 9]], arr2=[[2, 3], [5, 7]]
Output: [2, 3], [5, 6], [7, 7]
Explanation: The output list contains the common intervals between the two lists.
Example 2:
Input: arr1=[[1, 3], [5, 7], [9, 12]], arr2=[[5, 10]]
Output: [5, 7], [9, 10]
Explanation: The output list contains the common intervals between the two lists.
*/
#include<bits/stdc++.h>
using namespace std;
struct t
{
    int st;
    int ft;
};
bool com(t t1,t t2)
{
    return t1.st<t2.st;
}
void findIntersection(t l[],int s )
{ 
   
     int a,b; 
    for (int i = 0; i < s-1; i++) { 
  
        // If no intersection exists 
        for(int j=i+1;j<s;j++)
        {
        if (l[i].ft>l[j].st) 
        { 
            //cout<<"a"<<endl;
            a = max(l[i].st, l[j].st); 
            b = min(l[i].ft, l[j].ft); 
            cout <<a<< " " << b<<endl; 
         
        } 
        }
     
    } 
  
   
} 
int main() 
{
    int s1,s2;
    cin>>s1;
    t l1[s1];
    for(int i=0;i<s1;i++)
    {
        cin>>l1[i].st>>l1[i].ft;
    }
    cin>>s2;
    t l2[s2];
    for(int i=0;i<s2;i++)
    {
        cin>>l2[i].st>>l2[i].ft;
    }
    t l[s1+s2];
    for(int i=0;i<s1;i++)
    {l[i].st=l1[i].st;l[i].ft=l1[i].ft;}
    for(int i=s1;i<s1+s2;i++)
    {l[i].st=l2[i-s1].st;l[i].ft=l2[i-s1].ft;}
    sort(l,l+(s1+s2),com);
//       for(int i=0;i<s1+s2;i++)
//       cout<<l[i].st<<" "<<l[i].ft<<endl;   
//     cout<<endl;
    findIntersection(l,s1+s2);
    
}
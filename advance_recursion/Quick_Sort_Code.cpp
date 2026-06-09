/*
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :

Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :

Array elements in increasing order (separated by space)

Constraints :

1 <= n <= 10^3

Sample Input 1 :

6 
2 6 8 5 4 3

Sample Output 1 :

2 3 4 5 6 8

Sample Input 2 :

5
1 5 2 7 3

Sample Output 2 :

1 2 3 5 7 


*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int partition(int *a,int l ,int r)
{
    int index,count=0;
    for(int i=l+1;i<=r;i++)
    {
        if(a[l]>a[i])
        count++;
    }
    swap(a[l],a[l+count]);
    index=l+count;
    int i=l,j=index+1;
    while(i<index && j<=r)
    {
        if(a[i]<a[index])
        i++;
        else if(a[j]>=a[index])
        j++;
        else
        {
            swap(a[i],a[j]);
            i++;j++;
        }
                
    }
    // cout<<index<<endl;
    return index;
}
void q_sort(int *a,int l,int r)
{
    if(l>=r)
    return;
    else
    {
        int c=partition(a,l,r);
        q_sort(a,l,c-1);
        q_sort(a,c+1,r);
    }
    
    


}
void quickSort(int input[], int size) {
    q_sort(input,0,size-1);

}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}



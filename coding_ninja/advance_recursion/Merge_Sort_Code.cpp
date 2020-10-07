/*
Sort an array A using Merge Sort.
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
2 1 5 2 3

Sample Output 2 :

1 2 2 3 5 


*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void merge(int a[],int start,int mid,int end)
{
    int *arr=new int[end-start+1];
    int i,j,k;
    i=start,k=0,j=mid+1;
    for(;i<=mid && j<=end;)
    {
        if(a[i]>a[j])
        {
            arr[k]=a[j];
            j++;
        }
        else
        {
            arr[k]=a[i];
            i++;
        }
        k++;
    }
    
    while(i<=(mid))
    	arr[k++]=a[i++];
    while(j<=end)
        arr[k++]=a[j++];
    
    for(i=start,j=0;j<=(end-start) || i<=end;i++,j++)
        a[i]=arr[j];
        
    	
    
    
}
void mergesort(int a[],int start,int end)
{
    // cout<<start<<" "<<mid<<" "<<end<<endl;
    if(start>=end)
        return;
    else
    {
        int mid=(start+end)/2;
        
        mergesort(a,start,mid);
        mergesort(a,mid+1,end);
        merge(a,start,mid,end);
        
    }
    
}
void mergeSort(int input[], int size){
	mergesort(input,0,size-1);
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
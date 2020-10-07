#include<iostream>
using namespace std;
 	
	int longestBitonicSubarray(int *input, int n) {
		
	/* Don't write main().
     	* the input is already passed as function argument.
     	* Taking input and printing output is handled automatically.
     	*/
    	int inc[n];
        inc[0]=1;
        for (int i=1;i<n;i++)
            inc[i]= (input[i]>input[i-1])?inc[i-1]+1:1;
        int dec[n];
        dec[n-1]=1;
        for (int i=n-2;i>=0;i--)
            dec[i]= (input[i]>input[i+1])?inc[i+1]+1:1;
     	
     	int max=inc[0]+dec[0]-1;
        for (int i=0;i<n;i++)
            if(max<inc[i]+dec[i]+1)
                max=inc[i]+dec[i]+1;
        return max;
     	
 	}
int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubarray(input, n);
  return 0;
}

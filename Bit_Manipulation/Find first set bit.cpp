/*
Find first set bit
Send Feedback
You are given an integer N. You need to return an integer M, in which only one bit is set which at position of lowest set bit of N (from right to left).
Input Format :

Integer N

Output Format :

Integer M

Sample Input 1 :

7

Sample Output 1 :

1

Sample Input 2 :

12

Sample Output 2 :

4


*/
#include <iostream>
#include "Solution.h"
using namespace std;
#include <iostream>
using namespace std;
int clearAllBits(int n, int i){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     
     */
    int m=1<<(i);
    // cout<<m<<endl;
    return n&(m-1);
    
}


int main() {
	int n;

	cin >> n;
	
	cout<< returnFirstSetBit(n) <<endl;
		
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
void multiply(int a[][2],int m[][2])
{
    int fv=a[0][0]*m[0][0]+a[0][1]*m[1][0];
    int sv=a[0][0]*m[0][1]+a[0][1]*m[1][1];
    int tv=a[1][0]*m[0][0]+a[1][1]*m[1][0];
    int lv=a[1][0]*m[0][1]+a[1][1]*m[1][1];

    a[0][0]=fv; //first value
    a[0][1]=sv; //second value
    a[1][0]=tv; //third value
    a[1][1]=lv; //fourth value
}
void power(int a[][2],int n)
{
    if(n==0 || n==1)
    return;

    power(a,n/2);
    //multiplying a^n/2 with a^n/2
    multiply(a,a);
    if(n%2!=0)
    {
        int m[2][2]={{1,1},{1,0}};
        multiply(a,m);
    }

}
int fib(int n)
{
    if(n==0)
    return 0;
    int A[2][2]={{1,1},{1,0}};
    power(A,n-1);
    return A[0][0];

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,k;
    cout<<fib(9)<<endl;

}

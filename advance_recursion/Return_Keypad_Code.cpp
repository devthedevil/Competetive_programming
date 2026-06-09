/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : The order of strings are not important.
Input Format :

Integer n

Output Format :

All possible strings in different lines

Constraints :
1 <= n <= 10^6
Sample Input:

23

Sample Output:

ad
ae
af
bd
be
bf
cd
ce
cf


*/
#include <bits/stdc++.h>
using namespace std;
#include <string>
using namespace std;
#include <string>
using namespace std;

int recur(int num,string *out,string *s)
{
    
    if(num==0)
    {
        out[0]="";
        return 1;
    }
    
    int small_str_len=recur(num/10,out,s);
    // cout<<num<<" num "<<endl;
    // cout<<small_str_len<<" small "<<endl;
    // for(int i=0;i<small_str_len;i++)
    //      cout<<out[i]<<" out "<<endl;
    // cout<<endl;
    int index=num%10;
    for(int i=1;i<s[index].size();i++)
    {
        for(int j=0;j<small_str_len;j++)
        {
            out[j+i*small_str_len]=out[j];
            // cout<<out[j]<<" out "<<endl;
            // cout<<i<<" i "<<j<<" j "<<endl;
        }
    }
    for(int j=0;j<s[index].size();j++)
    {
        for(int i=0;i<small_str_len;i++)
        {
            out[j*small_str_len+i]=out[j*small_str_len+i]+s[index][j];
            // cout<<out[i*small_str_len+j]<<" out "<<endl;
            // cout<<i<<" i "<<j<<" j "<<endl;
        }
    }
    return (s[index].size()*small_str_len);
}

int keypad(int num, string output[]){
    string *s=new string[10];
    s[0]="";
    s[1]="";
    s[2]="abc";
    s[3]="def";
    s[4]="ghi";
    s[5]="jkl";
    s[6]="mno";
    s[7]="pqrs";
    s[8]="tuv";
    s[9]="wxyz";
    return recur(num,output,s);
}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

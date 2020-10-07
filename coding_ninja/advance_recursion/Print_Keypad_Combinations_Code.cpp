/*
Print Keypad Combinations Code
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
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
#include <iostream>
#include <string>
using namespace std;
#include <iostream>
#include <string>
using namespace std;
void print_sub(int n,string* s,string out)
{
    if(n==0)
    {
        cout<<out<<endl;
        return;
    }
    for(int i=0;i<s[n%10].size();i++)
    {
    	print_sub(n/10,s,s[n%10][i]+out);
    }

}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
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
    string out="";
    print_sub(num,s,out);
}
int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}

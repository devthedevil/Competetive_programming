#include <bits/stdc++.h>
using namespace std;
// s.substr(starting_index,length_of_substring);
int main()
{
    string *st=new string;
    *st="dev";
    // cout<<st<<endl;
    // cout<<*st<<endl;
    string s;
    // cin>>s;
    getline(cin,s);
    // s="dec";
    // s+=" singh";
    cout<<s<<endl;
    // cout<<s.length()<<endl;
    // cout<<s.size()<<endl;
    // cout<<s.substr(3)<<endl;
    cout<<s.substr(3,3)<<endl;
    cout<<s.find("mar")<<endl;

}
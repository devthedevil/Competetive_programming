#include <bits/stdc++.h>
using namespace std;
void print_sub(string in,string out)
{
    if(in.empty())
    {
        cout<<out<<endl;
        return;
    }
    print_sub(in.substr(1),out);
    print_sub(in.substr(1),out+in[0]);

}
int main()
{
    string in;
    cin>>in;
    string out="";
    print_sub(in,out);
}
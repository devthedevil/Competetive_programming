#include <bits/stdc++.h>
using namespace std;
int sub(string s,string* out)
{
    if(s.empty())
    {
        out[0]="";
        return 1;
    }
    int small_str_len=sub(s.substr(1),out);
    for(int i=0;i<small_str_len;i++)
    {
        out[small_str_len+i]=s[0]+out[i];
    }
    return 2*small_str_len;
}
int main()
{
   string s;
   cin>>s;
   int m=pow(2,s.size());
   string *out=new string[m];
   int n=sub(s,out);
   for(int i=0;i<n;i++)
   {
       cout<<out[i]<<endl;
   }


}
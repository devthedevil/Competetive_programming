#include<bits/stdc++.h>
using namespace std;

bool isver(char **cross,int row,int col,int index,string* s)
{
    if(row+s[index].size()>10){
    return false;
}
    for(int i=row,j=0;i<row+s[index].length();i++,j++)
    {
        if(cross[i][col]!='-' && cross[i][col]!=s[index][j])
        return false;
    }
    return true;
}
bool ishor(char **cross,int row,int col,int index,string* s)
{
    if(col+s[index].size()>10){
    return false;
}
    for(int i=col,j=0;i<col+s[index].length();i++,j++)
    {
        if(cross[row][i]!='-' && cross[row][i]!=s[index][j])
        return false;
    }
    return true;
}
void setver(char **cross,string *s,int row,int col,int index,bool *arr)
{
    for(int i=row,j=0;i<row+s[index].length();i++,j++)
    {
        if(cross[i][col]==s[index][j])
        arr[j]=false;
        else
        {
            cross[i][col]=s[index][j];
            arr[j]=true;
        }
        
    }
}

void resetver(char **cross,string *s,int row,int col,int index,bool *arr)
{
    for(int i=row,j=0;i<row+s[index].length();i++,j++)
    {
        if(arr[j]==true)
        cross[i][col]='-';
    }
}
void sethor(char **cross,string *s,int row,int col,int index,bool *arr)
{
    for(int i=col,j=0;i<col+s[index].length();i++,j++)
    {
        if(cross[row][i]==s[index][j])
        arr[j]=false;
        else
        {
            cross[row][i]=s[index][j];
            arr[j]=true;
        }
        
    }
}
void resethor(char **cross,string *s,int row,int col,int index,bool *arr)
{
    for(int i=col,j=0;i<col+s[index].length();i++,j++)
    {
        if(arr[j]==true)
        cross[row][i]='-';
        
        
    }
}
void print(char **cross)
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        cout<<cross[i][j];
        cout<<endl;
    }
}
void crossword(char **cross,string *s,int n,int index)
{
    //int row,col;
    if(index==n)
    {
        print(cross);
        return;
    }
    for(int row=0;row<10;row++)
    {
        for(int col=0;col<10;col++)
        {
        if(cross[row][col]=='-' || cross[row][col]==s[index][0]){
        if(ishor(cross,row,col,index,s)){
        bool arr_hor[s[index].length()];
        sethor(cross,s,row,col,index,arr_hor);
        crossword(cross,s,n,index+1);
        
        resethor(cross,s,row,col,index,arr_hor);

    }
    	if(isver(cross,row,col,index,s))
    {
        bool arr_ver[s[index].length()];
        setver(cross,s,row,col,index,arr_ver);
        crossword(cross,s,n,index+1);
        
        resetver(cross,s,row,col,index,arr_ver);

    }
   
            }
        }
    }
    

}
int main() 
{

	char **cross=new char*[10];
    for(int i=0;i<10;i++)
    {
        cross[i]=new char[10];
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            cin>>cross[i][j];
            
    }
    string str;
    cin>>str;
    int n=0;
    for(int i=0;i<str.length();i++)
    if(str[i]==';')
    n++;
    n++;
    // cout<<n<<endl;
    string s[n];
    
    vector<int> size;
    int count=0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==';')
        {
            size.push_back(count);
            count=0;
        }
        else
        {
            count++;
        }
    }
    size.push_back(count);
    string in="";
    in.resize(size[0]);
    int ind=0;
    for(int i=0,j=0;i<str.length();i++)
    {
        if(str[i]==';')
        {
            //  cout<<in<<endl;
            s[ind]=in;
            j=0;
            ind++;
           
            in="";
            // cout<<size[ind]<<endl;
            in.resize(size[ind]);

        }
        else
        {
            in[j]=str[i];
            
            // cout<<in[j]<<" j "<<endl;
            // cout<<in<<endl;
            j++;
        }
    }
    s[ind]=in;
    // for(int i=0;i<size.size();i++){
    //     cout<<s[i]<<endl;
    // }
    // for(int i=0;i<n;i++)
    // cout<<s[i].length()<<endl;
	  crossword(cross,s,n,0);
     

    

}
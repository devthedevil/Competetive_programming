/*
CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you 
are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.

+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV

Output for the given input should be:

+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA

Note: We have provided such test cases that there is only one solution for the given input.
Input format:

The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 

Output format:

Print the crossword grid, after placing the words of word list in '-' cells.  

Sample Test Cases:
Sample Input 1:

+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV

Sample Output 1:

+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA


*/
#include<bits/stdc++.h>
using namespace std;
// bool findpos(char **cross,int &row,int &col,int index,string *s)
// {
//     for(int i=0;i<10;i++)
//     {
//         for(int j=0;j<10;j++)
//         {
//             if(cross[i][j]=='-' || cross[i][j]==s[index][0])
//             {
//                 row=i;
//                 col=j;
//                 cout<<i<<" i "<<j<<" j "<<endl;
//                 return true;
//             }
//         }
//     }
//     return false;

// }
bool isver(char **cross,int row,int col,int index,string* s)
{
    if(row+s[index].length()>10)
    return false;
    for(int i=row,j=0;i<row+s[index].length();i++,j++)
    {
        if(cross[i][col]!='-' && cross[i][col]!=s[index][j])
        return false;
    }
    return true;
}
bool ishor(char **cross,int row,int col,int index,string* s)
{
    if(col+s[index].length()>10)
    return false;
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
bool crossword(char **cross,string *s,int n,int i)
{
    int row,col;
    // cout<<index<<" index "<<endl;
    if(i==n)
    {
        print(cross);
        return true;
    }
	for(row=0;row<10;row++)
    {
        for(col=0;col<10;col++)
    	{
            if(cross[row][col]=='-' || cross[row][col]==s[i][0])
            {
                if(ishor(cross,row,col,i,s))
                {
                    // cout<<" ishor "<<endl;
                    bool arr_hor[s[i].length()];
                    sethor(cross,s,row,col,i,arr_hor);
                    if(crossword(cross,s,n,i+1))
                    return true;
                    resethor(cross,s,row,col,i,arr_hor);

                }
                if(isver(cross,row,col,i,s))
                {
                    // cout<<" isver "<<endl;
                    bool arr_ver[s[i].length()];
                    setver(cross,s,row,col,i,arr_ver);
                    if(crossword(cross,s,n,i+1))
                    return true;
                    resetver(cross,s,row,col,i,arr_ver);

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
    // for(int i=0;i<n;i++)
    // cout<<s[i].length()<<endl;
    crossword(cross,s,n,0);
     

    

}
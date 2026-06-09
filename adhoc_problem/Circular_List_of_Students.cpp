/*
Circular List of Students
Send Feedback
You are given a circular list of students as follows:
0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11
This list is circular, means that 11 will follow 0 again. You will be given the student number ‘i’ and some position ‘p’. You will have to tell that if the list will start from (i+1)th student, then which student will be at pth position.
Input Format:

First line will have an integer ‘t’, denoting the number of test cases.
Next line will have two space separated integers denoting the value of ‘i’ and ‘p’ respectively.

Output Format:

Print ‘t’ lines containing single integer denoting the student number.

Constraints:

1 <= t <= 10^5
0 <= i <= 11
1 <= p <= 12

Sample Input:

2
2 3
5 8

Sample Output:

5
1

Explanation:

First, list will start at 3. 3 -> 4 -> 5. Hence, 5 will be at third position.
Second, list will start at 6. 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> 0 -> 1. Hence, 1 will be at 8th position.





*/#include<bits/stdc++.h>
using namespace std;
typedef long long int ll; 
class stud{
    public:
    stud *next;
    ll num;

    
};
stud *addtoempty(stud* last,ll num)
{
    if(last!=NULL)
    return last;

    stud *temp=new stud;
    temp->num=num;
    temp->next=temp;
    last=temp;

    return last;

}
stud *addtolast(stud* last,ll num)
{
    if(last==NULL)
    return addtoempty(last,num);

    stud *temp=new stud;
    temp->num=num;
    temp->next=last->next;
    last->next=temp;
    last=temp;

    return last;


}
int main()
{
    stud *last=new stud;
    stud *start=new stud;
    last=NULL;
    for(int i=0;i<12;i++)
    {
        last=addtolast(last,i);
    }
    start=last->next;
    ll t;
    cin>>t;
    ll stu,pos;
    while(t--)
    {
        cin>>stu>>pos;
        while(start->num!=stu)
        start=start->next;
        while(pos--)
        start=start->next;
        cout<<start->num<<endl;
        start=last->next;

    }
    
	return 0;
}

/*
Given a singly linked list, you have to rearrange the linked list by performing following operations:
1. You have to divide the given linked list into two halves.
2. Reverse the second half.
3. The first node of rearranged linked list will be the first node of the first half, second node will be the first node of the second half, third node will be second node of first half, fourth node will be second node of the second half and so on.
For example, if the given linked list is 1 -> 2 -> 3 -> 4 -> 5 -> null, then the rearranged linked list will be 1 -> 5 -> 2 -> 4 -> 3 -> null.
*/
//'head'is the head of your linked list
// Following is the node structure
/**************
class Node{
public:
    int data;
    Node * next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/
int length(Node* head)
{
    int len=0;
    while(head)
    {
        head=head->next;
        len++;
    }
    return len;
}
Node* rev(Node* head)
{
    Node* pre=NULL;
    Node* nxt;
    Node* curr=head;
    while(curr)
    {
        nxt=curr->next;
        curr->next=pre;
        pre=curr;
        curr=nxt;
        
    }
    return pre;
}
Node* rearrangeLinkedList(Node* head){
  
    Node* mid=head;
    Node* finalhead;
    Node* finaltail=NULL;
    int len=length(head);
    //cout<<len<<endl;
    if(len<3) return head;
    int i=1;
    while(i<(len)/2)
    {
        mid=mid->next;
        i++;
    }
   // cout<<mid->data<<endl;
    Node* firsthalfhead=head;
    Node* secondhalfhead=rev(mid->next);
    Node* firsthalftail=mid;
    Node* secondhalftail=NULL;
    int count=0;
    while(firsthalfhead && secondhalfhead)
    {
        if(count%2==0)
        {
            if(firsthalfhead==head)
     		{
         			finalhead=firsthalfhead;
                	finaltail=firsthalfhead;
                	//cout<<finaltail->data<<"c=0,fh=fhead"<<endl;
     		}
        	else
        	{
            	finaltail->next=firsthalfhead;
                finaltail=finaltail->next;
              //  cout<<finaltail->data<<"c=0,fh!=fhead"<<endl;
                
        	}
            firsthalfhead=firsthalfhead->next;
        }
        else
        {
            if(secondhalfhead==head)
     		{
         			finalhead=secondhalfhead;
                	finaltail=secondhalfhead;
              //  cout<<finaltail->data<<"c=1,fh=shead"<<endl;
     		}
        	else
        	{
            	finaltail->next=secondhalfhead;
                finaltail=finaltail->next;
              //  cout<<finaltail->data<<"c=1,fh!=shead"<<endl;
                
        	}
            secondhalfhead=secondhalfhead->next;
          
        }
          count++;
        
     
    }
    
    
    
    
    return finalhead;
}
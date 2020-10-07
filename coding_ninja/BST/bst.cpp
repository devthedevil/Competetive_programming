#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct node
{
    ll data;
    struct node *left;
    struct node *right;
};
struct node  *newnode(ll n)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=n;
    temp->left=temp->right=NULL;
    return temp;
}
struct node* insert(struct node* nod,ll n)
{
    //cout<<"a"<<endl;
    if(nod==NULL) return newnode(n);
    if(n > nod->data)
    nod->right= insert(nod->right,n);
    else if(n<=nod->data)
    nod->left=  insert(nod->left,n);

}
void preorder(struct node* nod)
{
    //cout<<"a"<<endl;
    if(nod!=NULL)
    {
        cout<<nod->data<<endl;
        preorder(nod->left);
        preorder(nod->right);
    }
    
}
int main()
{
    ll n,val;
    cin>>n;
    cin>>val;
    struct node* root=NULL;
    root=insert(root,val);
    for(ll i=0;i<n-1;i++)
    { 
        cin>>val;
        insert(root,val);
    }
    preorder(root);
}
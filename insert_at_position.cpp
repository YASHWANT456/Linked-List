# include<bits/stdc++.h>
using namespace std;

class Node
{
    public :
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};


void insertathead(Node* &head,int val)
{
    Node* n = new Node(val);
    n->next = head;
    head = n;

}
void insertattail(Node* &head,int val)
{
    Node* n = new Node(val);
    if(head == NULL)
    {
        insertathead(head,val);
        return ;
    }
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;

    }
    temp->next = n;

}
void display(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}
int lengthoflist(Node* head)
{
    Node* temp = head;
    int len = 0;
    while( temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertatposition(Node* &head,int pos,int val)
{
    Node* n = new Node(val);
    if( pos == 1)
    {
        insertathead(head,val);
        return ;
    }
    int length = lengthoflist(head);
    if( pos == length+1)
    {
        insertattail(head,val);
        return ;
    }
    int t = pos - 2;
    Node* temp = head;
    while(t--)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;

}

int main()
{
    Node* head = NULL;
    insertatposition(head,1,1);
    insertatposition(head,2,2);
    insertatposition(head,3,3);
    insertatposition(head,4,4);
    insertatposition(head,5,5);
    cout<<"List : ";
    display(head);
    return 0;

}

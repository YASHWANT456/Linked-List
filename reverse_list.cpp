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
    if( head == NULL)
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
Node* reverselist(Node* head)
{
    if( head->next == NULL || head == NULL)
    {
        return head;
    }
   
    Node* prevptr = NULL;
    Node* curptr = head;
    Node* nxtptr;
    while( curptr != NULL)
    {
        nxtptr = curptr->next;
        curptr->next = prevptr;
        prevptr = curptr;
        curptr = nxtptr;
    }
    return prevptr;
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
int main()
{
    Node* head = NULL;
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    cout<<"original list : ";
    display(head);
    cout<<endl;
    Node* newhead = reverselist(head);
    cout<<"reversed list : ";
    display(newhead);
    return 0;
}

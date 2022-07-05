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
Node* reverselist(Node* &head)
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
bool  palindrome(Node* head)
{
    
    Node* slow = head;
    Node* fast = head;
    if( head == NULL || head->next == NULL)
    {
        return true;
    }
    while( fast->next!= NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverselist(slow->next);
    slow = slow->next;
    while( slow != NULL)
    {
        if( head->data != slow->data)
        {
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return true;

}
int main()
{
    Node* head = NULL;
    insertattail(head,1);
    insertattail(head,1);
    insertattail(head,1);
    insertattail(head,1);
    insertattail(head,1);
    insertattail(head,1);
    if(palindrome(head))
    {
        cout<<"List is palindrome";


    }
    else
    {
        cout<<"List is not palindrome";
    }
    return 0;
}
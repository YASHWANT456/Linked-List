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
bool is_circular(Node* head)
{
    if( head == NULL)
    {
        return true;
    }
    Node* temp = head;
    while( temp != NULL && temp->next != head)
    {
        temp = temp->next;
    }
    if( temp == head)
    {
        return true;
    }
    else
    {
        return false;
    }

}
int main()
{
    Node* head = NULL;
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,5);
    insertattail(head,7);
    if(is_circular(head))
    {
        cout<<"List is circular";
    }
    else
    {
        cout<<"List is not circular";
    }
    return 0;

}
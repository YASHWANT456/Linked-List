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
Node* reverse_k(Node* head,int k)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* curptr = head;
    Node* prevptr = NULL;
    Node* nxtptr;
    int count = 0;
    while( curptr != NULL && count < k)
    {
        nxtptr = curptr->next;
        curptr->next = prevptr;
        prevptr = curptr;
        curptr = nxtptr;
        count++;
    }
    if( nxtptr != NULL)
    {
        head->next = reverse_k(nxtptr,k);
    }
    return prevptr;
}


int main()
{
    Node* head = NULL;
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    insertattail(head,6);
    cout<<"original list : ";
    display(head);
    cout<<endl;
    Node* newhead = reverse_k(head,2);
    cout<<"reversed list : ";
    display(newhead);

    return 0;

}

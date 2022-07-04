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
void middle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while( fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<"Middle of list : "<<slow->data;
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
    cout<<"List : ";
    display(head);
    cout<<endl;
    middle(head);
    return 0;

}

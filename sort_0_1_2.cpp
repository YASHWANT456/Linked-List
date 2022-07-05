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
void insertattail1(Node* &tail,Node* curr)
{
    tail->next = curr;
    tail = curr;

}
Node* sort_list(Node* head)
{
    Node* zerohead = new Node(-1);
    Node* zerotail = zerohead;
    Node* onehead = new Node(-1);
    Node* onetail = onehead;
    Node* twohead = new Node(-1);
    Node* twotail = twohead;
    Node* curr = head;
    while( curr != NULL)
    {
        if( curr->data == 0)
        {
            insertattail1(zerotail,curr);
        }
        else if(curr->data == 1)
        {
            insertattail1(onetail,curr);
        }
        else if( curr->data == 2)
        {
            insertattail1(twotail,curr);
        }
        curr = curr->next;
    }
    if(onehead->next != NULL)
    {
        zerotail->next = onehead->next;
    }
    else
    {
        zerotail->next = twohead->next;
    }
    onetail->next = twohead->next;
    twotail->next = NULL;
    head = zerohead->next;
    delete zerohead;
    delete onehead;
    delete twohead;
    return head;
    


}
int main()
{
    Node* head = NULL;
    insertattail(head,1);
    insertattail(head,0);
    insertattail(head,2);
    insertattail(head,0);
    insertattail(head,1);
    cout<<"original list : ";
    display(head);
    cout<<endl;
    Node* newhead = sort_list(head);
    cout<<"sorted list : ";
    display(newhead);
    return 0;
}
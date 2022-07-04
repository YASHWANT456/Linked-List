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
bool search(Node* head,int key)
{
    bool flag = false;
    if( head == NULL)
    {
        return false ;
    }
    Node* temp = head;
    while( temp != NULL)
    {
        if( temp->data == key)
        {
            flag = true;
        }
        temp = temp->next;
    }
    if( flag == true)
    {
        return true;
    }
    else
    {
        return false;
    }

}
void deletehead(Node* &head)
{
    Node* todelete = head;
    head = head->next;
    delete todelete;
}
void deletenode(Node* &head,int pos)
{
    if( head == NULL)
    {
        return ;
    }
    if( pos == 0)
    {
        deletehead(head);
        return ;
    }
    int count = 0;
    Node* temp = head;
    while( count != pos-1)
    {
        temp = temp->next;
        count++;
    }
    Node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;

}
int main()
{
    Node* head = NULL;
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    display(head);
    cout<<endl;
    if(search(head,4))
    {
        cout<<"Node is present"<<endl;
    }
    else
    {
        cout<<"Node is not present"<<endl;

    }
    deletenode(head,4);
    display(head);
    return 0;

}

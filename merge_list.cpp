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
Node* merge(Node* head1,Node* head2)
{
    Node* p1 = head1;
    Node* p2 = head2;
    Node* dummy = new Node(-1);
    Node* p3 = dummy;
    while( p1 != NULL && p2 != NULL)
    {
        if( p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while(p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while( p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummy->next;
}

int main()
{
    Node* head1 = NULL;
    insertattail(head1,1);
    insertattail(head1,2);
    insertattail(head1,3);
    insertattail(head1,4);
    Node* head2 = NULL;
    insertattail(head2,5);
    insertattail(head2,6);
    insertattail(head2,7);
    cout<<"First list : ";
    display(head1);
    cout<<endl;
    cout<<"second list : ";
    display(head2);
    cout<<endl;
    cout<<"Merged list : ";
    Node* newhead = merge(head1,head2);
    display(newhead);

    return 0;
    


}
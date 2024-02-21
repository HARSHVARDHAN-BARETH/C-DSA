#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val)
{
   
    
    node* n = new node(val);
     if(head == NULL)
    {
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}



void insertAtHead(node* &head, int val)
{
    node* n = new node(val);
    n->next=head;
    head=n;
    
}

void display(node* head)
{
    node* temp =head;
    while(temp!=NULL)
    {
        cout << temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
bool Serach(node* head, int Key)
{
    node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data==Key)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void deleteAtHead(node* &head)
{
    node* todelete=head;
    head=head->next;
    
    delete todelete;
}

void deletion(node* &head, int val)
{
    if(head==NULL)
    {
        return;
    }
    if(head->next==NULL)
    {
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    while(temp->next->data!=val)
    {
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    
    delete todelete;
}
void deletAtEnd(node* &head)
{
    node* temp = head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
   
}

int main()
{
    node* head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    display(head);
    deletion(head, 2);
    deleteAtHead(head);
    display(head);
    return 0;
}

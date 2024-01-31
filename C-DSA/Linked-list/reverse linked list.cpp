
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

node* reverse(node* &head)
{
    node* prevPtr = NULL;
    node* currPtr = head;
    node* nextPtr;
    
    while(currPtr!=NULL)
    {
        nextPtr=currPtr->next;
        currPtr->next=prevPtr;
        
        prevPtr=currPtr;
        currPtr=nextPtr;
    }
    
    return prevPtr;
    
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
int main()
{
    node* head = NULL;
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    
    display(head);
    // cout<<Serach(head,3)<<endl;
    node* newHead = reverse(head);
    display(newHead);
    
    return 0;
}
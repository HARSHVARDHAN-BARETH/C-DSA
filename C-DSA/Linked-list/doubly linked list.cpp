#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;
    
    node(int val)
    {
        this->data =val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(node* head)
{
    node* temp = head;
    
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertAtHead(node* &head, int val)
{
    node* temp = new node(val);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

int getLength(node* head)
{
    int len = 0;
    node* temp = head;
    while(temp!=NULL)
    {
        len++;
        temp = temp->next;
    }cout << endl;
    return len;
}

void insertAtTail(node* &tail, int val)
{
    node* temp = new node(val);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

int main()
{
    node* node1 = new node(10);
    node* head = node1;
    print(head);
    cout << getLength(head) << endl;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    print(head);
    insertAtTail(head, 11);
        print(head);
    insertAtTail(head, 12);
        print(head);
    insertAtTail(head, 13);
    print(head);
    
    return 0;
}
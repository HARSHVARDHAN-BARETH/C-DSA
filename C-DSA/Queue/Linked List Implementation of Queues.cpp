#include <iostream>
#include <bits/stdc++.h>
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

class Queue
{
    public:
    node* front;
    node* back;
    
    Queue()
    {
        front = NULL;
        back = NULL;
    }
    
    void push(int x)
    {
        node* n = new node(x);
        if(front == NULL)
        {
            back = n;
            front = n;
            return;
        }
        
        back->next = n;
        back = n;
    }
    
    void pop()
    {
        if(front == NULL)
        {
            cout << "queue is underflow " << endl;
            return;
        }
        
        node* todelete = front;
        front = front->next;
        delete todelete;
    }
    
    int peek()
    {
        if(front == NULL)
        {
            cout << "No element in queue" << endl;
            return -1;
        }
        return front->data;
    }
    
    bool empty()
    {
        if(front == NULL)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    node* head  = NULL;
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    
    while(!q.empty())
    {
        cout << q.peek() << " ";
        q.pop();
    }
    
    return 0;
}

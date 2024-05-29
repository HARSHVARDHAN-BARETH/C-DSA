

Node* sortList(Node *head){
    // Write your code here.

    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    
    Node* temp = head;

    while(temp!=NULL)
    {
        if(temp->data == 0)
        {
            zeroCount++;
        }else if(temp->data == 1)
        {
            oneCount++;
        }
        else if (temp->data == 2)
      {
          twoCount++;
      }
      temp=temp->next;
    }
   
   temp = head;

    while(temp!=NULL)
    {
        if(zeroCount)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if (oneCount)
        {
            temp->data = 1;
            oneCount--;
        }
        else if (twoCount)
        {
            temp->data = 2;
            twoCount--;
        }
        temp=temp->next;
    }
    return head;
}
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        // if(head == NULL)
        // {
        //     return;
        // }
        
        ListNode* curr = head;
        
        while(curr!=NULL)
        {
            
            if((curr->next!=NULL) && curr->val == curr->next->val)
            {
                ListNode* next = curr -> next -> next;
                ListNode* todelete = curr->next;
                delete(todelete);
                curr -> next = next;
            }
            else 
            {
                curr = curr->next;
            }
        }
        return head;
        
    }
};
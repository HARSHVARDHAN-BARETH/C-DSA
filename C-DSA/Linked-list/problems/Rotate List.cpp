/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
                //last element -> head // 7->1
        
        if(head==NULL || k==0)return head;
        ListNode* temp = head;
        int n = 0;
        while(temp->next)
        {
            temp = temp->next;
            n++; // 6
        }
         //temp = 7
        temp->next = head; // 7->1
        
        //n = 6
        k = k%(n+1); 
        int jump = n-k; // 6-2 = 4
        temp = head;
        while(jump)
        {
            temp = temp->next;
            jump--;
        }
        //temp -> 5
        ListNode* returnhead = temp->next; // 6
        temp->next = NULL;
       return returnhead;


    }
};
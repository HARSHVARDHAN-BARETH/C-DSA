class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode *fh=NULL, *ft=NULL;
        if(head1 == NULL) {
            return head2;
        }
        if(head2 == NULL) {
            return head1;
        }
    while(head1!=NULL && head2!=NULL){
        
        if(fh== NULL && ft==NULL){
            if(head1->val>head2->val){
                fh=head2;
                ft=head2;
                head2=head2->next;
            }else{
                fh=head1;
                ft=head1;
                head1=head1->next;
            }
        }else{
            
        if(head1->val < head2->val){
            ft->next=head1;
            ft=ft->next;
            head1=head1->next;
            
        }else {
            ft->next=head2;
            ft=ft->next;
            head2=head2->next;
        }   
        }
        
    }
    
    if(head1!=NULL){
        ft->next=head1;
    }
    if(head2!=NULL){
        ft->next=head2;
    }
    
    return fh;
    }
};
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
    ListNode* deleteDuplicates(ListNode* head) {
     
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* curr=head;
        ListNode* prev=dummy;
        
        while(curr!=NULL)
        {
            bool dupli=false;
            while(curr->next !=NULL && curr->val==curr->next->val)
            {
                curr=curr->next;
                dupli=true;
            }
            
            if(dupli)
            {
                prev->next=curr->next;
               
            }
            else
            {
        prev = prev->next; 
               
            }
             curr=curr->next;
        }
       return dummy->next;
    }
};
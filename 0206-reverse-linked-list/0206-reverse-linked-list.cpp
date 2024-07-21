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
    ListNode* reverseList(ListNode* head) {
        
      ListNode* prev=NULL,*curr=head; 
        ListNode*temp=head;
        while(curr!=NULL)
        {
             temp=curr;
            curr=curr->next;
            temp->next=prev;
            prev=temp;
           
        }
        return prev;
    }
};
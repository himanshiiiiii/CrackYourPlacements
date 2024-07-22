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
    ListNode* addTwoNumbers(ListNode* p1 , ListNode* p2 ) {
    ListNode* l1  = reverseList(p1);
    ListNode* l2  = reverseList(p2);
        ListNode* ans=new ListNode(0);
         ListNode* curr=ans;
         int carry=0; 
        while(l1!=NULL && l2!=NULL)
        {
            int sum=((l1->val)+(l2->val)+carry);
              carry =sum/10;
            int val=sum%10;
            ans->next=new ListNode(val);
            ans=ans->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL )
        {
            int sum=((l1->val)+carry);
               carry =sum/10;
            int val=sum%10;
            ans->next=new ListNode(val);
             ans=ans->next;
            l1=l1->next;
        
        }
        while( l2!=NULL)
        {
            int sum=((l2->val)+carry);
               carry =sum/10;
            int val=sum%10;
            ans->next=new ListNode(val);
             ans=ans->next;
            l2=l2->next;
        }
       if(carry)
        {
            ans->next=new ListNode(carry); 
        }
  ListNode* a=reverseList(curr->next);
        return a;
    }
};
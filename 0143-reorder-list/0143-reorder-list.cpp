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
    void reorderList(ListNode* head) {
        ListNode* curr=head;
        stack<ListNode*>st;
        int n=0;
        while(curr!=NULL)
        {
            st.push(curr);
            curr=curr->next;
            n++;
        }
 
       for(int i=0;i<n/2;i++)
       {
            ListNode* val=st.top();
           ListNode* temp=head->next;
           head->next=val;
           val->next=temp;
           head=temp;
           st.pop();
       }
        head->next=NULL;
    }
};
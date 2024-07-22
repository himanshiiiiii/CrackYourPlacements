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
     
        if(head==NULL)
return NULL;
        ListNode* ans=new  ListNode(0);
        ListNode* curr=head;
        map<int,int>m;
        while(curr!=NULL)
        {
            m[curr->val]++;
            curr=curr->next;
        }
        curr=ans;
        for(auto it:m)
        {
            if(it.second==1)
            {
            ans->next=new ListNode(it.first);
            ans=ans->next;
        }}
        return curr->next;
    }
};
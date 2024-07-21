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
    ListNode* sortList(ListNode* head) {
         if(head==NULL)return NULL;
        // Add code here
        map<int,int>m;
        ListNode* ans=new ListNode(0);
        ListNode*temp=ans;
        while(head!=NULL)
        {
            m[head->val]++;
            head=head->next;
        }
        for(auto it:m)
        {
            int c=it.second;
            for(int i=1;i<=c;i++)
            {
                ans->next=new ListNode(it.first);
                ans=ans->next;
            }
        }
        return temp->next;
    }
};
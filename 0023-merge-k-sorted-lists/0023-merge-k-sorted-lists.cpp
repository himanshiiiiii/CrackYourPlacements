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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>data;
        int n=lists.size();
        if(n==0)return NULL;
        for(int i=0;i<n;i++)
        {
            while(lists[i]!=NULL)
            {
                data.push_back(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        sort(data.begin(),data.end());
         ListNode* ans=new  ListNode(0);
         ListNode* curr=ans;
       for(int i=0;i<data.size();i++)
       {
           ans->next=new ListNode(data[i]);
           ans=ans->next;
       }
        
        return curr->next;
    }
};
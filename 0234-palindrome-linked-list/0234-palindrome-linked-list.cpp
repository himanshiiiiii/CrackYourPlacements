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
    bool isPalindrome(ListNode* head) {
       ListNode* curr=head;
         vector<int>v;
        int n=0;
        while(curr!=NULL)
        {
         v.push_back(curr->val);
            curr=curr->next;
            n++;
        }
        for(int i=0;i<v.size()/2;i++)
        {
            if(v[i]!=v[n-i-1])
                return false;
        }
        return true;
    }
};
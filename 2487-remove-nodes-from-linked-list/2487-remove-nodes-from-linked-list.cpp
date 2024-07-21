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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode* temp=head;
        
        while(temp!=NULL)
        {
            st.push(temp);
            temp=temp->next;
        }
        //iske right p kooii bada nii hoga
        ListNode* ans=new ListNode(st.top()->val);
        int maxi=st.top()->val;
        st.pop();
        
        while(!st.empty())
        {
            ListNode* curr=st.top();
            st.pop();
                
            if(maxi<=curr->val)
            {
                maxi=curr->val;
                ListNode* newnode=new ListNode(curr->val);
                newnode->next=ans;
                ans=newnode;
            }
        }
        return ans;
    }
};
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
     ListNode* reverse(ListNode* temp) {
        
      ListNode* prev=NULL,*curr=temp; 
        ListNode*t=temp;
        while(curr!=NULL)
        {
             t=curr;
            curr=curr->next;
            t->next=prev;
            prev=t;
           
        }
        return prev;
    }
    
    ListNode* getKthNode(ListNode*temp, int k)
    {
        k=k-1;
        
        while(temp!=NULL &&k>0)
        {
            k--;
            temp=temp->next;
        }
        
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp=head;
        ListNode* prev=NULL;
        
        while(temp!=NULL)
        {
         ListNode*  kthNode=getKthNode(temp,k);
            //agr ab koii kth node nii bacaha h
            if(kthNode==NULL)
            {
                //agr smaller cycle h to kch nii krna h
                if(prev) prev->next=temp;
                break;
            }
            
            ListNode*  nextNode=kthNode->next;
            kthNode->next=NULL;
            reverse(temp);
            //mtlb phla reversal h
            if(head==temp)
            {
                head=kthNode;
            }
            else
            {
                //jod rhe h prev k baad
                prev->next=kthNode;
            }
            
            
            prev=temp;
            temp=nextNode;
        }
        
        return head;
    }
};
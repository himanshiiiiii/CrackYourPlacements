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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;

        ListNode* curr = head;
        int c = 0;
        while (curr != NULL) {
            c++;
            curr = curr->next;
        }

        int delidxprev = c - n - 1;

        if (delidxprev < 0) return head->next;

        curr = head;
        while (delidxprev--) {
            curr = curr->next;
        }

        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        
        return head;
    }
};

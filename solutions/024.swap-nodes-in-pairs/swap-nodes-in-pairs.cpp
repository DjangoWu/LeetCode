/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *cur = head;
        while(cur&&cur->next)
        {
            prev->next = cur->next;
            cur->next = cur->next->next;
            prev->next->next = cur;
            
            prev = cur;
            cur = cur->next;
        }
        
        return dummy->next;
    }
};
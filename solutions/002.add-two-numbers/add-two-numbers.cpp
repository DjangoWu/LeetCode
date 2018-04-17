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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* res = &head;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry == 1)
        {
            res->next = new ListNode(0);
            res = res->next;
            int tempVal = carry;
            if(l1 != nullptr)
            {
                tempVal += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                tempVal += l2->val;
                l2 = l2->next;
            }
            res->val = tempVal % 10;
            carry = tempVal / 10;
        }
        return head.next;
        
    }
};
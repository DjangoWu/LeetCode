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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* head = ans;
        while (l1 != NULL && l2 != NULL) {
            ListNode* tmp = new ListNode(0);
            if (l1->val < l2->val){
                tmp->val = l1->val;
                l1 = l1->next;
            }
            else{
                tmp->val = l2->val;
                l2 = l2->next;
            }
            //std::cout << tmp->val << std::endl;
            tmp->next = NULL;
            ans->next = tmp;
            ans = ans->next;
        }
        if (l1 != NULL)
            ans->next = l1;
        if (l2 != NULL)
            ans->next = l2;
        return head->next;
        
    }
};
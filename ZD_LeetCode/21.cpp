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
        if (l1 == 0) return l2;
        if (l2 == 0) return l1;
        ListNode* p = new ListNode(-1);
        ListNode* q = p;
        while (l1 != 0 && l2 != 0) {
            if (l1->val > l2->val) {
                q->next = l2;
                l2 = l2->next;
            } else {
                q->next = l1;
                l1 = l1->next;
            }
            q = q->next;
        }
        q->next = l1 == 0 ? l2 : l1;
        return p->next;
    }
};

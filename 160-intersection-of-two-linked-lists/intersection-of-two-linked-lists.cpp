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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *nA=headA, *nB=headB;

        while(nA!=nB) {
            if(!nA) {
                nA=headB;
            }else {
                nA=nA->next;
            }

            if(!nB) {
                nB=headA;
            }else {
                nB=nB->next;
            }
        }

        return nA;
    }
};
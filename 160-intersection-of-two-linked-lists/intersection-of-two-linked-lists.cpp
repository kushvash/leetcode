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
        ListNode *l1=headA, *l2=headB;

        while(l1!=l2){
            if(l1==nullptr){
                l1=headB;
            }else{
                l1=l1->next;
            }

            if(l2==nullptr){
                l2=headA;
            }else{
                l2=l2->next;
            }
        }

        return l1;
    }
};
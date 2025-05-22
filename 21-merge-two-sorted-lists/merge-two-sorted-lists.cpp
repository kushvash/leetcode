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
    ListNode* mergeTwoListsHelper(ListNode* l1, ListNode* l2) {
        // base cases
        if (!l1) {
            return l2;
        } 
        if (!l2) {
            return l1;
        } 
        
        // choose the smaller head, recurse on the rest
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {        
        return mergeTwoListsHelper(list1, list2);
    }
};
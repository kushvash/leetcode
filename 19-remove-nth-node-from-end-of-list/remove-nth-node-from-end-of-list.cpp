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
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast ahead by n+1 steps to maintain the gap
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        // Move both until fast reaches the end
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the target node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; // only if you're not using a GC environment

        return dummy.next;
    }
};
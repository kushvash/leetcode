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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* prev = nullptr;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
            }
            if (l2) {
                sum += l2->val;
            }

            if (l1) {
                l1->val = sum % 10;
            } else {
                prev->next = new ListNode(sum % 10);
                l1 = prev->next;
            }

            carry = sum / 10;

            prev = l1;
            
            if (l1) {
                l1 = l1->next;
            } else {
                l1 = nullptr;
            }

            if (l2) {
                l2 = l2->next;
            } else {
                l2 = nullptr;
            }
        }

        return head;
    }
};
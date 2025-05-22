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
    void deleteDuplicatesHelper(ListNode* curr,ListNode* prevN) {
        if (!curr) return;

        if (curr->val == prevN->val) {
            prevN->next = curr->next;
            delete curr;
            deleteDuplicatesHelper(prevN->next, prevN);
            
        } else {
            deleteDuplicatesHelper(curr->next, prevN->next);
        }

        return;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode *curr=head->next, *prevN=head;

        deleteDuplicatesHelper(curr, prevN);

        return head;
    }
};
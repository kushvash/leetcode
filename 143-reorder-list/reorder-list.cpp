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
    void reorderList(ListNode* head) {
        ListNode *slow=head, *fast=head, *l1=head, *l2=head->next, *r1, *r2;

        while(fast!=nullptr && fast->next!=nullptr) {
            slow=slow->next;
            fast=fast->next->next;
        }

        r1=reverseList(slow);
        r2=r1->next;

        while(r2) {
            l1->next=r1;
            r1->next=l2;

            l1=l2;
            r1=r2;

            l2=l2->next;
            r2=r2->next;
        }

        return;

    }

private:
    ListNode *reverseList(ListNode* mid) {
        ListNode *prevP=nullptr, *temp, *curr=mid;

        while(curr) {
            temp=curr->next;
            curr->next=prevP;
            prevP=curr;
            curr=temp;
        }

        return prevP;
    }
};
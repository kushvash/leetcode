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
    ListNode* reverseList(ListNode* mid) {
        ListNode *prevN=nullptr;

        while(mid!=nullptr){
            ListNode *temp=mid->next;
            mid->next=prevN;
            prevN=mid;
            mid=temp;
        }

        return prevN;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next){
            return;
        }
        
        ListNode *slow=head, *fast=head, *first=head;

        while(fast!=nullptr && fast->next!=nullptr) {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *second = reverseList(slow->next);
        slow->next=nullptr;

        while(second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};
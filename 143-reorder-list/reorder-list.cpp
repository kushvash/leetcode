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
        // Finding the mid
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next && fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }

        // Reversing the second half of LinkedList
        ListNode* secondHalf=slow->next;
        slow->next=nullptr;
        ListNode* prev=nullptr;

        while(secondHalf) {
            ListNode* nextNode=secondHalf->next;
            secondHalf->next=prev;
            prev=secondHalf;
            secondHalf=nextNode;
        }

        ListNode* leftLi=head; 
        ListNode* rightLi=prev;
    
        while(rightLi && leftLi!=rightLi) {
            ListNode* leftNext=leftLi->next;
            ListNode* rightNext=rightLi->next;

            leftLi->next=rightLi;
            rightLi->next=leftNext;

            leftLi=leftNext;
            rightLi=rightNext;
        }
    
        return;
    }
};
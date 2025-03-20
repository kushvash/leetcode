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
    ListNode *detectCycle(ListNode *head){
        ListNode *slow=head, *fast=head;


        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                return findStart(head, slow);
            }
        }

        return nullptr;
    }

    ListNode *findStart(ListNode *head, ListNode *meet){
        while(head!=meet){
            head=head->next;
            meet=meet->next;
        }

        return head;
    }
};
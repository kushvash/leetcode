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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head;

        while(fast!=nullptr && fast->next!=nullptr) {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *head2=reverseList(slow);

        while(head!=slow){
            if(head->val!=head2->val){
                return false;
            }
            head=head->next;
            head2=head2->next;
        }

        return true;


    }

    ListNode *reverseList(ListNode* mid) {
        ListNode *prev=nullptr, *curr=mid;

        while(curr!=nullptr) {
            ListNode *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }


        return prev;
    }
};
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head(0);
        ListNode *tempHead=&head;
        while(list1 && list2) {
            if(list1->val>list2->val) {
                tempHead->next=list2;
                list2=list2->next;
            }else {
                tempHead->next=list1;
                list1=list1->next;
            }
            tempHead=tempHead->next;
        }

        if(list1) {
            tempHead->next=list1;
        }else if(list2) {
            tempHead->next=list2;
        }

        return head.next;
    }
};
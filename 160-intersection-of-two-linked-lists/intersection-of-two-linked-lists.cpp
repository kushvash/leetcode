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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0, l2=0;
        ListNode *temp=headA;

        while(temp!=nullptr){
            l1++;
            temp=temp->next;
        }

        temp=headB;
        
        while(temp!=nullptr){
            l2++;
            temp=temp->next;
        }

        if(l1>l2){
            while(l1!=l2){
                headA=headA->next;
                l1--;
            }
        }else{
            while(l1!=l2){
                headB=headB->next;
                l2--;
            }
        }


        while(headA!=nullptr && headB!=nullptr){
            if(headA==headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }


        return nullptr;
    }
};
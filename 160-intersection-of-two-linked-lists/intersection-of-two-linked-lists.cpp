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
        unordered_set<ListNode*> helper;

        // while(headA!=nullptr && headB!=nullptr){
        //     if(helper.find(headA)!=helper.end()){
        //         return headA;
        //     }
        //     helper.insert(headA);

        //     if(helper.find(headB)!=helper.end()){
        //         return headB;
        //     }
        //     helper.insert(headB);
        // }

        while(headA!=nullptr){
            helper.insert(headA);
            headA=headA->next;
        }


        while(headB!=nullptr){
            if(helper.find(headB)!=helper.end()){
                return headB;
            }
            // helper.insert(headB);
            headB=headB->next;
        }

        return nullptr;
    }
};
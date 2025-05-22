/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copyMap;
        
        Node *curr=head;
        while(curr){
            Node* temp=new Node(curr->val);
            copyMap[curr]=temp;
            curr=curr->next;
        }

        curr=head;

        while(curr){
            copyMap[curr]->next=copyMap[curr->next];

            copyMap[curr]->random=copyMap[curr->random];

            curr=curr->next;
        }


        return copyMap[head];


    }

};
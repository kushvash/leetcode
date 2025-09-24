/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        if (!p || !q) {
            return nullptr;
        }
        Node* a = p;
        Node* b = q;
        while (a != b) {
            if(a) {
                a=a->parent;
            }else {
                a=q;
            }
            if(b) {
                b=b->parent;
            }else {
                b=p;
            }
        }
        return a;
    }
};
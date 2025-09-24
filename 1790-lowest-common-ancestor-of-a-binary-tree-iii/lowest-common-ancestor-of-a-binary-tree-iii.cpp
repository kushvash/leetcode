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
        unordered_set<Node*> s;
        
        // Node* temp=p;

        while(p->parent) {
            s.insert(p);
            p=p->parent;
        }

        while(q->parent) {
            if(s.find(q)!=s.end()) {
                return q;
            }
            q=q->parent;
        }

        return p;
    }
};
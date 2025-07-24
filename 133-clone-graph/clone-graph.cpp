/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) { 
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraphHelper(Node* root, unordered_map<Node*, Node*>& record){
        if(!root){
            return nullptr;    
        }

        if(record.find(root)!=record.end()){
            return record[root];
        }

        record[root] = new Node(root->val);

        for(Node* ne: root->neighbors){
            record[root]->neighbors.push_back(cloneGraphHelper(ne, record));
        }

        return record[root];
    }

    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }   

        unordered_map<Node*, Node*> record;
        
        return cloneGraphHelper(node, record);
    }
};
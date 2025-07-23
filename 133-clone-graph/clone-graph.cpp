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
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }   

        queue<Node*> q;
        unordered_map<Node*, Node*> record;

        q.push(node);

        record[node]=new Node(node->val);

        while(!q.empty()){
            Node* curr=q.front();
            q.pop();

            for(Node* ne: curr->neighbors){
                if(record.find(ne)==record.end()){
                    record[ne] = new Node(ne->val);
                    q.push(ne); 
                }

                record[curr]->neighbors.push_back(record[ne]);
            }
        }

        return record[node];
    }
};
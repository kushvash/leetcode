/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int length(Node* node, int& res) {
        if(!node) {
            return 0;
        }

        int longest=0, secondLongest=0;

        for(Node* tempNode: node->children) {
            int tempLength=length(tempNode, res);
            if(tempLength>=longest) {
                secondLongest=longest;
                longest=tempLength;
            }else if(tempLength>secondLongest) {
                secondLongest=tempLength;
            }
        }

        res=max(res, longest+secondLongest);

        return longest+1;
    }
    int diameter(Node* root) {
        int res=0;

        length(root, res);

        return res;
    }
};
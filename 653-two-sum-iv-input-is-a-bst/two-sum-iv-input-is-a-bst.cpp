/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findTargetHelper(TreeNode* node, int& k, unordered_set<int>& record, bool& found){
        if(!node || found){
            return;
        }

        if(record.find(k-node->val)!=record.end()){
            found=true;
            return;
        }

        record.insert(node->val);

        findTargetHelper(node->left, k, record, found);
        findTargetHelper(node->right, k, record, found);
    }
    bool findTarget(TreeNode* root, int k) {
        bool found=false;
        unordered_set<int> record;

        findTargetHelper(root, k, record, found);

        return found;
    }
};
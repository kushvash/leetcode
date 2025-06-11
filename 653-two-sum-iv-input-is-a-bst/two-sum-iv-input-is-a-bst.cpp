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
    bool findTargetHelper(TreeNode* node, int k, unordered_set<int>& record){
        if(!node){
            return false;
        }

        if(record.find(k-node->val)!=record.end()){
            return true;
        }

        record.insert(node->val);

        return findTargetHelper(node->left, k, record) || findTargetHelper(node->right, k, record);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> record;

        return findTargetHelper(root, k, record);

    }
};
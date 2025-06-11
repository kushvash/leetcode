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
    bool isValidBSTHelper(TreeNode* node, long minV, long maxV) {
        if(!node) {
            return true;
        }

        if(node->val>=maxV || node->val<=minV) {
            return false;
        }

        return isValidBSTHelper(node->left, minV , node->val) && isValidBSTHelper(node->right, node->val, maxV);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);    
    }
};
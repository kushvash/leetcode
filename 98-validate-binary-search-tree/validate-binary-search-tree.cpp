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
    bool _helper(TreeNode* node, long max, long min) {
        if(!node) {
            return true;
        }

        int curr=node->val;

        if(curr>=max || curr<=min) {
            return false;
        }

        return _helper(node->left, curr, min) && _helper(node->right, max, curr);
    }

    bool isValidBST(TreeNode* root) {
        int curr=root->val;
        
        return _helper(root->left, curr, LONG_MIN) && _helper(root->right, LONG_MAX, curr);
    }
};
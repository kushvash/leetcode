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
    bool _isValidBSTHelper(TreeNode* node, long currMin, long currMax) {
        if(!node) {
            return true;
        }

        if(node->val>=currMax || node->val<=currMin) {
            return false;
        }

        bool leftB=_isValidBSTHelper(node->left, currMin, node->val);
        bool rightB=_isValidBSTHelper(node->right, node->val, currMax);

        return leftB && rightB;
    }

    bool isValidBST(TreeNode* root) {
        int curr=root->val;

        return _isValidBSTHelper(root->left, LONG_MIN, curr) && _isValidBSTHelper(root->right, curr, LONG_MAX);
    }
};
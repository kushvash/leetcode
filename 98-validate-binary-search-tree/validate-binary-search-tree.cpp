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
    bool isValidBSTHelper(TreeNode* root, long maxEle, long minEle) {
        if(!root) {
            return true;
        }

        if(root->val>=maxEle || root->val<=minEle) {
            return false;
        }

        return isValidBSTHelper(root->left, root->val, minEle) && isValidBSTHelper(root->right, maxEle, root->val);
    }
    bool isValidBST(TreeNode* root) {
        return (isValidBSTHelper(root->left, root->val, LONG_MIN) && isValidBSTHelper(root->right, LONG_MAX, root->val));
    }
};
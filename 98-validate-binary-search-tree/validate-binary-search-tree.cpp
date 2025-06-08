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
    bool isValidBSTHelper(TreeNode* node, long currMax, long currMin){
        if(!node){
            return true;
        }

        if(node->val>=currMax){
            return false;
        }
        if(node->val<=currMin){
            return false;
        }

        return (isValidBSTHelper(node->left, node->val, currMin) && isValidBSTHelper(node->right, currMax, node->val));
    }

    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LONG_MAX, LONG_MIN);
    }
};
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
    int isBalancedHelper(TreeNode* node) {
        if(!node) {
            return 0;
        }

        int left=isBalancedHelper(node->left);
        int right=isBalancedHelper(node->right);

        if(left==-1 || right==-1) {
            return -1;
        }
        if(left-right==1 || left-right==-1 || left-right==0) {
            return 1+max(left, right);
        }
        return -1;
    }

    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root)!=-1;
    }
};
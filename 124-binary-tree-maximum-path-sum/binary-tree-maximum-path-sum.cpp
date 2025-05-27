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
    int maxPathSumHelper(TreeNode* root, int& maxSum) {
        if(!root){
            return 0;
        }

        int leftSum=max(maxPathSumHelper(root->left, maxSum),0);
        int rightSum=max(maxPathSumHelper(root->right, maxSum),0);

        maxSum=max(maxSum, leftSum+rightSum+root->val);

        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
       int maxSum=INT_MIN;

       maxPathSumHelper(root, maxSum);

       return maxSum;
    }
};
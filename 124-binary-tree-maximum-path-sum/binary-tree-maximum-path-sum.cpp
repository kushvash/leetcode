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
    int maxPathSumHelper(TreeNode* node, int& maxSum) {
        if(!node) {
            return 0;
        }

        int left=maxPathSumHelper(node->left, maxSum);
        int right=maxPathSumHelper(node->right, maxSum);
        int temp=node->val;
        
        if(left>0) {
            temp+=left;
        }
        if(right>0) {
            temp+=right;
        }

        maxSum=max(maxSum, temp);

        return max(0, max(node->val, node->val+max(left, right)));
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=root->val;

        int temp=maxPathSumHelper(root, maxSum);
    
        return maxSum;
    }
};
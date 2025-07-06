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
    int maxPathSumHelper(TreeNode* root, int& maxP){
        if(!root){
            return 0;
        }

        int leftPath=maxPathSumHelper(root->left, maxP);

        int rightPath=maxPathSumHelper(root->right, maxP);

        if(leftPath<0){
            leftPath=0;
        }
        if(rightPath<0){
            rightPath=0;
        }

        maxP=max(maxP, leftPath+rightPath+root->val);

        return root->val + max(leftPath, rightPath);
    }

    int maxPathSum(TreeNode* root){
        int maxP=root->val;
    
        int temp=maxPathSumHelper(root, maxP);
    
        return maxP;
    }
};
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
    int diameterOfBinaryTreeHelper(TreeNode* root, int& maxL) {
        if(!root){
            return 0;
        }

        int left=diameterOfBinaryTreeHelper(root->left, maxL);
        int right=diameterOfBinaryTreeHelper(root->right, maxL);

        maxL=max(maxL, left+right);
        
        return 1 + max(left, right);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxL=0;

        diameterOfBinaryTreeHelper(root, maxL); 
        
        return maxL;
    }
};
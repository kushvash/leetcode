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

        int leftMax=diameterOfBinaryTreeHelper(root->left, maxL);
        int rightMax=diameterOfBinaryTreeHelper(root->right, maxL);

        maxL=max(maxL, leftMax+rightMax);

        return 1 + max(leftMax, rightMax);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxL=0;

        diameterOfBinaryTreeHelper(root, maxL);       

        return maxL; 
    }
};
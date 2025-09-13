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
    int diameterOfBinaryTreeHelper(TreeNode* root, int& maxD) {
        if(!root) {
            return 0;
        }

        int temp=0;

        int temp1=diameterOfBinaryTreeHelper(root->left, maxD);
        int temp2=diameterOfBinaryTreeHelper(root->right, maxD);
        maxD=max(maxD, temp+temp1+temp2);

        return 1+max(temp1, temp2);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD=0;

        int temp = diameterOfBinaryTreeHelper(root, maxD);
    
        return maxD;
    }
};
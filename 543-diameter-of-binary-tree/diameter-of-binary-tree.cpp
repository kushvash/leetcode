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
    int diameterOfBinaryTreeHelper(TreeNode* node, int& maxD) {
        if(!node){
            return 0;
        }
        int l=diameterOfBinaryTreeHelper(node->left, maxD), r=diameterOfBinaryTreeHelper(node->right, maxD);
        maxD=max(maxD, l+r);

        return 1+max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxD=0;
        diameterOfBinaryTreeHelper(root, maxD);

        return maxD;
    }
};
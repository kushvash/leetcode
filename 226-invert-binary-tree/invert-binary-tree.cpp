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
    void invertTreeHelper(TreeNode* node){
        if(!node){
            return;
        }

        TreeNode* temp=node->left;
        node->left=node->right;
        node->right=temp;

        invertTreeHelper(node->left);
        invertTreeHelper(node->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        invertTreeHelper(root);

        return root;
    }
};
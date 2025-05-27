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
    int isBalancedHelper(TreeNode* root) {
        if(!root){
            return 0;
        } 

        int leftH=isBalancedHelper(root->left);
        int rightH=isBalancedHelper(root->right);
        int diff=leftH-rightH;
        if(diff<0){
            diff*=-1;
        }

        if(leftH==-1 || rightH==-1 || diff>1){
            return -1;
        }

        return 1 + max(leftH, rightH);
    }

    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root)!=-1;
    }
};
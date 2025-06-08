/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return nullptr; 
        }
        if(root==p || root==q){
            return root;
        } 

        TreeNode* tempL=lowestCommonAncestor(root->left, p, q);
        TreeNode* tempR=lowestCommonAncestor(root->right, p, q);

        if(tempL && tempR){
            return root;
        }
        if(tempL){
            return tempL;
        }
        if(tempR){
            return tempR;
        }

        return nullptr;
    }
};
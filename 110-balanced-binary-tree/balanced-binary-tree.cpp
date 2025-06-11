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
    int isBalancedHelper(TreeNode* node) {
        if(!node){
            return 0;
        }

        int l=isBalancedHelper(node->left);
        if(l<0){
            return -1;
        }

        int r=isBalancedHelper(node->right);
        if(r<0){
            return -1;
        }

        if(l-r>1 || l-r<-1){
            return -1;
        }

        return 1+ max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root)>=0;
    }
};